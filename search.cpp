#include "search.h"

// strings
const QString SearchConstants::GENERAL_SEARCH = "General";
const QString SearchConstants::FULLTEXT_SEARCH = "Fulltext";

GeneralSearch::GeneralSearch(const QString& search_type,
                             const QString& key_word,
                             bool exact_matching,
                             int year_from,
                             int year_to,
                             const QList<QString>& languages,
                             const QList<QString>& extensions)
    :
    search_type(search_type),
    key_word(key_word),
    exact_matching(exact_matching),
    year_from(year_from),
    year_to(year_to),
    languages(languages),
    extensions(extensions)
{

}

GeneralSearch::~GeneralSearch() {

}

FulltextSearch::FulltextSearch(const QString& search_type,
                               const QString& key_word,
                               bool exact_matching,
                               int year_from,
                               int year_to,
                               const QList<QString>& languages,
                               const QList<QString>& extensions,
                               bool match_a_phrase)
    :
    GeneralSearch(search_type, key_word, exact_matching, year_from, year_to, languages, extensions),
    match_a_phrase(match_a_phrase)
{

}

FulltextSearch::~FulltextSearch() {
    // data will be released in disconstructing function of Class GS
}
