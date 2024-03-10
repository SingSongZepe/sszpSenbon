#include "bookinfoitem.h"
#include "ui_bookinfoitem.h"
#include "mainwindow.h"

#include "sslog.h"
#include "worker.h"

#include <QThread>

BookInfoItem::BookInfoItem(QWidget *parent, MainWindow* context)
    : QWidget(parent)
    , ui(new Ui::BookInfoItem)
    , context(context)
{
    ui->setupUi(this);
}

void BookInfoItem::install_event_filter() {
    // lb_book_cover
    ui->lb_book_cover->blockSignals(true);
    ui->lb_book_cover->installEventFilter(this);
    ui->lb_book_cover->blockSignals(false);
}

bool BookInfoItem::set_book_info(const BookInfo& book_info) {
    this->href = book_info.href;

    ui->tb_book_title->setText(book_info.title);
    ui->tb_book_publisher->setText(book_info.publisher);
    ui->tb_book_authors->setText(book_info.authors);
    ui->lb_book_ratiing->setText(book_info.rating);
    // set sub info file_info language
    ui->lb_book_file_info->setText(book_info.file_info);
    ui->lb_book_language->setText(book_info.language);
    // set picture for lb_cover
    // if (!MainWindow::set_label_pixmap(ui->lb_book_cover, MainWindow::load_picture(book_info.cover))) {
    //     SSLog::le("error while setting picture of lb_cover");
    // }

    Worker::work_now([&](){
        MainWindow::set_label_pixmap(ui->lb_book_cover, MainWindow::load_picture(book_info.cover));
    });

    return true;
}

bool BookInfoItem::eventFilter(QObject* obj, QEvent* event) {
    if (obj == ui->lb_book_cover && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);
        if (mouse_event) {
            if (mouse_event->button() == Qt::LeftButton) {
                this->context->toggle_view(SingSongZepe::SingleBookView);
                this->context->search_singlebook_launch(this->href);

                return true;
            }
        }
    }
    return BookInfoItem::eventFilter(obj, event);
}

BookInfoItem::~BookInfoItem()
{
    delete ui;
}
