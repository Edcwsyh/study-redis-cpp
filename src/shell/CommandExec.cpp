/*
    > File Name: CommandExec.cpp
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年06月30日 星期四 16时17分12秒
*/

#include <sstream>
#include <string>
#include <iostream>
#include <string_view>
#include <vector>
#include "CommandExec.hpp"
#include "Controller.hpp"
#include "ArticleCommand.h"

namespace Edc {

void CommandExec::exec( const std::string& oInput ) {
    auto commands = parsing_command( oInput );
    if ( oInput.size() == 0 ) {
        std::cerr << "The commands is empty!" << std::endl;
        return;
    }
    if ( auto pTaget = m_CommandMap.find( commands.front() ); pTaget != m_CommandMap.end() ) {
        pTaget->second.get_func()( commands );
    } else {
        std::cerr << "Unknow command, you can use 'help'command view help document" << std::endl;
    }
}

const std::vector<std::string_view> CommandExec::get_all_command() {
    std::vector<std::string_view> oRes;
    for ( auto& [ command, _ ] : m_CommandMap ) {
        oRes.push_back( command );
    }
    return oRes;
}

void CommandExec::register_all_commands() {
    // 退出系统
    register_cmd( "exit", "Exit this system", CommandExec::command_exit );
    register_cmd( "quit", "Exit this system", CommandExec::command_exit );
    // 帮助文档
    register_cmd( "help", "Display help document,  you can use 'allcmd' view all command\n Usage : help [command]", CommandExec::command_help );
    // 查看所有命令
    register_cmd( "allcmd", "Usage : allcmd\n\tDisplay all commands", CommandExec::command_allcmd );
    // 创建文章
    register_cmd( "newarticle", "Usage : newarticle [autor] [title]\n\tCreate a new empty article", command_create_article );
    // 查询所有文章
    register_cmd( "allarticle", "Usage : allarticle\n\tGet a list of all articles (sorted by vote)", command_all_article );
    // 投票
    register_cmd( "vote", "Usage : vote [username] [article id]\n\tVote on an article", command_vote );
    // 热榜
    register_cmd( "top", "Usage : top [number(default = 10)]\n\tDisplays the top [number] articles with the highest votes", command_top );
}


void CommandExec::command_exit( const std::vector<std::string>& commands ) {
    if ( commands.size() != 1 ) {
        std::cerr << "Usage : help " << commands.front() << std::endl;
        return;
    }
    Controller::instance().set_state( Controller::ENM_STATE_CLOSE );
}

void CommandExec::command_help( const std::vector<std::string>& commands ) {
    CommandEntry* pCommandEntry = nullptr;
    if ( commands.size() == 2 ) {
        pCommandEntry = CommandExec::instance().get_command_entry( commands.back() );
    } else {
        pCommandEntry = CommandExec::instance().get_command_entry( commands.front() );
    }
    if ( pCommandEntry == nullptr ) {
        std::cerr << "Help command exception !" << std::endl;
        return;
    }
    std::cout << pCommandEntry->get_doc() << std::endl;
}

void CommandExec::command_allcmd( const std::vector<std::string>& commands ) {
    if ( commands.size() != 1 ) {
        std::cerr << "Usage : help " << commands.front() << std::endl;
        return;
    }
    auto oCommandList = CommandExec::instance().get_all_command();
    std::stringstream ss;
    ss << "Command list : \n";
    for ( auto& command : oCommandList ) {
        ss << '\t' << command << '\n';
    }
    std::cout << ss.str() << std::endl;
}

}
