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
    enum ToggleViewHistoryKind {
        SearchHistory,
        DownloadHistory,
    };

public:
    SingSongZepe();
    ~SingSongZepe();

    static int transfrom_viewkind2idx(SingSongZepe::ToggleViewKind tvk);
    static SingSongZepe::ToggleViewKind transfrom_idx2viewkind(int idx);
    static SingSongZepe::ToggleViewHistoryKind transfrom_idx2viewhistorykind(int idx);

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
    static const QString DB_FILE_PATH_SEARCH_HISTORY;
    static const QString DB_FILE_PATH_DOWNLOAD_HISTORY;
    static const QString DB_KIND;
        // sql
        // not need to specialize
    static const QString CHECK_TABLE_EXISTANCE_SQL;
    static const QString CREATE_TABLE_SQL;
    static const QString DELETE_ITEM_BY_ID_SQL;
    static const QString SEARCH_ITEM_BY_ID_SQL; // but this value, where use it, the function need to specialize, but it self not need to
    static const QString SEARCH_ALL_SQL;
        // specialize
    static const QString INSERT_SEARCH_HISTORY_ITEM_SQL;
    static const QString UPDATE_SEARCH_HISTORY_ITEM_SQL;
        // table name
    static const QString TABLE_SEARCH_HISTORY_NAME;
    static const QString TABLE_DOWNLOAD_HISTORY_NAME;
        // table parameter (you can get it by table_name)
    static const QString TABLE_PARAMETER_SEARCH_HISTORY;
    static const QString TABLE_PATAMETER_DOWNLOAD_HISTORY;

public:
    static const QString& get_table_parameter(const QString& table_name);
};

#endif // SINGSONGZEPE_H
