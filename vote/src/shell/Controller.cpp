/*
    > File Name: Controller.cpp
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年06月30日 星期四 15时03分10秒
*/

#include "Controller.hpp"
#include <iostream>
#include <string>

namespace Edc {

// 显示终端页面
void Controller::show_input() {
    std::cout << "# Vote|> ";
}

void Controller::run() {
    if ( m_enmState != ENM_STATE_READY ) {
        std::cerr << "The system no ready" << std::endl;
        return;
    }
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
    std::getline( std::cin, buffer );
    return buffer;
}

}
