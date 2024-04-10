#include "downloadhistoryitem.h"
#include "ui_downloadhistoryitem.h"

DownloadHistoryItem::DownloadHistoryItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DownloadHistoryItem)
{
    ui->setupUi(this);
}

DownloadHistoryItem::~DownloadHistoryItem()
{
    delete ui;
}
