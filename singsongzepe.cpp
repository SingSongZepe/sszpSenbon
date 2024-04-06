#include "singsongzepe.h"
#include "sslog.h"

#include <QCoreApplication>

SingSongZepe::SingSongZepe() {
}

SingSongZepe::~SingSongZepe() {
}

int SingSongZepe::transfrom_viewkind2idx(SingSongZepe::ToggleViewKind tvk) {
    switch (tvk) {
    case SingSongZepe::Search:
        return 0;
    case SingSongZepe::SingleBookView:
        return 1;
    case SingSongZepe::History:
        return 2;
    case SingSongZepe::Setting:
        return 3;
    case SingSongZepe::Todo:
        return 4;
    default:
        return 0;
    }
}

SingSongZepe::ToggleViewKind SingSongZepe::transfrom_idx2viewkind(int idx) {
    switch (idx) {
    case -1:
    case 0:
        return SingSongZepe::Search;
    case 1:
        return SingSongZepe::SingleBookView;
    case 2:
        return SingSongZepe::History;
    case 3:
        return SingSongZepe::Setting;
    case 4:
        return SingSongZepe::Todo;
    default:
        return SingSongZepe::Search;
    }
}

SingSongZepe::ToggleViewHistoryKind SingSongZepe::transfrom_idx2viewhistorykind(int idx) {
    switch (idx) {
    case -1:
    case 0:
        return SingSongZepe::SearchHistory;
    case 1:
        return SingSongZepe::DownloadHistory;
    default:
        return SingSongZepe::SearchHistory;
    }
}

const QString SingSongZepe::sslog = "SingSongLog: ";
const QString SingSongZepe::SINGSONGZEPE_ = "SingSongZepe";

// project name
const QString SingSongZepe::SSZPSENBON_ = "sszpSenbon";

// web info
const QString SingSongZepe::zlibrary_url = "https://zh.z-library.se/";
// https://z-library.se/s/?q=book_name&e=1
const QString SingSongZepe::subfix_general = "s/?";
// https://z-library.se/fulltext/?q=HelloWorld&type=phrase
const QString SingSongZepe::subfix_fulltext = "fulltext/?";

// book parse
const QString SingSongZepe::BOOK_RESULT_PARSE_FILE = "book_result_parse.py";

// utils for constructing of book_infos and book_full_info
const QString SingSongZepe::URL_ = "url";
const QString SingSongZepe::HREF_ = "href";
const QString SingSongZepe::COVER_ = "cover";
const QString SingSongZepe::TITLE_ = "title";
const QString SingSongZepe::PUBLISHER_ = "publisher";
const QString SingSongZepe::AUTHORS_ = "authors";
const QString SingSongZepe::FILE_INFO_ = "file_info";
const QString SingSongZepe::LANGUAGE_ = "language";
const QString SingSongZepe::RATING_ = "rating";

const QString SingSongZepe::DESCRIPTION_ = "description";
const QString SingSongZepe::CATEGORIES_ = "categories";
const QString SingSongZepe::EDITION_ = "edition";
const QString SingSongZepe::ISBN_ = "isbn";
const QString SingSongZepe::ISBN10_ = "isbn10";
const QString SingSongZepe::ISBN13_ = "isbn13";
const QString SingSongZepe::FILE_ = "file";
const QString SingSongZepe::VOLUME_ = "volume";
const QString SingSongZepe::YEAR_ = "year";
const QString SingSongZepe::PAGES_ = "pages";
const QString SingSongZepe::SERIES_ = "series";
const QString SingSongZepe::IPFS_ = "ipfs";

// for wgt_book_items size
const int SingSongZepe::WGT_BOOK_ITEMS_X = 10;
const int SingSongZepe::WGT_BOOK_ITEMS_Y = 10;
const int SingSongZepe::SINGLE_BOOK_ITEM_WIDTH_DEFULT = 711;
const int SingSongZepe::SINGLE_BOOK_ITEM_HEIGHT = 161;
const int SingSongZepe::BOOK_ITEM_MARGIN = 10;

// for sa_books scrollbar
const QString SingSongZepe::STYLE_SCROLLBAR_SLIM_TRANSPARENT = "QScrollBar:vertical { width: 5px; }"
                                                               "QScrollBar::handle:vertical { background: #c0c0c0; }"
                                                               "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0; }"
                                                               "QScrollBar {background-color: #ADD8E6}";

// for request time out
const int SingSongZepe::TIME_REQUEST_TIMER_OUT = 10000;

// for python script
const QString SingSongZepe::PYTHON_BOOK_RESULT_PARSE = "book_result_parse";
const QString SingSongZepe::FUNCTION_BOOK_RESULT_PARSE = "book_result_parse";
const QString SingSongZepe::PYTHON_SEARCH_SINGLE_BOOK_PARSE = "search_single_book_parse";
const QString SingSongZepe::FUNCTION_SEARCH_SINGLE_BOOK_PARSE = "search_single_book_parse";
const QString SingSongZepe::PYTHON_CHECK_COOKIE_USEFUL = "check_cookie_useful";
const QString SingSongZepe::FUNCTION_CHECK_COOKIE_USEFUL = "check_cookie_useful";

// for store file
const QString SingSongZepe::PATH_ROOT_PROJECT = "F:/QTProjects/sszpSenbon"; // the value will changed because of install path
const QString SingSongZepe::PATH_STORE_FILE_DOWNLOAD = SingSongZepe::PATH_ROOT_PROJECT + "/file/download";
const QString SingSongZepe::PATH_STORE_FILE_DATABASE = SingSongZepe::PATH_ROOT_PROJECT + "/usr/database";

// json string
const QString SingSongZepe::JSON_STR_NULL = "<NULL>";
const QString SingSongZepe::BOOK_INFO_UNKNOWN = "unknown";

// database
const QString SingSongZepe::DB_FILE_PATH_SEARCH_HISTORY = SingSongZepe::PATH_STORE_FILE_DATABASE + "/history_search.db";
const QString SingSongZepe::DB_FILE_PATH_DOWNLOAD_HISTORY = SingSongZepe::PATH_STORE_FILE_DATABASE + "/history_download.db";
const QString SingSongZepe::DB_KIND = "QSQLITE";

    // not need to specialize
const QString SingSongZepe::CHECK_TABLE_EXISTANCE_SQL = "SELECT name FROM sqlite_master WHERE type='table' AND name='%1'";
const QString SingSongZepe::CREATE_TABLE_SQL = "CREATE TABLE %1 (%2)";
const QString SingSongZepe::DELETE_ITEM_BY_ID_SQL = "DELETE FROM %1 WHERE id = :id";
const QString SingSongZepe::SEARCH_ITEM_BY_ID_SQL = "SELECT * FROM %1 WHERE id = :id";
const QString SingSongZepe::SEARCH_ALL_SQL = "SELECT * FROM %1";
    // need to specialize
const QString SingSongZepe::INSERT_SEARCH_HISTORY_ITEM_SQL = "INSERT INTO search_history ("
                                                             "search_type, key_word, exact_matching, year_from, year_to, languages, extensions, match_a_phrase, time, id"
                                                             ") "
                                                             "VALUES ("
                                                             ":search_type, :key_word, :exact_matching, :year_from, :year_to, :languages, :extensions, :match_a_phrase, :time, :id"
                                                             ")";
const QString SingSongZepe::UPDATE_SEARCH_HISTORY_ITEM_SQL = "UPDATE search_history SET search_type = :search_type, key_word = :key_word, exact_matching = :exact_matching, year_from = :year_from, year_to = :year_to, languages = :languages, extensions = :extensions, match_a_phrase = :match_a_phrase, time = :time WHERE id = :id";

    // table name
const QString SingSongZepe::TABLE_SEARCH_HISTORY_NAME = "search_history";
const QString SingSongZepe::TABLE_DOWNLOAD_HISTORY_NAME = "download_history";

const QString SingSongZepe::TABLE_PARAMETER_SEARCH_HISTORY = "search_type TEXT, key_word TEXT, exact_matching INTEGER, year_from INTEGER, year_to INTEGER,"
                                                             "languages TEXT, extensions TEXT, match_a_phrase INTEGER, time TEXT, id TEXT";
const QString SingSongZepe::TABLE_PATAMETER_DOWNLOAD_HISTORY = "";

const QString& SingSongZepe::get_table_parameter(const QString& table_name) {
    if (table_name == SingSongZepe::TABLE_SEARCH_HISTORY_NAME) {
        return SingSongZepe::TABLE_PARAMETER_SEARCH_HISTORY;
    } else if (table_name == SingSongZepe::TABLE_DOWNLOAD_HISTORY_NAME) {
        return SingSongZepe::TABLE_PATAMETER_DOWNLOAD_HISTORY;
    }
    else {
        SSLog::lw("this table_name is not found");
        return SingSongZepe::TABLE_PARAMETER_SEARCH_HISTORY;
    }
}


// ////// VALUE
// size of search_history_item
const int SingSongZepe::WIDTH_SEARCH_HISTORY_ITEM_DEFAULT = 741;
const int SingSongZepe::HEIGHT_SEARCH_HISTORY_ITEM = 111;

