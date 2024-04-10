#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include "bookfullinfo.h"

class Download
{
public:
    Download(const BookFullInfo& book_info);
    Download(QString cover = "cover",
             QString url = "url",
             QString title = "title",
             QString authors = "authors",
             QString rating = "rating",
             QString description = "description",
             QString categories = "categories",
             QString edition = "edition",
             QString language = "language",
             QString isbn = "isbn",
             QString isbn10 = "isbn10",
             QString isbn13 = "isbn13",
             QString file = "file",
             QString volume = "volume",
             QString year = "year",
             QString publisher = "publisher",
             QString pages = "pages",
             QString series = "series",
             QString ipfs = "ipfs");
    ~Download();
public:
    QString cover;
    QString url;
    QString title;
    QString authors;
    QString rating;
    QString description;
    QString categories;
    QString edition;
    QString language;
    QString isbn;
    QString isbn10;
    QString isbn13;
    QString file;
    QString volume;
    QString year;
    QString publisher;
    QString pages;
    QString series;
    QString ipfs;
};

#endif // DOWNLOAD_H
