#include "download.h"

Download::Download(const BookFullInfo& book_info)
    : cover(book_info.cover)
    , url(book_info.url)
    , title(book_info.title)
    , authors(book_info.authors)
    , rating(book_info.rating)
    , description(book_info.description)
    , categories(book_info.categories)
    , edition(book_info.edition)
    , language(book_info.language)
    , isbn(book_info.isbn)
    , isbn10(book_info.isbn10)
    , isbn13(book_info.isbn13)
    , file(book_info.file)
    , volume(book_info.volume)
    , year(book_info.year)
    , publisher(book_info.publisher)
    , pages(book_info.pages)
    , series(book_info.series)
    , ipfs(book_info.ipfs)
{
}

Download::Download(QString cover,
                    QString url ,
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

Download::~Download() {

}
