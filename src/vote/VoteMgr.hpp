/*
    > File Name: VoteMgr.hpp
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年06月30日 星期四 11时21分16秒
*/

#ifndef __VOTEMGR_EDC__
#define __VOTEMGR_EDC__

#include <memory>
#include <string_view>
#include <sw/redis++/redis++.h>
#include <sw/redis++/redis.h>
#include <unordered_map>
#include <vector>
#include "base/Singleton.hpp"
#include "article/Article.pb.h"

namespace Edc {

class VoteMgr : public Singleton<VoteMgr> {
//Type
public:
    
//Constant
public:
protected:
    constexpr static std::string_view TABLE_ARTICLE = "article_entry"; // 文章实体表
    constexpr static std::string_view TABLE_SCORE = "article_socre";
    constexpr static std::string_view TABLE_USER = "article_user_";
    constexpr static std::string_view KEY_ARTICLE_ID = "article_id";
    constexpr static uint64_t DEFAULT_ARTICLE_ID = 1000;

    // 投票相关
    constexpr static uint32_t REDUCE_CYCLE = 1000; //衰减周期
    constexpr static uint32_t REDUCE_SOCRE = 20; //衰减分数
    constexpr static uint32_t VOTE_SCORE = 100; //投票分数
    constexpr static uint32_t VOTE_LIMIT = 12000; //投票周期限制(创建时间超过该值无法投票)
    
//Member Variables
protected:
    sw::redis::Redis m_oRedis;
    
//Static Member Variables
protected:
    
//Member Function
private:
    VoteMgr();
    friend Singleton;

    std::string get_article_user_table( const Article& oArticle );
public:
    explicit VoteMgr( const VoteMgr& ) = delete;
    explicit VoteMgr( VoteMgr&& ) = delete;
    ~VoteMgr() = default;
    VoteMgr& operator=( const VoteMgr& ) = delete;
    VoteMgr& operator=( VoteMgr&& ) = delete;

    // 获取下一文章ID
    uint64_t get_next_article_id();

    // 创建一个文章对象
    int add_article( const Article& oArticle );
    
    // 获取所有的文章对象
    std::vector<Article> get_all_article();

    // 获取文章对象
    std::unique_ptr<Article> get_article_by_id( std::string_view sArticleID );

    // 投票
    int vote( std::string_view sArticleID, std::string_view username );
//Static Member Function
public:
    
};

}

#endif
