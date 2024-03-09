#include "singsongzepe.h"

SingSongZepe::SingSongZepe()
{

}

SingSongZepe::~SingSongZepe()
{

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
