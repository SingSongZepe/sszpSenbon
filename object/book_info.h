#include <QString>

class BookInfo {
public:
    QString url;
    QString cover;
    QString title;
    QString publisher;
    QString authors;
    QString file_info;
    QString language;
    QString rating;

public:
    BookInfo(QString url = "url",
             QString  = "cover",
             QString title = "title",
             QString publisher = "publisher",
             QString authors = "authors",
             QString file_info = "file_info",
             QString language = "language",
             QString rating = "rating");
    ~BookInfo();
};

