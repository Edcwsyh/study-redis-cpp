/*
    > File Name: ArticleMgr.cpp
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年06月30日 星期四 14时50分16秒
*/

#include <ctime>
#include <iostream>
#include "ArticleMgr.hpp"
#include "vote/VoteMgr.hpp"

namespace Edc {

int ArticleMgr::create_artile( std::string& sAutor, std::string& sTitle, std::string& sContent  ) {
    Article oArticle;
    auto* pData = oArticle.mutable_articledata();
    if ( !pData ) {
        std::cerr << "Protobuf exception!" << std::endl;
        return -1;
    }
    pData->set_title( std::move( sTitle ) );
    pData->set_content( std::move( sContent ) );
    pData->set_autor( std::move( sAutor ) );
    pData->set_createtime( time(nullptr) );
    oArticle.set_articleid( VoteMgr::instance().get_next_article_id() );
    oArticle.set_score( 0 );
    VoteMgr::instance().add_article( oArticle );
    std::cout << "Create article success, article id : " << oArticle.articleid() << std::endl;
    return 0;
}

}
