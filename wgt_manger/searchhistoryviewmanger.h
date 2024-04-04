#ifndef SEARCHHISTORYVIEWMANGER_H
#define SEARCHHISTORYVIEWMANGER_H

#include <QObject>
#include <QWidget>

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

public:
    MainWindow* context;
    QWidget* wgt_search_history;
    QList<SearchHistoryItem*>* sh_items;
    int sh_items_size;

signals:
};

#endif // SEARCHHISTORYVIEWMANGER_H
