/*
    > File Name: Controller.cpp
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年06月30日 星期四 15时03分10秒
*/

#include "Controller.hpp"
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <termios.h>

namespace Edc {

// 显示终端页面
void Controller::show_input() {
    print_stdout( SHOW_INPUT );
}

void Controller::run() {
    if ( m_enmState != ENM_STATE_READY ) {
        std::cerr << "The system no ready" << std::endl;
        return;
    }
    set_no_buffer_input();
    std::cin.tie(nullptr);
    std::cout.sync_with_stdio(false);
    m_enmState = ENM_STATE_RUNNING;
    while ( m_enmState == ENM_STATE_RUNNING ) {
        show_input();
        auto commands = input_command();
        m_pCommandExec->exec( commands );
    }
    std::cout << "Bye!" << std::endl;
}

void Controller::register_command_exec( BaseCommandExec* pCommandExec ) {
    m_pCommandExec = pCommandExec;
    m_enmState = ENM_STATE_READY;
}

std::string Controller::input_command() {
    std::string buffer;
    char c = 0, prec = 0;
    while ( ( c = read_char_from_stdin() ) != '\n' ) {
        switch ( c ) {
            case '\t' : 
                command_complete( buffer );
                break;
            case 127 :
                if ( buffer.size() ) {
                    buffer.pop_back();
                    print_stdout( "\b \b" );
                }
                print_stdout( "\b \b" );
                print_stdout( "\b \b" );
                break;
            // case '\033' : 
            //     print_stdout( "\b \b" );
            //     try_handle_direction_key();
            //     break;
            default : 
                buffer.push_back( c );
                break;
        }
        prec = c;
    }
    return buffer;
}

void Controller::command_complete(std::string& input) {
    auto oVec = m_pCommandExec->match_command( input );
    switch ( oVec.size() ) {
        case 0 : 
            handle_complete_0( input );
            break;
        case 1 :
            input = oVec.front();
            print_stdout( "\n" );
            show_input();
            print_stdout( input );
            break;
        default : 
            handle_complete_n( input, oVec );
            break;
    }
}

// 补全处理(可选命令为0)
void Controller::handle_complete_0(const std::string& prefix) {
    print_stdout( "\nNot command prefix : " );
    print_stdout( prefix, true );
    show_input();
    print_stdout( prefix );
}

void Controller::handle_complete_n(const std::string& prefix, std::vector<std::string>& oVec) {
    uint32_t uNum = 0;
    for ( auto& str : oVec ) {
        if ( uNum % COMPLETE_OUT_PUT_LINE_NUM == 0 ) {
            print_stdout( "\n" );
        }
        print_stdout( str );
        print_stdout( "  " );
    }
    print_stdout( "\n" );
    show_input();
    print_stdout( prefix );
}

// 设置无缓冲输入
// modify from https://stackoverflow.com/questions/4327942/non-buffering-stdin-reading
void Controller::set_no_buffer_input() {
    termios term, term_orig;
    int iRet = 0;
    if ( ( iRet = tcgetattr( STDIN_FILENO, &term_orig ) ) ) {
        std::cerr << "tcgetattr failed, retcode : " << iRet << std::endl;
        exit(-1);
    }
    term = term_orig;

    term.c_lflag &= ~ICANON;
    term.c_lflag |= ECHO;
    term.c_cc[VMIN] = 0;
    term.c_cc[VTIME] = 0;

    if ( ( iRet = tcsetattr(STDIN_FILENO, TCSANOW, &term) ) ) {
        std::cerr << "tcgetattr failed, retcode : " << iRet << std::endl;
        exit(-1);
    }

}

// 从stdint读取一个字符
char Controller::read_char_from_stdin() {
    char c = 0;
    while ( true ) {
        if ( read(STDIN_FILENO, &c, 1) ) {
            return c;
        }
    }
    return c;
}

// 从stdint读取一个字符, 不管有没有效, 直接返回
char Controller::read_char_from_stdin_once() {
    char c = 0;
    read( STDIN_FILENO, &c, 1 );
    return c;
}

// 输出到标准输出
void Controller::print_stdout(std::string_view str, bool bNewLine ) {
    write( STDOUT_FILENO, str.data(), str.size() );
    if ( bNewLine ) {
        char c = '\n';
        write( STDOUT_FILENO, &c, 1 );
    }
}

// 尝试处理方向键
void Controller::try_handle_direction_key() {
    char c = read_char_from_stdin_once();
    if ( c != -1 ) {
        print_stdout( "\b \b" );
    }
    if ( c != '[' ) {
        return;
    }
    c = read_char_from_stdin_once();
    switch ( c ) {
        case 'A' : break;
        case 'B' : break;
        case 'D' : 
            print_stdout( "\b \b" );
            print_stdout( "\b \b" );
            print_stdout( "\033[1D" );
            break;
        case 'C' :
            print_stdout( "\b \b" );
            print_stdout( "\b \b" );
            print_stdout( "\033[1C" );
            break;
        default : 
            break;
    }
}

}
