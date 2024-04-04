#ifndef SEARCHHISTORYITEM_H
#define SEARCHHISTORYITEM_H

#include "object/searchhistory.h"
#include "singsongzepe.h"

#include <QWidget>

class SearchHistoryViewManger;

namespace Ui {
class SearchHistoryItem;
}

class SearchHistoryItem : public QWidget
{
    Q_OBJECT

public:
    explicit SearchHistoryItem(SearchHistoryViewManger* shv_manger, QWidget *parent = nullptr);
    ~SearchHistoryItem();

    bool eventFilter(QObject *obj, QEvent *event);

    void set_search_history_info(const SearchHistory& search_history);

private:
    Ui::SearchHistoryItem *ui;
    SearchHistoryViewManger* shv_manger;
};

#endif // SEARCHHISTORYITEM_H
