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
    , time(SearchHistory::generate_time())
    , id(SearchHistory::generate_id())
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
    , time(SearchHistory::generate_time())
    , id(SearchHistory::generate_id())
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

const QString SearchHistory::generate_time() {
    return QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm");
}

QString SearchHistory::get_str_languages() const {
    if (this->languages.isEmpty()) {
        return "any";
    } return this->languages.join(", ");
}
QString SearchHistory::get_str_extensions() const {
    if (this->extensions.isEmpty()) {
        return "any";
    } return this->extensions.join(", ");
}
QString SearchHistory::get_str_require_time() const {
    if (this->year_from == -1 && this->year_to == -1) {
        return QString("any");
    } else if (this->year_from == -1) {
        return QString("to %1").arg(this->year_to);
    } else if (this->year_to == -1) {
        return QString("from %1").arg(this->year_from);
    }
    return QString("from %1 to %2").arg(this->year_from).arg(year_to);
}
QString SearchHistory::get_str_exact_matching() const {
    return this->exact_matching ? "True" : "False";
}
QString SearchHistory::get_str_match_a_phrase() const {
    return this->match_a_phrase ? "True" : "False";
}

// specifization for GeneralSearch
template <>
GeneralSearch SearchHistory::cvt_search_history() {
    return GeneralSearch(this->search_type,
                         this->key_word,
                         this->exact_matching,
                         this->year_from,
                         this->year_to,
                         this->languages,
                         this->extensions);
}

template <>
FulltextSearch SearchHistory::cvt_search_history() {
    return FulltextSearch(this->search_type,
                          this->key_word,
                          this->exact_matching,
                          this->year_from,
                          this->year_to,
                          this->languages,
                          this->extensions,
                          this->match_a_phrase);
}

SearchHistory::SearchHistory() {
}

SearchHistory::~SearchHistory() {
    // qDebug() << "sh release";
}
