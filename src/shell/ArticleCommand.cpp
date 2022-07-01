/*
    > File Name: ArticleCommand.cpp
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年06月30日 星期四 19时18分16秒
*/

#include <cstdlib>
#include <string>
#include <string_view>
#include "ArticleCommand.h"
#include "vote/VoteMgr.hpp"
#include "article/ArticleMgr.hpp"
#include "Output.h"

void command_create_article( std::vector<std::string>& commands ) {
    if ( commands.size() != 3 ) {
        std::cerr << "command error , please use 'help " << commands.front() << "'" << std::endl;
        return;
    }
    std::string& sAutor = commands[1];
    std::string& sTitle = commands[2];
    std::string conetent;
    Edc::ArticleMgr::instance().create_artile( sAutor, sTitle, conetent );
}

void command_all_article( std::vector<std::string>& commands ) {
    if ( commands.size() != 1 ) {
        std::cerr << "command error , please use 'help " << commands.front() << "'" << std::endl;
        return;
    }
    auto oArticleList = Edc::VoteMgr::instance().get_all_article();
    for ( auto& oArticle: oArticleList ) {
        std::cout << oArticle << std::endl;
    }
}

// 投票
void command_vote( std::vector<std::string>& commands ) {
    if ( commands.size() != 3 ) {
        std::cerr << "command error , please use 'help " << commands.front() << "'" << std::endl;
        return;
    }
    std::string_view sUsername = commands[1];
    std::string_view sArticle = commands[2];
    Edc::VoteMgr::instance().vote( sArticle, sUsername );
}

#define DEFATILT_TOP_NUM 10 //默认热榜数量
// 热榜
void command_top( std::vector<std::string>& commands ) {
    uint64_t ullShowNum = DEFATILT_TOP_NUM;
    switch ( commands.size() ) {
        case 2 : 
            ullShowNum = std::strtoull( commands[1].c_str(), nullptr, 10 );
            break;
        case 1 : 
            break;
        default :
            std::cerr << "command error , please use 'help " << commands.front() << "'" << std::endl;
            return;
    }
    auto oArticleList = Edc::VoteMgr::instance().get_article_top_score( ullShowNum );
    for ( auto &oArticle : oArticleList ) {
        std::cout << oArticle << std::endl;
    }
}

void command_top_time( std::vector<std::string>& commands ) {
    uint64_t ullShowNum = DEFATILT_TOP_NUM;
    switch ( commands.size() ) {
        case 2 : 
            ullShowNum = std::strtoull( commands[1].c_str(), nullptr, 10 );
            break;
        case 1 : 
            break;
        default :
            std::cerr << "command error , please use 'help " << commands.front() << "'" << std::endl;
            return;
    }
    auto oArticleList = Edc::VoteMgr::instance().get_article_top_time( ullShowNum );
    for ( auto &oArticle : oArticleList ) {
        std::cout << oArticle << std::endl;
    }
}
