#include "search.h"

#include <QDebug>

// strings
const QString SearchConstants::GENERAL_SEARCH = "General";
const QString SearchConstants::FULLTEXT_SEARCH = "Fulltext";

GeneralSearch::GeneralSearch(QString search_type,
                             QString key_word,
                             bool exact_matching,
                             int year_from,
                             int year_to,
                             QList<QString> languages,
                             QList<QString> extensions)
    : search_type(search_type)
    , key_word(key_word)
    , exact_matching(exact_matching)
    , year_from(year_from)
    , year_to(year_to)
    , languages(languages)
    , extensions(extensions)
{

}

GeneralSearch::~GeneralSearch() {

}

FulltextSearch::FulltextSearch(QString search_type,
                               QString key_word,
                               bool exact_matching,
                               int year_from,
                               int year_to,
                               QList<QString> languages,
                               QList<QString> extensions,
                               bool match_a_phrase)
    : GeneralSearch(search_type, key_word, exact_matching, year_from, year_to, languages, extensions)
    , match_a_phrase(match_a_phrase)
{

}

FulltextSearch::~FulltextSearch() {
    // data will be released in disconstructing function of Class GS
    qDebug() << "1";
}

SingleBookSearch::SingleBookSearch(const QString& url)
    : url(url)
{

}

SingleBookSearch::~SingleBookSearch()
{

}
