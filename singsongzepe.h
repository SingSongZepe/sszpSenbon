#ifndef SINGSONGZEPE_H
#define SINGSONGZEPE_H

#include <QString>

class SingSongZepe
{
// enum
public:
    enum ToggleViewKind {
        Search,
        SingleBookView,
        History,
        Setting,
        Todo,
    };
public:
    SingSongZepe();
    ~SingSongZepe();

    static const QString sslog;
    static const QString SINGSONGZEPE_;

    //project name
    static const QString SSZPSENBON_;

    // web info
    static const QString zlibrary_url;
    static const QString subfix_general;
    static const QString subfix_fulltext;

    // html parse for book
    static const QString BOOK_RESULT_PARSE_FILE;

    // utils for constructing of book_infos
    static const QString URL_;
    static const QString COVER_;
    static const QString TITLE_;
    static const QString PUBLISHER_;
    static const QString AUTHORS_;
    static const QString FILE_INFO_;
    static const QString LANGUAGE_;
    static const QString RATING_;

    // for wgt_book_items size
    static const int WGT_BOOK_ITEMS_X;
    static const int WGT_BOOK_ITEMS_Y;
    static const int SINGLE_BOOK_ITEM_WIDTH_DEFULT;
    static const int SINGLE_BOOK_ITEM_HEIGHT;
    static const int BOOK_ITEM_MARGIN;

    // for sa_books scrollbar
    static const QString STYLE_SCROLLBAR_SLIM_TRANSPARENT;

    // for request time out
    static const int TIME_REQUEST_TIMER_OUT;

};

#endif // SINGSONGZEPE_H
