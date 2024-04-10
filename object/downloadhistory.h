#ifndef DOWNLOADHISTORY_H
#define DOWNLOADHISTORY_H

#include "download.h"
// use generate time and id
#include "searchhistory.h"

class DownloadHistory
{
public:
    DownloadHistory();
    DownloadHistory(const Download& download);
    DownloadHistory(const Download& download, const QString& time, const QString& id);
    ~DownloadHistory();
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
    QString time;
    QString id;
};

#endif // DOWNLOADHISTORY_H
