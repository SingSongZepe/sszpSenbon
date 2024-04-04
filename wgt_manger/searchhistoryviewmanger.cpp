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
    SearchHistoryItem* sh_item = new SearchHistoryItem(this, this->wgt_search_history);
    this->sh_items->append(sh_item);
    this->sh_items_size++;
    sh_item->set_search_history_info(search_history);
    // sh_item.setGeometry(0, MainWindow::get_book_items_pos_y_by_index(idx), SingSongZepe::SINGLE_BOOK_ITEM_WIDTH_DEFULT, SingSongZepe::SINGLE_BOOK_ITEM_HEIGHT);

}

void SearchHistoryViewManger::append_items(SearchHistory& search_history) {

}




