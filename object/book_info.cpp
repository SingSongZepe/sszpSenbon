#include "object/book_info.h"

#include <QString>

BookInfo::BookInfo(QString href,
                   QString cover,
                   QString title,
                   QString publisher,
                   QString authors,
                   QString file_info,
                   QString language,
                   QString rating)
    : href(href)
    , cover(cover)
    , title(title)
    , publisher(publisher)
    , authors(authors)
    , file_info(file_info)
    , language(language)
    , rating(rating)
{

}

BookInfo::~BookInfo()
{

}
