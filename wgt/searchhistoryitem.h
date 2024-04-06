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
    explicit SearchHistoryItem(SearchHistoryViewManger* shv_manger, QWidget *parent = nullptr, int idx = 0);
    ~SearchHistoryItem();

    bool eventFilter(QObject *obj, QEvent *event);

    void set_search_history_info(const SearchHistory& search_history);

    void research();

public: // get member var
    const QString& get_id() {
        return this->id;
    }
    int get_idx() {
        return this->idx;
    }
    void set_idx(int idx) {
        this->idx = idx;
    }

private:
    Ui::SearchHistoryItem *ui;
    SearchHistoryViewManger* shv_manger;
    SearchHistory search_history;

    // when call delete_item of shv_manger
    // pass this idx to shv_manger
    QString id;
    int idx;
};

#endif // SEARCHHISTORYITEM_H
