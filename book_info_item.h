#ifndef BOOK_INFO_ITEM_H
#define BOOK_INFO_ITEM_H

#include <QWidget>

namespace Ui {
class book_info_item;
}

class book_info_item : public QWidget
{
    Q_OBJECT

public:
    explicit book_info_item(QWidget *parent = nullptr);
    ~book_info_item();

private:
    Ui::book_info_item *ui;
};

#endif // BOOK_INFO_ITEM_H
