/*
    > File Name: VoteMgr.cpp
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年06月30日 星期四 11时35分53秒
*/

#include <article/Article.pb.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <string_view>
#include <sw/redis++/command_options.h>
#include <unordered_map>
#include <utility>
#include <vector>
#include "VoteMgr.hpp"

namespace Edc {

VoteMgr::VoteMgr() : m_oRedis( "tcp://127.0.0.1:6379" ) {
    auto oRes = m_oRedis.get( KEY_ARTICLE_ID );
    if ( !oRes.has_value() ) {
        m_oRedis.set( KEY_ARTICLE_ID, std::to_string( DEFAULT_ARTICLE_ID ) );
    }
}

int VoteMgr::add_article( const Article& oArticle ) {
    // 序列化文章对象并保存至redis
    std::string sArticleID( std::to_string( oArticle.articleid() ) );
    if ( !m_oRedis.hset( TABLE_ARTICLE, sArticleID, oArticle.SerializeAsString() ) ) {
        std::cerr << "Article already exists " << oArticle.articleid() << std::endl;
        return -1;
    }
    std::string oUserTable( TABLE_USER );
    oUserTable += sArticleID;
    // 将作者加入投票列表
    m_oRedis.sadd( oUserTable, oArticle.articledata().autor() );
    // 设置过期时间
    m_oRedis.expire( oUserTable, VOTE_LIMIT );
    m_oRedis.zadd( TABLE_SCORE, sArticleID, oArticle.score(), sw::redis::UpdateType::NOT_EXIST);
    m_oRedis.zadd( TABLE_TIME, sArticleID, oArticle.articledata().createtime(), sw::redis::UpdateType::NOT_EXIST);
    return 0;
}


std::unordered_map<std::string, std::string> VoteMgr::get_article_entry_map() {
    std::unordered_map<std::string, std::string> oRedisResMap;
    m_oRedis.hgetall( TABLE_ARTICLE, std::inserter( oRedisResMap, oRedisResMap.begin() ) );
    return oRedisResMap;
}

std::vector<Article> VoteMgr::get_all_article() {
    auto oRedisResMap = get_article_entry_map();
    std::vector<Article> oRes;
    for ( auto& [_, oArticleBinData] : oRedisResMap ) {
        Article oArticle;
        oArticle.ParseFromString( oArticleBinData );
        oRes.emplace_back( oArticle );
    }
    return oRes;
}

// 获取热榜
std::vector<Article> VoteMgr::get_article_top_score( uint64_t ullNum ) {
    auto oRedisResMap = get_article_entry_map(); //实体哈希表
    std::vector<std::pair<std::string, double>> oRedisZSetRes; //Zset的映射
    std::vector<Article> oRes; //返回的结果
    m_oRedis.zrevrangebyscore( TABLE_SCORE, sw::redis::UnboundedInterval<double>{}, 
        std::back_inserter(oRedisZSetRes) );
    for ( auto iter = oRedisZSetRes.begin(); iter != oRedisZSetRes.end() && ullNum; ++iter, --ullNum ) {
        Article oArticle;
        auto &sArticleID = iter->first;
        if ( auto pTaget = oRedisResMap.find( sArticleID );pTaget != oRedisResMap.end() ) {
            oArticle.ParseFromString( pTaget->second );
        } else {
            std::cerr << "Get article entry fail, id : " << sArticleID << std::endl;
            continue;
        }
        oRes.emplace_back( oArticle );
    }
    return oRes;
}

// 获取按照最早时间排序的文章 
std::vector<Article> VoteMgr::get_article_top_time( uint64_t ullNum ) {
    auto oRedisResMap = get_article_entry_map(); //实体哈希表
    std::vector<std::pair<std::string, double>> oRedisZSetRes; //Zset的映射
    std::vector<Article> oRes; //返回的结果
    m_oRedis.zrangebyscore( TABLE_TIME, sw::redis::UnboundedInterval<double>{}, 
        std::back_inserter(oRedisZSetRes) );
    for ( auto iter = oRedisZSetRes.begin(); iter != oRedisZSetRes.end() && ullNum; ++iter, --ullNum ) {
        Article oArticle;
        auto &sArticleID = iter->first;
        if ( auto pTaget = oRedisResMap.find( sArticleID );pTaget != oRedisResMap.end() ) {
            oArticle.ParseFromString( pTaget->second );
        } else {
            std::cerr << "Get article entry fail, id : " << sArticleID << std::endl;
            continue;
        }
        oRes.emplace_back( oArticle );
    }
    return oRes;
}

// 获取下一文章ID
uint64_t VoteMgr::get_next_article_id() {
    auto oRes = m_oRedis.get( KEY_ARTICLE_ID );
    if ( oRes.has_value() ) {
        uint64_t ullResult = std::strtoull( oRes.value().c_str(), nullptr, 10 );
        m_oRedis.incr( KEY_ARTICLE_ID );
        return ullResult;
    }
    uint64_t ullResult = DEFAULT_ARTICLE_ID;
    m_oRedis.set( KEY_ARTICLE_ID, std::to_string( ullResult + 1 ) );
    return ullResult;
}

std::unique_ptr<Article> VoteMgr::get_article_by_id( std::string_view sArticleID ) {
    auto oRes = m_oRedis.hget( TABLE_ARTICLE, sArticleID );
    if ( !oRes.has_value() ) {
        return nullptr;
    }
    auto pArticle = std::make_unique<Article>();
    pArticle->ParseFromString( oRes.value() );
    return std::move( pArticle );
}

// 投票
int VoteMgr::vote( std::string_view sArticleID, std::string_view sUsername ) {
    std::string oUserTable( TABLE_USER );
    oUserTable += sArticleID;
    auto pArticle = get_article_by_id( sArticleID );
    if ( !pArticle ) {
        std::cerr << "Article does not exist id : " << sArticleID << std::endl;
        return -1;
    }
    if ( pArticle->articledata().createtime() + VOTE_LIMIT < time( nullptr ) ) {
        std::cerr << "The article is out of date, article id : " << pArticle->articleid() << std::endl;
        return -1;
    }
    if ( m_oRedis.sismember( oUserTable, sUsername ) ) {
        std::cerr << "User " << sUsername << "has already voted for Article " << sArticleID << std::endl;
        return -1;
    }
    pArticle->set_score( pArticle->score() + VOTE_SCORE );
    // 同步到实体列表
    m_oRedis.hset( TABLE_ARTICLE, sArticleID, pArticle->SerializeAsString() );
    // 更新分数
    m_oRedis.zincrby( TABLE_SCORE, VOTE_SCORE, sArticleID );
    //m_oRedis.zadd( TABLE_SCORE, sArticleID, pArticle->score(), sw::redis::UpdateType::EXIST );
    // 加入投票列表
    m_oRedis.sadd( oUserTable, sUsername );
    return 0;
}

}
