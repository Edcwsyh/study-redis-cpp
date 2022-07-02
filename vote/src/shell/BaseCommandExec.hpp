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
            CommandEntry( std::string_view sDoc, func_t&& func ) : m_sDoc( sDoc ), m_oFunc( std::move( func ) ) {  };
            
            const std::string& get_doc() const noexcept { return m_sDoc; }
            func_t& get_func() { return m_oFunc; }
    };
    
//Constant
public:
protected:
    
//Member Variables
protected:
    std::unordered_map<std::string, CommandEntry> m_CommandMap;
    
//Static Member Variables
protected:
    
//Member Function
protected: 
    std::vector<std::string> parsing_command( const std::string& oInput );
    CommandEntry* get_command_entry( const std::string& command ) {
        if ( auto pTarget = m_CommandMap.find( command ); pTarget != m_CommandMap.end() ) {
            return &pTarget->second;
        }
        return nullptr;
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

    // 注册一条命令
    int register_cmd( std::string_view sCommand, std::string_view sDoc, CommandEntry::func_t&& func );

//Static Member Function
public:
    
};

}

#endif
