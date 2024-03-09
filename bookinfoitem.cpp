#include "bookinfoitem.h"
#include "ui_bookinfoitem.h"
#include "mainwindow.h"

#include "sslog.h"
#include "worker.h"

#include <QThread>

BookInfoItem::BookInfoItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BookInfoItem)
{
    ui->setupUi(this);
}

bool BookInfoItem::set_book_info(const BookInfo& book_info) {
    this->ui->tb_book_title->setText(book_info.title);
    this->ui->tb_book_publisher->setText(book_info.publisher);
    this->ui->tb_book_authors->setText(book_info.authors);
    this->ui->lb_book_ratiing->setText(book_info.rating);
    // set sub info file_info language
    this->ui->lb_book_file_info->setText(book_info.file_info);
    this->ui->lb_book_language->setText(book_info.language);
    // set picture for lb_cover
    // if (!MainWindow::set_label_pixmap(ui->lb_book_cover, MainWindow::load_picture(book_info.cover))) {
    //     SSLog::le("error while setting picture of lb_cover");
    // }

    Worker::work_now([&](){
        MainWindow::set_label_pixmap(ui->lb_book_cover, MainWindow::load_picture(book_info.cover));
    });

    return true;
}

BookInfoItem::~BookInfoItem()
{
    delete ui;
}
