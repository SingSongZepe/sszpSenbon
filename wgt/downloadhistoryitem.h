#ifndef DOWNLOADHISTORYITEM_H
#define DOWNLOADHISTORYITEM_H

#include <QWidget>

namespace Ui {
class DownloadHistoryItem;
}

class DownloadHistoryItem : public QWidget
{
    Q_OBJECT

public:
    explicit DownloadHistoryItem(QWidget *parent = nullptr);
    ~DownloadHistoryItem();

private:
    Ui::DownloadHistoryItem *ui;
};

#endif // DOWNLOADHISTORYITEM_H
