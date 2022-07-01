/*
    > File Name: Controller.hpp
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年06月30日 星期四 15时00分21秒
*/

#ifndef __CONTROLLER_EDC__
#define __CONTROLLER_EDC__

#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>
#include <memory>
#include "base/Singleton.hpp"
#include "BaseCommandExec.hpp"

namespace Edc {

class Controller : public Singleton<Controller>{
//Type
public:
    enum State {
        ENM_STATE_UNKNOW = 0, //未知状态
        ENM_STATE_READY,    // 就绪
        ENM_STATE_RUNNING, // 运行中
        ENM_STATE_CLOSE, // 关闭
    };

//Constant
public:
protected:
    
//Member Variables
protected:
    State m_enmState;
    BaseCommandExec* m_pCommandExec;
    
//Static Member Variables
protected:
    
//Member Function
private:
    Controller() = default;
    friend Singleton;
    // 显示终端页面
    void show_input();

    std::string input_command();
public:
    explicit Controller( const Controller& ) = delete;
    explicit Controller( Controller&& ) = delete;
    ~Controller() = default;
    Controller& operator=( const Controller& ) = delete;
    Controller& operator=( Controller&& ) = delete;

    void register_command_exec( BaseCommandExec* pCommandExec );

    // 运行
    void run();

    void set_state( State enmStete ) noexcept { m_enmState = enmStete; }
    State get_state() const noexcept { return m_enmState; }

//Static Member Function
public:
    
};

}

#endif
