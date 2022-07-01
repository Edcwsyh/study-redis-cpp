/*
    > File Name: BaseCommandExec.cpp
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年06月30日 星期四 15时51分26秒
*/

#include "BaseCommandExec.hpp"
#include "base/Singleton.hpp"
#include "string/StringTools.hpp"
#include <utility>
#include <iostream>

namespace Edc {

std::vector<std::string> BaseCommandExec::parsing_command( const std::string& oInput ) {
    return Singleton<StringTools>::instance().split( oInput, " " );
}


int BaseCommandExec::register_cmd( std::string_view sCommand, std::string_view sDoc, 
    CommandEntry::func_t&& func ) 
{
    auto oInsertRes = 
        m_CommandMap.insert( std::make_pair( sCommand, CommandEntry( sDoc, std::move( func ) ) ) );
    if ( !oInsertRes.second ) {
        std::cerr << "Command conflict : " << sCommand << std::endl;
        return -1;
    }
    return 0;
}

}
