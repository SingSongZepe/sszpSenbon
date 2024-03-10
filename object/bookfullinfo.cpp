#include "bookfullinfo.h"

BookFullInfo::BookFullInfo(QString cover,
                           QString url,
                           QString title,
                           QString authors,
                           QString rating,
                           QString description,
                           QString categories,
                           QString edition,
                           QString language,
                           QString isbn,
                           QString isbn10,
                           QString isbn13,
                           QString file,
                           QString volume,
                           QString year,
                           QString publisher,
                           QString pages,
                           QString series,
                           QString ipfs)
    : cover(cover)
    , url(url)
    , title(title)
    , authors(authors)
    , rating(rating)
    , description(description)
    , categories(categories)
    , edition(edition)
    , language(language)
    , isbn(isbn)
    , isbn10(isbn10)
    , isbn13(isbn13)
    , file(file)
    , volume(volume)
    , year(year)
    , publisher(publisher)
    , pages(pages)
    , series(series)
    , ipfs(ipfs)
{

}

BookFullInfo::~BookFullInfo()
{

}
