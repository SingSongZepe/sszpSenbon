#include "mainwindow.h"

#include "singsongzepe.h"
#include "sslog.h"

#include <QList>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QTimer>
#include <QEventLoop>
#include <QVariant>
#include <QNetworkCookie>
#include <QNetworkCookieJar>

#undef slots
#include "Python.h"
#define slots Q_SLOTS


// utils
QString MainWindow::make_url(const GeneralSearch* search) {
    QString url = SingSongZepe::zlibrary_url + SingSongZepe::subfix_general;
    url += "q=" + search->key_word + "&e=" + (search->exact_matching ? "1" : "0");
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
            QJsonObject json_object = value.toObject();
            BookInfo book_info;
            book_info.href = json_object[SingSongZepe::HREF_].toString();
            book_info.cover = json_object[SingSongZepe::COVER_].toString();
            book_info.title = json_object[SingSongZepe::TITLE_].toString();
            book_info.publisher = json_object[SingSongZepe::PUBLISHER_].toString();
            book_info.authors = json_object[SingSongZepe::AUTHORS_].toString();
            book_info.file_info = json_object[SingSongZepe::FILE_INFO_].toString();
            book_info.language = json_object[SingSongZepe::LANGUAGE_].toString();
            book_info.rating = json_object[SingSongZepe::RATING_].toString();

            book_infos.append(book_info);
        } else {
            SSLog::lw("constructing book_infos, there be a book_info is not a JsonObject");
        }
    }
    return book_infos;
}

BookFullInfo MainWindow::json_str2book_full_info(const QString* json_str) {
    QJsonDocument json_doc = QJsonDocument::fromJson((*json_str).toUtf8());
    QJsonObject json_object = json_doc.object();

    BookFullInfo book_info;
    book_info.cover = json_object[SingSongZepe::COVER_].toString();
    book_info.url = json_object[SingSongZepe::URL_].toString();
    book_info.title = json_object[SingSongZepe::TITLE_].toString();
    book_info.authors = json_object[SingSongZepe::AUTHORS_].toString();
    book_info.rating = json_object[SingSongZepe::RATING_].toString();
    book_info.description = json_object[SingSongZepe::DESCRIPTION_].toString();
    book_info.categories = json_object[SingSongZepe::CATEGORIES_].toString();
    book_info.edition = json_object[SingSongZepe::EDITION_].toString();
    book_info.language = json_object[SingSongZepe::LANGUAGE_].toString();
    book_info.isbn = json_object[SingSongZepe::ISBN_].toString();
    book_info.isbn10 = json_object[SingSongZepe::ISBN10_].toString();
    book_info.isbn13 = json_object[SingSongZepe::ISBN13_].toString();
    book_info.file = json_object[SingSongZepe::FILE_].toString();
    book_info.volume = json_object[SingSongZepe::VOLUME_].toString();
    book_info.year = json_object[SingSongZepe::YEAR_].toString();
    book_info.publisher = json_object[SingSongZepe::PUBLISHER_].toString();
    book_info.pages = json_object[SingSongZepe::PAGES_].toString();
    book_info.series = json_object[SingSongZepe::SERIES_].toString();
    book_info.ipfs = json_object[SingSongZepe::IPFS_].toString();

    return book_info;
}


// for python
bool MainWindow::initializa_python() {
    // python
    if (!Py_IsInitialized()) {
        // maybe there we will store it in "config.json" or "sszpsenbon.conf"
        Py_SetPythonHome((const wchar_t *)(L"C:\\Users\\Lenovo\\AppData\\Local\\Programs\\Python\\Python311"));
        Py_Initialize();
        PyRun_SimpleString("import os");
        PyRun_SimpleString("import sys");

        QString str;
        str += "sys.path.append(os.path.dirname(os.getcwd())+'/";
        str += SingSongZepe::SSZPSENBON_;
        str += "')";
        PyRun_SimpleString(str.toStdString().c_str());
        PyRun_SimpleString("print(sys.path)");
        return true;
        if (!Py_IsInitialized()) {
            return false;
        }
    }
    return true;
}

bool MainWindow::finalize_python() {
    if (Py_IsInitialized()) {
        Py_Finalize();
        if (!Py_IsInitialized())
            return true;
        return false;
    }
    return true;
}

// for wgt_book_items
// 10*(n+1)+161*n
int MainWindow::get_book_items_height() {
    if (this->book_infos != nullptr) {
        return (SingSongZepe::SINGLE_BOOK_ITEM_HEIGHT + SingSongZepe::BOOK_ITEM_MARGIN) * this->book_infos->count() + SingSongZepe::BOOK_ITEM_MARGIN;
    }
    SSLog::lw("can't call get_book_items_height, when there book_infos is nullptr");
    return 0;
}

int MainWindow::get_book_items_pos_y_by_index(int index) {
    return (SingSongZepe::SINGLE_BOOK_ITEM_HEIGHT + SingSongZepe::BOOK_ITEM_MARGIN) * index;
}

// for loading (for QLabel?)
QByteArray MainWindow::request_url(const QString& url) {
    QNetworkAccessManager manager;
    QNetworkRequest request = QNetworkRequest(QUrl(url));
    QNetworkReply* reply = manager.get(request);

    QEventLoop loop;
    QTimer timer;
    timer.start(SingSongZepe::TIME_REQUEST_TIMER_OUT);
    QObject::connect(&timer, &QTimer::timeout, [&](){
        SSLog::le(QString("error while request url: %1").arg(url));
        reply->abort();
        loop.quit();
    });

    QByteArray data;
    QObject::connect(reply, &QNetworkReply::finished, [&](){
        if (reply->error() == QNetworkReply::NoError) {
            data = reply->readAll();
        }
        reply->deleteLater();
        loop.quit();
    });

    loop.exec();
    return data;
}

// for downloading with cookie
QByteArray MainWindow::request_url_with_cookie(const QString& url, const QString& cookie) {
    QNetworkAccessManager manager;
    QNetworkRequest request = QNetworkRequest(QUrl(url));

    request.setRawHeader("Cookie", cookie.toUtf8());

    QNetworkReply* reply = manager.get(request);

    QEventLoop loop;
    QTimer timer;
    timer.start(SingSongZepe::TIME_REQUEST_TIMER_OUT);
    QObject::connect(&timer, &QTimer::timeout, [&](){
        SSLog::le(QString("error while request url: %1").arg(url));
        reply->abort();
        loop.quit();
    });

    QByteArray data;
    QObject::connect(reply, &QNetworkReply::finished, [&](){
        if (reply->error() == QNetworkReply::NoError) {
            data = reply->readAll();
        }
        reply->deleteLater();
        loop.quit();
    });

    loop.exec();
    return data;
}

// for downloading with cookie, and no timeout
QByteArray MainWindow::request_url_with_cookie_no_timeout(const QString& url, const QString& cookie) {
    QNetworkAccessManager manager;
    QNetworkRequest request = QNetworkRequest(QUrl(url));

    request.setRawHeader("Cookie", cookie.toUtf8());

    QNetworkReply* reply = manager.get(request);

    QEventLoop loop;

    QByteArray data;
    QObject::connect(reply, &QNetworkReply::finished, [&](){
        if (reply->error() == QNetworkReply::NoError) {
            data = reply->readAll();
        }
        reply->deleteLater();
        loop.quit();
    });

    loop.exec();
    return data;
}

QPixmap MainWindow::load_picture(const QString& url) {
    QByteArray data = MainWindow::request_url(url);
    QPixmap pixmap;
    pixmap.loadFromData(data);
    return pixmap;
}

bool MainWindow::set_label_pixmap(QLabel* lb, const QPixmap& pixmap) {
    lb->setPixmap(pixmap.scaled(lb->size(), Qt::KeepAspectRatio));
    return true;
}

const BookInfo* MainWindow::get_bookinfo_of_pos(const QPoint& pos) {
    if (this->book_infos == nullptr) {
        return nullptr;
    }
    int x = pos.x();
    int y = pos.y();

    if (x >= 5 && x <= 105) {
        int n = (y - 10) / 170;
        if (n >= this->book_infos->length()) {
            return nullptr;
        }
        if (y >= 170 * n + 10 && y <= 170 * n + 150 && n >= 0 && n <= 49) {
            return &this->book_infos->at(n);
        }
    }
    return nullptr;
}



