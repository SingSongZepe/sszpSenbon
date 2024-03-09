#ifndef BOOKINFOITEM_H
#define BOOKINFOITEM_H

#include "mainwindow.h"
#include <QWidget>

namespace Ui
{
    class BookInfoItem;
}

class BookInfoItem : public QWidget
{
    Q_OBJECT

public:
    explicit BookInfoItem(QWidget *parent = nullptr);
    ~BookInfoItem();

    bool set_book_info(const BookInfo& book_info);

public:
    Ui::BookInfoItem *ui;   
};

#endif // BOOKINFOITEM_H
