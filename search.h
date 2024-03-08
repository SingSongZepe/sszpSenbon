#ifndef SEARCH_H
#define SEARCH_H

#include <QString>
#include <QList>

class GeneralSearch
{
public:
    GeneralSearch(QString* search_type,
                  QString* key_word,
                  bool exact_matching=false,
                  int year_from=NULL,
                  int year_to=NULL,
                  QList<QString>* languages=nullptr,
                  QList<QString>* extensions=nullptr);
    ~GeneralSearch();

public:
    QString* search_type;
    QString* key_word;
    bool exact_matching;
    int year_from;
    int year_to;
    QList<QString>* languages;
    QList<QString>* extensions;
};

class FulltextSearch : public GeneralSearch
{
public:
    FulltextSearch(QString* search_type,
                   QString* key_word,
                   bool exact_matching=false,
                   int year_from=NULL,
                   int year_to=NULL,
                   QList<QString>* languages=nullptr,
                   QList<QString>* extensions=nullptr,
                   bool match_a_phrase=true);
    ~FulltextSearch();
public:
    bool match_a_phrase;
    // bool match_words
    // match_words == !match_a_phrase
};

class SearchConstants
{
public:
    static const QString GENERAL_SEARCH_;
    static const QString FULLTEXT_SEARCH_;
};

#endif // SEARCH_H
