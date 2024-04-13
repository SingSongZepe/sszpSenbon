#include "downloadingitem.h"
#include "ui_downloadingitem.h"

DownloadingItem::DownloadingItem(Download d, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DownloadingItem)
    , d(d)
{
    ui->setupUi(this);
}

DownloadingItem::~DownloadingItem()
{
    delete ui;
}
