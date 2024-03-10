#include "singsongzepe.h"

SingSongZepe::SingSongZepe()
{

}

SingSongZepe::~SingSongZepe()
{

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

const QString SingSongZepe::sslog = "SingSongLog: ";
const QString SingSongZepe::SINGSONGZEPE_ = "SingSongZepe";

// project name
const QString SingSongZepe::SSZPSENBON_ = "sszpSenbon";

// web info
const QString SingSongZepe::zlibrary_url = "https://z-library.se/";
// https://z-library.se/s/?q=book_name&e=1
const QString SingSongZepe::subfix_general = "s/?";
// https://z-library.se/fulltext/?q=HelloWorld&type=phrase
const QString SingSongZepe::subfix_fulltext = "fulltext/?";

// book parse
const QString SingSongZepe::BOOK_RESULT_PARSE_FILE = "book_result_parse.py";

// utils for constructing of book_infos
const QString SingSongZepe::URL_ = "url";
const QString SingSongZepe::COVER_ = "cover";
const QString SingSongZepe::TITLE_ = "title";
const QString SingSongZepe::PUBLISHER_ = "publisher";
const QString SingSongZepe::AUTHORS_ = "authors";
const QString SingSongZepe::FILE_INFO_ = "file_info";
const QString SingSongZepe::LANGUAGE_ = "language";
const QString SingSongZepe::RATING_ = "rating";

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
const QString SingSongZepe::PYTHON_SEARCH_SINGLE_BOOK_PARSE = "search_single_book_parse";
const QString SingSongZepe::FUNCTION_SEARCH_SINGLE_BOOK_PARSE = "search_single_book_parse";

