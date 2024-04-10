#include "downloadmanger.h"

DownloadManger::DownloadManger(MainWindow* context, QObject *parent)
    : QObject{parent}
    , context(context)
{

}

DownloadManger::~DownloadManger() {

}
