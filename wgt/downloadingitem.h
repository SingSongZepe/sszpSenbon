#ifndef DOWNLOADINGITEM_H
#define DOWNLOADINGITEM_H

#include "object/download.h"

#include <QWidget>

namespace Ui {
class DownloadingItem;
}

class DownloadingItem : public QWidget
{
    Q_OBJECT

public:
    explicit DownloadingItem(Download d, QWidget *parent = nullptr);
    ~DownloadingItem();

private:
    Ui::DownloadingItem *ui;
    Download d;
};

#endif // DOWNLOADINGITEM_H
