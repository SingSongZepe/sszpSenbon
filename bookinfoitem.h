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
    explicit BookInfoItem(QWidget *parent = nullptr, MainWindow* context = nullptr);
    ~BookInfoItem();

    bool set_book_info(const BookInfo& book_info);

public:
    bool eventFilter(QObject* obj, QEvent* event);
    void install_event_filter();

public:
    Ui::BookInfoItem *ui;
    MainWindow* context;
    QString href;
};

#endif // BOOKINFOITEM_H
