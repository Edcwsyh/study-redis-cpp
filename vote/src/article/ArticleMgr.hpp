/*
    > File Name: ArticleMgr.hpp
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年06月30日 星期四 14时42分53秒
*/

#ifndef __ARTICLEMGR_EDC__
#define __ARTICLEMGR_EDC__

#include <string_view>
#include "Article.pb.h"
#include "base/Singleton.hpp"

namespace Edc{

class ArticleMgr : public Singleton<ArticleMgr> {
//Type
public:
    
//Constant
public:
protected:
    
//Member Variables
protected:
    
//Static Member Variables
protected:
    
//Member Function
private:
    ArticleMgr() = default;
    friend Singleton;
public:
    explicit ArticleMgr( const ArticleMgr& ) = delete;
    explicit ArticleMgr( ArticleMgr&& ) = delete;
    ~ArticleMgr() = default;
    ArticleMgr& operator=( const ArticleMgr& ) = delete;
    ArticleMgr& operator=( ArticleMgr&& ) = delete;

    int create_artile( std::string& sAutor, std::string& sTitle, std::string& sContent  );
//Static Member Function
public:
    
};

}

#endif
