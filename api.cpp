#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_bookinfoitem.h"

#include "sslog.h"
#include "singsongzepe.h"
#include "bookinfoitem.h"
#include "singlebookinfo.h"
#include "function/savefile.h"

// network
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QTimer>
#include <QEventLoop>

#undef slots
#include "Python.h"
#define slots Q_SLOTS

void MainWindow::search_books(const GeneralSearch* search) {
    SSLog::ln("-----Search Info-----");
    SSLog::ln("key word: " + search->key_word);
    SSLog::ln("search type: " + search->search_type);

    QString url = MainWindow::make_url(search);

    SSLog::ln("request url: " + url);

    QNetworkAccessManager manager;
    QNetworkRequest request{QUrl(url)};

    QNetworkReply* reply = manager.get(request);
    reply->deleteLater();

    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);
    QObject::connect(&timer, &QTimer::timeout, [&](){
        SSLog::le(QString("error while request, timeout!").arg(url));
        loop.quit();
    });
    timer.start(SingSongZepe::TIME_REQUEST_TIMER_OUT);

    // start the request loop
    QObject::connect(reply, &QNetworkReply::finished, &loop, [&]() {
        timer.stop();
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();

            PyObject* pymodule = PyImport_ImportModule(SingSongZepe::PYTHON_BOOK_RESULT_PARSE.toStdString().c_str());
            if (!pymodule) {
                SSLog::le("can't open the module file");
                return;
            }

            PyObject* callable = PyObject_GetAttrString(pymodule, SingSongZepe::FUNCTION_BOOK_RESULT_PARSE.toStdString().c_str());

            // arguments
            PyObject* tuple = PyTuple_New(1);
            std::string stri = data.toStdString();
            PyObject* d = PyUnicode_FromString(stri.c_str());
            PyTuple_SET_ITEM(tuple, 0, d);

            PyObject* rep = PyObject_CallObject(callable, tuple);
            PyObject* py_json_str = PyObject_Str(rep);
            QString json_str = QString::fromUtf8(PyUnicode_AsUTF8(py_json_str));

            // SSLog::ln("Result: " + json_str);

            QList<BookInfo> book_infos = MainWindow::json_str2book_infos(&json_str);
            qDebug() << json_str;
            if (this->book_infos != nullptr) {
                delete this->book_infos;
            }
            this->book_infos = new QList<BookInfo>(std::move(book_infos)); // pass the value to this

            // call show_books
            MainWindow::show_books();
            loop.quit();
        } else {
            qDebug() << "Error:" << reply->errorString();
        }

    });
    loop.exec();
}

bool MainWindow::show_books() {
    // create object
    if (this->book_infos == nullptr) {
        SSLog::lw("can't call show_books when book_infos is nullptr");
        return false;
    }
    if (this->wgt_book_items != nullptr) {
        delete this->wgt_book_items;
    }
    this->wgt_book_items = new QWidget(ui->sa_books);
    int height = MainWindow::get_book_items_height();
    this->wgt_book_items->setGeometry(SingSongZepe::WGT_BOOK_ITEMS_X, SingSongZepe::WGT_BOOK_ITEMS_Y, height, SingSongZepe::SINGLE_BOOK_ITEM_WIDTH_DEFULT);
    this->wgt_book_items->setFixedHeight(height);
    this->wgt_book_items->setStyleSheet("background-color: #ADD8E6"); // color skyblue
    this->wgt_book_items->installEventFilter(this); // for which book user clicks

    int idx = 0;
    for (const auto& book_info : *book_infos) {
        // BookInfoItem* book_info_item = new BookInfoItem();
        BookInfoItem* book_info_item = new BookInfoItem(this->wgt_book_items, this); // pass context to BookInfoItem
        book_info_item->set_book_info(book_info);
        book_info_item->setGeometry(0, MainWindow::get_book_items_pos_y_by_index(idx), SingSongZepe::SINGLE_BOOK_ITEM_WIDTH_DEFULT, SingSongZepe::SINGLE_BOOK_ITEM_HEIGHT);
        // book_info_item->install_event_filter();
        // set main info title publisher authors
        // book_info_item->ui->tb_book_title->setText(book_info.title);
        // book_info_item->ui->tb_book_publisher->setText(book_info.publisher);
        // book_info_item->ui->tb_book_authors->setText(book_info.authors);
        // book_info_item->ui->lb_book_ratiing->setText(book_info.rating);
        // // set sub info file_info language
        // book_info_item->ui->lb_book_file_info->setText(book_info.file_info);
        // book_info_item->ui->lb_book_language->setText(book_info.language);
        idx++;
    }

    ui->sa_books->setWidget(this->wgt_book_items);

    // show wgt_books
    if (ui->wgt_books->isHidden()) {
        ui->wgt_books->setHidden(false);
    }

    return true;
}

void MainWindow::search_singlebook(const SingleBookSearch* search) {
    SSLog::ln("-----Single Book Search Info-----");
    SSLog::ln("search url: " + search->url);

    // new a single_book_info (widget)
    if (this->single_book_info != nullptr) {
        delete this->single_book_info;
    }
    this->single_book_info = new SingleBookInfo(ui->sa_singlebookview, this);

    // get html data
    Cookie cookie = this->lcm->get_one_cookie();
    QByteArray data = MainWindow::request_url_with_cookie(search->url, cookie.cookie);
    ((SingleBookInfo*) this->single_book_info)->set_cookie(cookie);

    // pass data to python for processing
    PyObject* pymodule = PyImport_ImportModule("search_single_book_parse");
    if (!pymodule) {
        SSLog::le("can't open the module file");
        return;
    }
    // qDebug() << data;
    // SaveFile::save_file(data, "default.html");

    PyObject* callable = PyObject_GetAttrString(pymodule, "search_single_book_parse");

    // arguments
    PyObject* tuple = PyTuple_New(1);
    std::string stri = data.toStdString();
    PyObject* d = PyUnicode_FromString(stri.c_str());
    PyTuple_SET_ITEM(tuple, 0, d);

    PyObject* rep = PyObject_CallObject(callable, tuple);
    PyObject* py_json_str = PyObject_Str(rep);
    QString json_str = QString::fromUtf8(PyUnicode_AsUTF8(py_json_str));

    if (json_str == SingSongZepe::JSON_STR_NULL) {
        SSLog::le("parse json string there be a error, may be python file be changed");
        return;
    }

    BookFullInfo book_full_info = MainWindow::json_str2book_full_info(&json_str);
    if (this->book_full_info != nullptr) {
        delete this->book_full_info;
    }

    this->book_full_info = new BookFullInfo(book_full_info);
    MainWindow::show_singlebook();
}

bool MainWindow::show_singlebook() {
    if (this->book_full_info == nullptr) {
        SSLog::lw("can't call show_singlebook when book_full_info is nullptr");
        return false;
    }

    ((SingleBookInfo*) this->single_book_info)->set_book_full_info(*this->book_full_info); // to const BookFullInfo&

    ui->sa_singlebookview->setWidget(this->single_book_info);
    MainWindow::toggle_view(SingSongZepe::SingleBookView);
    // qDebug() << this->book_full_info->title;

    return true;
}
