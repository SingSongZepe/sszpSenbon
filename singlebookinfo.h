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

public:
    bool eventFilter(QObject* obj, QEvent* event);

private:
    Ui::SingleBookInfo *ui;
    MainWindow* context;
};

#endif // SINGLEBOOKINFO_H
