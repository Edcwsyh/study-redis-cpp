/*
    > File Name: Output.cpp
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年07月01日 星期五 12时08分00秒
*/

#include "Output.h"

std::ostream& operator<< ( std::ostream& out, Edc::Article& oArticle ) {
    out << "ID : " << oArticle.articleid()
              << " | time : " << oArticle.articledata().createtime()
              << " | Title : " << oArticle.articledata().title()
              << " | autor : " << oArticle.articledata().autor()
              << " | score : " << oArticle.score();
    return out;
}
