#include "downloadhistoryviewmanger.h"

#include "mainwindow.h"
// #include <QList>

DownloadHistoryViewManger::DownloadHistoryViewManger(MainWindow* context, QObject *parent)
    : QObject{parent}
    , context(context)
{
    this->wgt_download_history = context->get_ptr_wgt_download_history();
    this->dh_items = new QList<DownloadHistoryItem*>();
    this->dh_items_size = 0;
}

DownloadHistoryViewManger::~DownloadHistoryViewManger() {
    delete dh_items;
}

void DownloadHistoryViewManger::append_item(const DownloadHistory& downlaod_history) {
    DownloadHistoryItem* dh_item = new DownloadHistoryItem(this, this->wgt_download_history, this->dh_items_size);
    dh_item->set_download_history_info(downlaod_history);
    dh_item->move(DownloadHistoryViewManger::get_position_by_idx(this->dh_items_size));

    this->dh_items->append(dh_item);
    this->dh_items_size++;
    this->update_wgt_download_history_size();
    qDebug() << "append";
}

// call append_item for many times, so it is not need to autoincrement(sh_items_size)
void DownloadHistoryViewManger::append_items(const QList<DownloadHistory>& dhs) {
    for (const DownloadHistory& dh : dhs) {
        this->append_item(dh);
    }
}

// delete item in database and delete it in view
void DownloadHistoryViewManger::delete_item(int idx) {
    // delete it from database
    this->context->get_ptr_dbm_history_download()->delete_item_by_id(this->dh_items->at(idx)->get_id());

    // delete it from wgt
    delete this->dh_items->at(idx);
    this->dh_items->removeAt(idx);

    // new size
    this->dh_items_size = this->dh_items->size();
    for (int i = idx; i < this->dh_items_size; i++) {
        // move up
        DownloadHistoryItem* dh_item = this->dh_items->at(i);
        dh_item->move(this->get_position_by_idx(i));
        dh_item->set_idx(i);
    }
}

void DownloadHistoryViewManger::delete_all() {

}

// from 0
QPoint DownloadHistoryViewManger::get_position_by_idx(int idx) {
    return QPoint(0, SingSongZepe::HEIGHT_DOWNLOAD_HISTORY_ITEM * idx);
}

void DownloadHistoryViewManger::update_wgt_download_history_size() {
    this->wgt_download_history->setFixedSize(this->wgt_download_history->size().width(), SingSongZepe::HEIGHT_DOWNLOAD_HISTORY_ITEM * this->dh_items_size);
}
