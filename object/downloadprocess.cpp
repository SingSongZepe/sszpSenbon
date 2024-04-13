#include "downloadprocess.h"

#include "mainwindow.h"

#include <QDebug>

const int DownloadProcess::UPDATE_INTERVAL = 1000;

DownloadProcess::DownloadProcess(Download d, QObject *parent)
    : QObject{parent}
    , d(d)
    , d_item(new DownloadingItem(d))
    , timer(QTimer())
{
    this->manager = new QNetworkAccessManager();
    // d.url
    this->reply = manager->get(QNetworkRequest(QUrl("https://www.baidu.com")));

    // this->d_timer = new QTimer();
    this->d_thread = new QThread();
    QObject::moveToThread(this->d_thread);

    QObject::connect(this->d_thread, &QThread::started, [&]() {
        this->run();
    });
    QObject::connect(this->d_thread, &QThread::finished, this, &DownloadProcess::sgn_done);
}

DownloadProcess::~DownloadProcess() {

}

void DownloadProcess::run() {
    qDebug() << "run";
    // this->d_timer->start(DownloadProcess::UPDATE_INTERVAL);
    // download

    // QFile pf1(SingSongZepe::PATH_STORE_FILE_DOWNLOAD + "/baidu.txt");
    // if (pf.exists()) {
    //     qDebug() << "file exists";
    // }

    QObject::connect(&timer, &QTimer::timeout, [&]() {
        qDebug() << 1;
    });
    timer.start(100);

    QObject::connect(reply, &QNetworkReply::readyRead, [&](){
        QByteArray data = reply->read(1024);
        this->total += data.size();
    });

    QObject::connect(reply, &QNetworkReply::finished, [&](){
        timer.stop();
        qDebug() << "Request completed. Total received data size: " << total;
        QFile pf(SingSongZepe::PATH_STORE_FILE_DOWNLOAD + "/baidu.txt");
        if (!pf.open(QIODevice::WriteOnly)) {
            qDebug() << "failed";
        }
        pf.write(reply->readAll());
        pf.close();
    });
}

void DownloadProcess::start() {
    if (this->d_thread != nullptr && !this->d_thread->isRunning()) {
        this->d_thread->start();

    } else {
        SSLog::ln("download thread running or not initilized");
    }
}

void DownloadProcess::done() {
    delete d_thread;
    // delete d_timer;
    delete d_item;

    // delete for download
    delete manager;
    delete reply;
    // delete pf;
    // delete timer;
}
