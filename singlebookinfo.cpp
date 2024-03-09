#include "singlebookinfo.h"
#include "ui_singlebookinfo.h"

SingleBookInfo::SingleBookInfo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SingleBookInfo)
{
    ui->setupUi(this);
}

SingleBookInfo::~SingleBookInfo()
{
    delete ui;
}
