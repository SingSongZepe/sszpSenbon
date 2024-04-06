#ifndef SEARCHHISTORYVIEWMANGER_H
#define SEARCHHISTORYVIEWMANGER_H

#include <QObject>
#include <QWidget>

#include "singsongzepe.h"
#include "object/searchhistory.h"
#include "wgt/searchhistoryitem.h"

class MainWindow;

class SearchHistoryViewManger : public QObject
{
    Q_OBJECT
public:
    explicit SearchHistoryViewManger(MainWindow* context, QObject *parent = nullptr);
    ~SearchHistoryViewManger();

    void append_item(SearchHistory& search_history);
    void append_items(QList<SearchHistory>& shs);
    void update_wgt_search_history_size();

    // delete item in database and delete it in view
    void delete_item(int idx);
    void delete_all();

    // return
    static QPoint get_position_by_idx(int idx);

public:
    MainWindow* context;
    QWidget* wgt_search_history;
    QList<SearchHistoryItem*>* sh_items; // sh_item are newed
    int sh_items_size;

signals:
};

#endif // SEARCHHISTORYVIEWMANGER_H
