#include "mainwindow.h"

#include "singsongzepe.h"
#include "sslog.h"

#include <QList>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>


// utils
QString MainWindow::make_url(const GeneralSearch* search) {
    QString url = SingSongZepe::zlibrary_url + SingSongZepe::subfix_general;
    url += "q=" + *search->key_word + "&e=" + (search->exact_matching ? "1" : "0");
    return url;
}

QList<BookInfo> MainWindow::json_str2book_infos(const QString* json_str) {
    QJsonDocument json_doc = QJsonDocument::fromJson((*json_str).toUtf8());
    if (!json_doc.isArray()) {
        SSLog::lw("there book infos json string is not an array");
        return QList<BookInfo>();
    }
    QJsonArray json_array = json_doc.array();
    QList<BookInfo> book_infos;

    for (const QJsonValue& value : json_array) {
        if (value.isObject()) {
            QJsonObject jsonObject = value.toObject();
            BookInfo book_info;
            book_info.url = jsonObject["url"].toString();
            book_info.cover = jsonObject["cover"].toString();
            book_info.title = jsonObject["title"].toString();
            book_info.publisher = jsonObject["publisher"].toString();
            book_info.authors = jsonObject["authors"].toString();
            book_info.file_info = jsonObject["file_info"].toString();
            book_info.language = jsonObject["language"].toString();
            book_info.rating = jsonObject["rating"].toString();

            book_infos.append(book_info);
        } else {
            SSLog::lw("constructing book_infos, there be a book_info is not a JsonObject");
        }
    }
    return book_infos;
}



