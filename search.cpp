#include "search.h"

// strings
const QString SearchConstants::GENERAL_SEARCH_ = "general";
const QString SearchConstants::FULLTEXT_SEARCH_ = "fulltext";

GeneralSearch::GeneralSearch(QString* search_type,
                             QString* key_word,
                             bool exact_matching,
                             int year_from,
                             int year_to,
                             QList<QString>* languages,
                             QList<QString>* extensions) {
    this->search_type = search_type;
    this->key_word = key_word;
    this->exact_matching = exact_matching;
    this->year_from = year_from;
    this->year_to = year_to;
    this->languages = languages;
    this->extensions = extensions;
}

GeneralSearch::~GeneralSearch() {
    delete search_type;
    delete key_word;
    // if (search_type != nullptr) {
    //     delete search_type;
    // }
    // if (key_word != nullptr) {
    //     delete key_word;
    // }
    if (languages != nullptr) {
        delete languages;
    }
    if (extensions != nullptr) {
        delete extensions;
    }
}

FulltextSearch::FulltextSearch(QString* search_type,
                               QString* key_word,
                               bool exact_matching,
                               int year_from,
                               int year_to,
                               QList<QString>* languages,
                               QList<QString>* extensions,
                               bool match_a_phrase): GeneralSearch(search_type, key_word, exact_matching, year_from, year_to, languages, extensions) {
    this->match_a_phrase = match_a_phrase;
}

FulltextSearch::~FulltextSearch() {
    // data will be released in disconstructing function of Class GS
}