#ifndef DOWNLOADHISTORYITEM_H
#define DOWNLOADHISTORYITEM_H

#include "object/downloadhistory.h"
#include "singsongzepe.h"

#include <QWidget>

class DownloadHistoryViewManger;

namespace Ui {
class DownloadHistoryItem;
}

class DownloadHistoryItem : public QWidget
{
    Q_OBJECT

public:
    explicit DownloadHistoryItem(DownloadHistoryViewManger* dhv_manger, QWidget *parent = nullptr, int idx = 0);
    ~DownloadHistoryItem();

    bool eventFilter(QObject *obj, QEvent *event);

    void set_download_history_info(const DownloadHistory& download_history);

    void redownload();

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
    Ui::DownloadHistoryItem *ui;
    DownloadHistoryViewManger* dhv_manger;
    DownloadHistory download_history;

    // when call delete_item of shv_manger
    // pass this idx to shv_manger
    QString id;
    int idx;
};

#endif // DOWNLOADHISTORYITEM_H
