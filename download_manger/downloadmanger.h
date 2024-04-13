#ifndef DOWNLOADMANGER_H
#define DOWNLOADMANGER_H

#include "object/downloadhistory.h"
#include "object/downloadprocess.h"

#include <QObject>
#include <QList>


class MainWindow;

class DownloadManger : public QObject
{
    Q_OBJECT
public:
    explicit DownloadManger(MainWindow* context, QObject *parent = nullptr);
    ~DownloadManger();

    // append download thread
    void append_download_event(Download d);

public:
    MainWindow* context;
    QList<DownloadProcess*> dp_pool;

signals:

};

#endif // DOWNLOADMANGER_H
