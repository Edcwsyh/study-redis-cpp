/*
    > File Name: ArticleCommand.h
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年06月30日 星期四 19时16分56秒
*/

#ifndef __ARTICLECOMMAND_EDC__
#define __ARTICLECOMMAND_EDC__

#include <vector>
#include <string>

// 创建文章
void command_create_article( std::vector<std::string>& commands );
// 所有文章列表
void command_all_article( std::vector<std::string>& commands );
// 投票
void command_vote( std::vector<std::string>& commands );
// 热榜
void command_top( std::vector<std::string>& commands );
// 获取文章列表--按时间先后排序
void command_top_time( std::vector<std::string>& commands );

#endif
