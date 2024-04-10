#include "downloadhistory.h"

DownloadHistory::DownloadHistory() {

};

DownloadHistory::DownloadHistory(const Download& download)
    : cover(download.cover)
    , url(download.url)
    , title(download.title)
    , authors(download.authors)
    , rating(download.rating)
    , description(download.description)
    , categories(download.categories)
    , edition(download.edition)
    , language(download.language)
    , isbn(download.isbn)
    , isbn10(download.isbn10)
    , isbn13(download.isbn13)
    , file(download.file)
    , volume(download.volume)
    , year(download.year)
    , publisher(download.publisher)
    , pages(download.pages)
    , series(download.series)
    , ipfs(download.ipfs)
    , time(SearchHistory::generate_time())
    , id(SearchHistory::generate_id())
{
}

DownloadHistory::DownloadHistory(const Download& download, const QString& time, const QString& id)
    : cover(download.cover)
    , url(download.url)
    , title(download.title)
    , authors(download.authors)
    , rating(download.rating)
    , description(download.description)
    , categories(download.categories)
    , edition(download.edition)
    , language(download.language)
    , isbn(download.isbn)
    , isbn10(download.isbn10)
    , isbn13(download.isbn13)
    , file(download.file)
    , volume(download.volume)
    , year(download.year)
    , publisher(download.publisher)
    , pages(download.pages)
    , series(download.series)
    , ipfs(download.ipfs)
    , time(time)
    , id(id)
{
}

DownloadHistory::~DownloadHistory() {

}
