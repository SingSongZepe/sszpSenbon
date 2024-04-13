#ifndef DOWNLOADPROCESS_H
#define DOWNLOADPROCESS_H

#include "singsongzepe.h"
#include "object/download.h"
#include "wgt/downloadingitem.h"
#include "sslog.h"

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>

class DownloadProcess : public QObject
{
    Q_OBJECT
public:
    explicit DownloadProcess(Download d, QObject *parent = nullptr);
    ~DownloadProcess();

    void run();
    void start();
    void done();

public:
    Download d;
    QThread* d_thread;
    // QTimer* d_timer;
    DownloadingItem* d_item;

    // for download
    QNetworkAccessManager* manager;
    QNetworkReply* reply;
    QByteArray data_buffer;
    QTimer timer;

    int total;

    static const int UPDATE_INTERVAL; // millisecond

signals:
    void sgn_done();
    void sgn_update_process(int, QString); // process 0 to 100 percent, download speed

};

#endif // DOWNLOADPROCESS_H
