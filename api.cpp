#include "mainwindow.h"

#include "sslog.h"
#include "singsongzepe.h"

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
    SSLog::ln("key word: " + *search->key_word);
    SSLog::ln("search type: " + *search->search_type);

    QString url = MainWindow::make_url(search);

    SSLog::ln(url);

    QNetworkAccessManager manager;
    QNetworkRequest request{QUrl(url)};

    QNetworkReply* reply = manager.get(request);

    QTimer timer;
    timer.setSingleShot(true);
    QObject::connect(&timer, &QTimer::timeout, [&](){
        SSLog::le("error while request, timeout!");
    });

    // start the request loop
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, [&]() {
        timer.stop();
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();

            // python
            Py_Initialize();
            if (!Py_IsInitialized()) {
                SSLog::le("error while initilize python");
            }

            PyRun_SimpleString("import os");
            PyRun_SimpleString("import sys");

            QString str;
            str += "sys.path.append(os.path.dirname(os.getcwd())+'/";
            str += SingSongZepe::SSZPSENBON_;
            str += "')";
            PyRun_SimpleString(str.toStdString().c_str());
            PyRun_SimpleString("print(sys.path)");

            PyObject* pymodule = PyImport_ImportModule("book_result_parse");
            if (!pymodule) {
                SSLog::le("can't open the module file");
            }

            PyObject* callable = PyObject_GetAttrString(pymodule, "book_result_parse");

            // arguments
            PyObject* tuple = PyTuple_New(1);
            std::string stri = data.toStdString();
            PyObject* d = PyUnicode_FromString(stri.c_str());
            PyTuple_SET_ITEM(tuple, 0, d);

            PyObject* rep = PyObject_CallObject(callable, tuple);
            PyObject* py_json_str = PyObject_Str(rep);
            QString json_str = QString::fromUtf8(PyUnicode_AsUTF8(py_json_str));

            SSLog::ln("Result: " + json_str);

            QList<BookInfo> book_infos = MainWindow::json_str2book_infos(&json_str);
            qDebug() << book_infos[0].title;

            // call show_books


            // PyObject* callable = PyObject_GetAttrString(pymodule, "add");

            // PyObject* tuple = PyTuple_New(2);

            // PyObject* arg1 = PyLong_FromLong(1);
            // PyTuple_SET_ITEM(tuple, 0, arg1);
            // PyObject* arg2 = PyLong_FromLong(2);
            // PyTuple_SET_ITEM(tuple, 1, arg2);

            // PyObject* rep = PyObject_CallObject(callable, tuple);

            // long result = PyLong_AsLong(rep);
            // qDebug() << result;

            Py_Finalize();
        } else {
            qDebug() << "Error:" << reply->errorString();
        }

        reply->deleteLater();
    });
    loop.exec();
}
