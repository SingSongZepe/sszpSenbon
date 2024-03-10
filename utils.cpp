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
            QJsonObject jsonObject = value.toObject();
            BookInfo book_info;
            book_info.href = jsonObject["url"].toString();
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

// for python
bool MainWindow::initializa_python() {
    // python
    if (!Py_IsInitialized()) {
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
// 10(n+1)+161*n
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

// for loading picture (for QLabel?)
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



