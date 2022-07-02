/*
    > File Name: main.cpp
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年06月30日 星期四 11时38分17秒
*/

#include <exception>
#include <iostream>
#include "shell/Controller.hpp"
#include "shell/CommandExec.hpp"

int main() {
    try {
        Edc::CommandExec::instance().register_all_commands(); //注册所有命令
        Edc::Controller::instance().register_command_exec( &Edc::CommandExec::instance() ); // 注册命令执行器
        Edc::Controller::instance().run();
    } catch ( std::exception& e ) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
