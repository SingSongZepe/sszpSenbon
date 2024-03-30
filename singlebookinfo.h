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

    // utils
    QPoint get_position_by_index(int xidx, int ydix) const;

public:
    bool eventFilter(QObject* obj, QEvent* event);

public:
    // width and height
    static const int SUB_INFO_LABEL_WIDTH_DEFAULT;  // if resized, this value will be changed
    static const int SUB_INFO_WIDTH_DEFAULT;
    static const int SUB_INFO_HEIGHT_DEFAULT;
    static const int SUB_INFO_HEIGHT_CATEGORIES; // exclude Categories

    // position
    static const int POSITION_OFFSET_X_DEFAULT_1; // 1 column
    static const int POSITION_OFFSET_X_DEFAULT_2; // 2 column
    static const int POSITION_OFFSET_Y_DEFAULT;
    static const int PADDING_BETWEEN_LABEL_VALUE;

    // SECTION_VALUE_DEFAULT
    static const QString SECTION_VALUE_DEFAULT;
    static const QString DESCRIPTION_UNKNOWN;

private:
    Ui::SingleBookInfo *ui; // new
    MainWindow* context;
    BookFullInfo book_full_info; // url for downloading book directly
    QScrollBar* sb_sa_singlebookinfo_sub_info; // new
    QWidget* wgt_sub_info_showing;
    // there the lbs_sub_info is unneccessary, because of
    // while delete wgt_sub_info_showing, all lbs (newed) will be deleted.
    // QList<QLabel*> lbs_sub_info; // store sub info and then release them
};

#endif // SINGLEBOOKINFO_H
