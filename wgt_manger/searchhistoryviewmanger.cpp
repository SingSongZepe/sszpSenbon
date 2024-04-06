#include "searchhistoryviewmanger.h"

#include "mainwindow.h"

SearchHistoryViewManger::SearchHistoryViewManger(MainWindow* context, QObject *parent)
    : QObject{parent}
    , context(context)
{
    // this->context->print_hello(true);
    this->wgt_search_history = context->get_ptr_wgt_search_history();
    this->sh_items = new QList<SearchHistoryItem*>();
    this->sh_items_size = 0;

    // test for showing
    // this->wgt_search_history->setFixedSize(QSize(741, 500));
    // SearchHistory sh = this->context->get_ptr_dbm_history_search()->search_by_id<SearchHistory>("3e254f87085fc614addcbfd97e7b76b2");
    // this->append_item(sh);
}

SearchHistoryViewManger::~SearchHistoryViewManger() {
    delete sh_items;
}

void SearchHistoryViewManger::append_item(SearchHistory& search_history) {
    SearchHistoryItem* sh_item = new SearchHistoryItem(this, this->wgt_search_history, this->sh_items_size);
    sh_item->set_search_history_info(search_history);
    sh_item->move(SearchHistoryViewManger::get_position_by_idx(this->sh_items_size));

    this->sh_items->append(sh_item);
    this->sh_items_size++;
    this->update_wgt_search_history_size();
    qDebug() << "append";
}

// call append_item for many times, so it is not need to autoincrement(sh_items_size)
void SearchHistoryViewManger::append_items(QList<SearchHistory>& shs) {
    for (SearchHistory& sh : shs) {
        this->append_item(sh);
    }
}

// delete item in database and delete it in view
void SearchHistoryViewManger::delete_item(int idx) {
    // delete it from database
    this->context->get_ptr_dbm_history_search()->delete_item_by_id(this->sh_items->at(idx)->get_id());

    // delete it from wgt
    delete this->sh_items->at(idx);
    this->sh_items->removeAt(idx);

    // new size
    this->sh_items_size = this->sh_items->size();
    for (int i = idx; i < this->sh_items_size; i++) {
        // move up
        SearchHistoryItem* sh_item = this->sh_items->at(i);
        sh_item->move(this->get_position_by_idx(i));
        sh_item->set_idx(i);
    }
}

void SearchHistoryViewManger::delete_all() {

}

// from 0
QPoint SearchHistoryViewManger::get_position_by_idx(int idx) {
    return QPoint(0, SingSongZepe::HEIGHT_SEARCH_HISTORY_ITEM * idx);
}

void SearchHistoryViewManger::update_wgt_search_history_size() {
    this->wgt_search_history->setFixedSize(this->wgt_search_history->size().width(), SingSongZepe::HEIGHT_SEARCH_HISTORY_ITEM * this->sh_items_size);
}



