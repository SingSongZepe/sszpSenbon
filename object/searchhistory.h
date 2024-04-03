#ifndef SEARCHHISTORY_H
#define SEARCHHISTORY_H

#include "search.h"

#include <QString>
#include <QList>

class SearchHistory
{
public:
    // construct from search object
    template <typename SEARCH>
    SearchHistory(const SEARCH& search);

    // when load from database, we are not change its time and id to construct the object
    template <typename SEARCH>
    SearchHistory(const SEARCH& search, const QString& time, const QString& id);
    SearchHistory();
    ~SearchHistory();

    static const QString generate_id();
    static const QString generate_time();

public:
    QString search_type;
    QString key_word;
    bool exact_matching;
    int year_from;
    int year_to;
    QList<QString> languages;
    QList<QString> extensions;
    bool match_a_phrase;
    QString time; // show when requests
    QString id;   // the indentifier 32 length
};

#endif // SEARCHHISTORY_H
