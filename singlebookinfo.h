#ifndef SINGLEBOOKINFO_H
#define SINGLEBOOKINFO_H

#include "mainwindow.h"

#include <QWidget>

namespace Ui {
class SingleBookInfo;
}

class SingleBookInfo : public QWidget
{
    Q_OBJECT

public:
    explicit SingleBookInfo(QWidget *parent = nullptr, MainWindow* context = nullptr);
    ~SingleBookInfo();

    bool set_book_full_info(const BookFullInfo& full_info);

public:
    bool eventFilter(QObject* obj, QEvent* event);

private:
    Ui::SingleBookInfo *ui; // new
    MainWindow* context;
    QString url; // url for downloading book directly
    QScrollBar* sb_sa_singlebookinfo_sub_info; // new
};

#endif // SINGLEBOOKINFO_H
