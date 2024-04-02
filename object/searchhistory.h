#ifndef SEARCHHISTORY_H
#define SEARCHHISTORY_H

#include "search.h"

#include <QString>
#include <QList>

class SearchHistory
{
public:
    template <typename SEARCH>
    SearchHistory(const SEARCH& search);
    template <typename SEARCH>
    SearchHistory(const SEARCH& search, const QString& time, const QString& id);
    SearchHistory();
    ~SearchHistory();

    static const QString generate_id();

public:
    const QString search_type;
    const QString key_word;
    bool exact_matching;
    int year_from;
    int year_to;
    const QList<QString> languages;
    const QList<QString> extensions;
    bool match_a_phrase;
    const QString time; // show when requests
    const QString id;   // the indentifier 32 length
};

#endif // SEARCHHISTORY_H
