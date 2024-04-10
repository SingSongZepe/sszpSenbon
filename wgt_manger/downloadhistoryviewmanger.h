#ifndef DOWNLOADHISTORYVIEWMANGER_H
#define DOWNLOADHISTORYVIEWMANGER_H

#include <QObject>
#include "singsongzepe.h"
#include "object/downloadhistory.h"
#include "wgt/downloadhistoryitem.h"

class MainWindow;

class DownloadHistoryViewManger : public QObject
{
    Q_OBJECT
public:
    explicit DownloadHistoryViewManger(MainWindow* context, QObject *parent = nullptr);
    ~DownloadHistoryViewManger();

    void append_item(Download& search_history);
    void append_items(QList<SearchHistory>& shs);
    void update_wgt_search_history_size();

    // delete item in database and delete it in view
    void delete_item(int idx);
    void delete_all();

    // return
    static QPoint get_position_by_idx(int idx);

public:
    MainWindow* context;
    QWidget* wgt_download_history;
    QList<DownloadHistoryItem*>* dh_items; // sh_item are newed
    int dh_items_size;

signals:
};

#endif // DOWNLOADHISTORYVIEWMANGER_H
