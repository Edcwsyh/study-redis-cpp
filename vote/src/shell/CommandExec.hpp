/*
    > File Name: CommandExec.hpp
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年06月30日 星期四 15时56分02秒
*/

#ifndef __COMMANDEXEC_EDC__
#define __COMMANDEXEC_EDC__

#include <base/Singleton.hpp>
#include <string_view>
#include <unordered_map>
#include <string>
#include <vector>
#include "BaseCommandExec.hpp"

namespace Edc {

class CommandExec : public BaseCommandExec, public Singleton<CommandExec> {
//Type
public:
    typedef BaseCommandExec::CommandEntry::func_t func_t;

private : 
    
//Constant
public:
protected:
    
//Member Variables
protected:
    
//Static Member Variables
protected:
    
//Member Function
public:
    CommandExec();
    explicit CommandExec( const CommandExec& ) = delete;
    explicit CommandExec( CommandExec&& ) = delete;
    ~CommandExec() = default;
    CommandExec& operator=( const CommandExec& ) = delete;
    CommandExec& operator=( CommandExec&& ) = delete;
    
    virtual void exec( const std::string& oInput ) override;

    virtual void register_all_commands() override;

    const std::vector<std::string> get_all_command();

//Static Member Function
public:
    static void command_exit( const std::vector<std::string>& commands );
    static void command_help( const std::vector<std::string>& commands );
    static void command_allcmd( const std::vector<std::string>& commands );
    
};

}

#endif
