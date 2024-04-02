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

    static int transfrom_viewkind2idx(SingSongZepe::ToggleViewKind tvk);
    static SingSongZepe::ToggleViewKind transfrom_idx2viewkind(int tvk);

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
    static const QString HREF_;
    static const QString COVER_;
    static const QString TITLE_;
    static const QString PUBLISHER_;
    static const QString AUTHORS_;
    static const QString FILE_INFO_;
    static const QString LANGUAGE_;
    static const QString RATING_;

    static const QString DESCRIPTION_;
    static const QString CATEGORIES_;
    static const QString EDITION_;
    static const QString ISBN_;
    static const QString ISBN10_;
    static const QString ISBN13_;
    static const QString FILE_;
    static const QString VOLUME_;
    static const QString YEAR_;
    static const QString PAGES_;
    static const QString SERIES_;
    static const QString IPFS_;

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

    // python
    static const QString PYTHON_BOOK_RESULT_PARSE;
    static const QString FUNCTION_BOOK_RESULT_PARSE;
    static const QString PYTHON_SEARCH_SINGLE_BOOK_PARSE;
    static const QString FUNCTION_SEARCH_SINGLE_BOOK_PARSE;
    static const QString PYTHON_CHECK_COOKIE_USEFUL;
    static const QString FUNCTION_CHECK_COOKIE_USEFUL;

    // store as file
    static const QString PATH_ROOT_PROJECT;
    static const QString PATH_STORE_FILE_DOWNLOAD;
    static const QString PATH_STORE_FILE_DATABASE;

    // json string
    static const QString JSON_STR_NULL;
    static const QString BOOK_INFO_UNKNOWN;

    // database
    static const QString DB_FILE_PATH_HISTORY_SEARCH;
    static const QString DB_FILE_PATH_HISTORY_DOWNLOAD;
    static const QString DB_KIND;

};

#endif // SINGSONGZEPE_H
