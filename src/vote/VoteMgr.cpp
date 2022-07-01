/*
    > File Name: VoteMgr.cpp
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年06月30日 星期四 11时35分53秒
*/

#include <article/Article.pb.h>
#include <cstdlib>
#include <iterator>
#include <memory>
#include <string>
#include <string_view>
#include <sw/redis++/command_options.h>
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
    if ( !m_oRedis.hset( TABLE_ARTICLE, std::to_string( oArticle.articleid() ), 
        oArticle.SerializeAsString() ) 
       ) {
        std::cerr << "Article already exists " << oArticle.articleid() << std::endl;
        return -1;
    }
    return m_oRedis.zadd( TABLE_SCORE, std::to_string( oArticle.articleid() ), oArticle.score(), sw::redis::UpdateType::NOT_EXIST);
}

std::vector<Article> VoteMgr::get_all_article() {
    std::vector<std::pair<std::string, double>> oZsetRes;
    std::vector<Article> oRes;
    m_oRedis.zrangebyscore( TABLE_SCORE, sw::redis::UnboundedInterval<double>{}, std::back_inserter( oZsetRes ) );
    for ( auto& [str, fSocre] : oZsetRes ) {
        auto pArticle = get_article_by_id( str );
        if ( !pArticle ) {
            std::cerr << "Get article entry error, id : " << str << std::endl;
        }
        oRes.emplace_back( *(pArticle.release()) );
    }
    return oRes;
}

// 获取下一文章ID
uint64_t VoteMgr::get_next_article_id() {
    auto oRes = m_oRedis.get( KEY_ARTICLE_ID );
    if ( oRes.has_value() ) {
        uint64_t ullResult = std::strtoull( oRes.value().c_str(), nullptr, 10 );
        m_oRedis.set( KEY_ARTICLE_ID, std::to_string( ullResult + 1 ) );
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
    if ( m_oRedis.sismember( oUserTable, sUsername ) ) {
        std::cerr << "User " << sUsername << "has already voted for Article " << sArticleID << std::endl;
        return -1;
    }
    auto pArticle = get_article_by_id( sArticleID );
    if ( !pArticle ) {
        std::cerr << "Article does not exist id : " << sArticleID << std::endl;
        return -1;
    }
    pArticle->set_score( pArticle->score() + VOTE_SCORE );
    // 同步到实体列表
    m_oRedis.hset( TABLE_ARTICLE, sArticleID, pArticle->SerializeAsString() );
    // 更新分数
    m_oRedis.zadd( TABLE_SCORE, sArticleID, pArticle->score(), sw::redis::UpdateType::EXIST );
    // 加入投票列表
    m_oRedis.sadd( oUserTable, sUsername );
    return 0;
}

}
