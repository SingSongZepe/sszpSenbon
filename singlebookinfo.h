#ifndef SINGLEBOOKINFO_H
#define SINGLEBOOKINFO_H

#include <QWidget>

namespace Ui {
class SingleBookInfo;
}

class SingleBookInfo : public QWidget
{
    Q_OBJECT

public:
    explicit SingleBookInfo(QWidget *parent = nullptr);
    ~SingleBookInfo();

private:
    Ui::SingleBookInfo *ui;
};

#endif // SINGLEBOOKINFO_H
