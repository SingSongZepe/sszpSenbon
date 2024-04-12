#include "downloadhistoryitem.h"
#include "ui_downloadhistoryitem.h"

#include "wgt_manger/downloadhistoryviewmanger.h"
#include "worker.h"
#include "mainwindow.h"

#include <QDebug>
#include <QMouseEvent>

DownloadHistoryItem::DownloadHistoryItem(DownloadHistoryViewManger* dhv_manger, QWidget *parent, int idx)
    : QWidget(parent)
    , ui(new Ui::DownloadHistoryItem)
    , dhv_manger(dhv_manger)
    , idx(idx)
{
    ui->setupUi(this);
    
    ui->lb_delete->installEventFilter(this);
    ui->lb_redownload->installEventFilter(this);
    
}

void DownloadHistoryItem::set_download_history_info(const DownloadHistory& download_history) {
    this->download_history = download_history;
    // main info
    ui->tb_title->setText(download_history.title);
    ui->tb_authors->setText(download_history.authors);
    ui->tb_publisher->setText(download_history.publisher);
    ui->lb_rating->setText(download_history.rating);
    ui->tb_year->setText(download_history.year);
    // sub_info
    ui->lb_file->setText(download_history.file);
    ui->lb_language->setText(download_history.language);
    ui->lb_id->setText(download_history.id);
    ui->lb_id->setText(download_history.time);
    // cover
    // the cover need be copied, otherwise will be deleted
    Worker::work_now([&, cover = download_history.cover](){
        MainWindow::set_label_pixmap(ui->lb_cover, MainWindow::load_picture(cover));
    });

    this->id = download_history.id;
}

bool DownloadHistoryItem::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->lb_delete && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent) {
            if (mouseEvent->button() == Qt::LeftButton) {
                // delete (self and wgt after self)
                this->dhv_manger->delete_item(this->idx);
                return true;
            }
        }
    } else if (obj == ui->lb_redownload && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent) {
            if (mouseEvent->button() == Qt::LeftButton) {
                // delete (self and wgt after self)
                this->redownload();
                return true;
            }
        }
    }
    return false;
}

void DownloadHistoryItem::redownload() {

    return;
}

DownloadHistoryItem::~DownloadHistoryItem()
{
    delete ui;
}
