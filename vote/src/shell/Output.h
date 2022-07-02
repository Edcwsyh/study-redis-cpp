/*
    > File Name: Output.h
    > Author: Edcwsyh
    > Mail: const.nullPointer@gmail.com
    > Created Time: 2022年07月01日 星期五 11时25分00秒
*/

#ifndef __OUTPUT_EDC__
#define __OUTPUT_EDC__

#include <iostream>
#include <ostream>
#include "article/Article.pb.h"

std::ostream& operator<< ( std::ostream&, Edc::Article& oArticle );

#endif
