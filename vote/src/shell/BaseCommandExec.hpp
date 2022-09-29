/*
    > File Name: BaseCommandExec.hpp
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年06月30日 星期四 15时13分00秒
*/

#ifndef __BASECOMMANDEXEC_EDC__
#define __BASECOMMANDEXEC_EDC__

#include <string>
#include <string_view>
#include <vector>
#include <functional>
#include "tree/PrefixTree.hpp"

namespace Edc {

class BaseCommandExec {
//Type
public:

protected:
    class CommandEntry {
        public : 
            typedef std::function<void(std::vector<std::string>&)> func_t;
        private : 
            std::string m_sDoc;
            func_t m_oFunc;
        public : 
            CommandEntry() = default;
            CommandEntry( const CommandEntry& ) = default;
            CommandEntry( std::string_view sDoc, func_t&& func ) : m_sDoc( sDoc ), m_oFunc( std::move( func ) ) {  };
            
            const std::string& get_doc() const noexcept { return m_sDoc; }
            func_t& get_func() { return m_oFunc; }
    };
    
//Constant
public:
protected:
    
//Member Variables
protected:
    typedef PrefixTree<char, CommandEntry, 64, 'z'> CommandMap;
    CommandMap m_CommandMap;
    
//Static Member Variables
protected:
    
//Member Function
protected: 
    std::vector<std::string> parsing_command( const std::string& oInput );
    CommandEntry* get_command_entry( const std::string& command ) {
        CommandMap::Node* pNode = m_CommandMap.find( command );
        if ( !pNode ) {
            return nullptr;
        }
        return &pNode->get_val();
    }
public:
    BaseCommandExec() = default;
    explicit BaseCommandExec( const BaseCommandExec& ) = default;
    explicit BaseCommandExec( BaseCommandExec&& ) = default;
    virtual ~BaseCommandExec() = default;
    BaseCommandExec& operator=( const BaseCommandExec& ) = default;
    BaseCommandExec& operator=( BaseCommandExec&& ) = default;

    // 执行命令
    virtual void exec( const std::string& oInput ) = 0;
    // 注册所有命令
    virtual void register_all_commands() = 0;
    // 命令补全
    virtual const std::vector<std::string> match_command(const std::string& prefix) noexcept {
        return m_CommandMap.match_all( prefix );
    }

    // 注册一条命令
    int register_cmd( const std::string& sCommand, std::string_view sDoc, CommandEntry::func_t&& func );

//Static Member Function
public:
    
};

}

#endif
