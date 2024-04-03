#ifndef SEARCH_H
#define SEARCH_H

#include <QString>
#include <QList>

class GeneralSearch
{
public:
    GeneralSearch(QString search_type,
                  QString key_word,
                  bool exact_matching=false,
                  int year_from=-1,
                  int year_to=-1,
                  QList<QString> languages=QList<QString>(),
                  QList<QString> extensions=QList<QString>());
    ~GeneralSearch();

public:
    QString search_type;
    QString key_word;
    bool exact_matching;
    int year_from;
    int year_to;
    QList<QString> languages;
    QList<QString> extensions;
};

class FulltextSearch : public GeneralSearch
{
public:
    FulltextSearch(QString search_type,
                   QString key_word,
                   bool exact_matching=false,
                   int year_from=-1,
                   int year_to=-1,
                   QList<QString> languages=QList<QString>(),
                   QList<QString> extensions=QList<QString>(),
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
    static const QString GENERAL_SEARCH;
    static const QString FULLTEXT_SEARCH;
};

class SingleBookSearch
{
public:
    QString url;
public:
    explicit SingleBookSearch(const QString& url);
    ~SingleBookSearch();
};

#endif // SEARCH_H
