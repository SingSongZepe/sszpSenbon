#ifndef DOWNLOADMANGER_H
#define DOWNLOADMANGER_H

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

public:
    MainWindow* context;

signals:

};

#endif // DOWNLOADMANGER_H
