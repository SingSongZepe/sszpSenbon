#include "downloadhistoryviewmanger.h"

#include "mainwindow.h"

DownloadHistoryViewManger::DownloadHistoryViewManger(MainWindow* context, QObject *parent)
    : QObject{parent}
    , context(context)
{

}

DownloadHistoryViewManger::~DownloadHistoryViewManger() {

}
