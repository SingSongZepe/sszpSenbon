#include "book_info_item.h"
#include "ui_book_info_item.h"

book_info_item::book_info_item(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::book_info_item)
{
    ui->setupUi(this);
}

book_info_item::~book_info_item()
{
    delete ui;
}
