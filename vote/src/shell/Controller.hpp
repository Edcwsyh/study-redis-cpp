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
    constexpr static uint32_t COMPLETE_OUT_PUT_LINE_NUM = 8; // 补充系统每行输出的匹配命令数量
    constexpr static std::string_view SHOW_INPUT = "# Vote|> ";
    
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
    // 命令补全
    void command_complete(std::string& input);
    // 补全处理(可选命令为0)
    void handle_complete_0( const std::string& prefix );
    // 补全处理(可选命令为多个)
    void handle_complete_n(const std::string& prefix, std::vector<std::string>& oVec );
    // 设置无缓冲输入
    void set_no_buffer_input();
    // 从stdint读取一个字符
    char read_char_from_stdin();
    // 从stdint读取一个字符, 不管有没有效, 直接返回
    char read_char_from_stdin_once();
    // 尝试处理方向键
    void try_handle_direction_key();
    // 输出到标准输出
    void print_stdout( std::string_view str, bool bNewLine = false );
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
