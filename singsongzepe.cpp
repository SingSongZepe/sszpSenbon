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
