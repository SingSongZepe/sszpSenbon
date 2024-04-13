#include "downloadmanger.h"

DownloadManger::DownloadManger(MainWindow* context, QObject *parent)
    : QObject{parent}
    , context(context)
{

}

DownloadManger::~DownloadManger() {

}

void DownloadManger::append_download_event(Download d) {
    DownloadProcess* dp = new DownloadProcess(d);
}
