#include "searchhistory.h"

#include "sslog.h"

#include <QDateTime>
#include <QCryptographicHash>

// specifizition for GeneralSearch
template <>
SearchHistory::SearchHistory(const GeneralSearch& search)
    : search_type(search.search_type)
    , key_word(search.key_word)
    , exact_matching(search.exact_matching)
    , year_from(search.year_from)
    , year_to(search.year_to)
    , languages(search.languages)
    , extensions(search.extensions)
    , match_a_phrase(false)
    , time(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm"))
    , id(generate_id())
{
}

// specifizition for FulltextSearch
template <>
SearchHistory::SearchHistory(const FulltextSearch& search)
    : search_type(search.search_type)
    , key_word(search.key_word)
    , exact_matching(search.exact_matching)
    , year_from(search.year_from)
    , year_to(search.year_to)
    , languages(search.languages)
    , extensions(search.extensions)
    , match_a_phrase(search.match_a_phrase)
    , time(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm"))
    , id(generate_id())
{
}

// with time and id
template <>
SearchHistory::SearchHistory(const GeneralSearch& search, const QString& time, const QString& id)
    : search_type(search.search_type)
    , key_word(search.key_word)
    , exact_matching(search.exact_matching)
    , year_from(search.year_from)
    , year_to(search.year_to)
    , languages(search.languages)
    , extensions(search.extensions)
    , match_a_phrase(false)
    , time(time)
    , id(id)
{
}

// with time and id
template <>
SearchHistory::SearchHistory(const FulltextSearch& search, const QString& time, const QString& id)
    : search_type(search.search_type)
    , key_word(search.key_word)
    , exact_matching(search.exact_matching)
    , year_from(search.year_from)
    , year_to(search.year_to)
    , languages(search.languages)
    , extensions(search.extensions)
    , match_a_phrase(search.match_a_phrase)
    , time(time)
    , id(id)
{
}

const QString SearchHistory::generate_id() {
    QByteArray time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm").toUtf8();
    time.append(QByteArray::number(rand()));
    QByteArray hash = QCryptographicHash::hash(time, QCryptographicHash::Md5);

    QString hex_string = QString::fromLatin1(hash.toHex());

    QString id;
    for (int i = 0; i < 32; ++i) {
        id += hex_string.at(i % hex_string.length());
    }

    return id;
}

SearchHistory::SearchHistory() {

}

SearchHistory::~SearchHistory() {

}
