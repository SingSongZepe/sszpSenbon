#include "databasemanger.h"

#include "sslog.h"
#include "singsongzepe.h"
#include "object/searchhistory.h"

#include <QFile>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

DatabaseManger::DatabaseManger(const QString& db_file_path, const QString& table_name, QObject *parent)
    : QObject{parent}
{
    db = QSqlDatabase::addDatabase(SingSongZepe::DB_KIND); // sqlite
    // // check database exists
    // if (!QFile::exists(db_file_path)) {
    //     SSLog::lw("database file lost, attempting to create one");
    // }

    db.setDatabaseName(db_file_path);
    SSLog::ln("database created successfully");

    // check open
    if (!db.open()) {
        SSLog::le("can't open sqlite database");
        return;
    }
    SSLog::ln("database opened successfully");

    // check table existance
    QSqlQuery query(db);
    query.exec(SingSongZepe::CHECK_TABLE_EXISTANCE_SQL.arg(table_name));

    if (query.next()) {
        SSLog::ln(QString("Table %1 already exists").arg(table_name));
    } else {
        query.exec(SingSongZepe::CREATE_TABLE_SQL.arg(table_name).arg(SingSongZepe::get_table_parameter(table_name)));
        SSLog::ln(QString("Table %1 created").arg(table_name));
    }

    this->table_name = QString(table_name);
}

DatabaseManger::~DatabaseManger() {
    this->db.close();
}

// specialization for SearchHistory
template <>
bool DatabaseManger::insert_item(const SearchHistory& search_history) {
    QSqlQuery query(this->db);
    query.prepare(SingSongZepe::INSERT_SEARCH_HISTORY_ITEM_SQL);

    query.bindValue(":search_type", search_history.search_type);     // TEXT
    query.bindValue(":key_word", search_history.key_word);           // TEXT
    query.bindValue(":exact_matching", search_history.exact_matching);        // BOOL
    query.bindValue(":year_from", search_history.year_from);                  // INT
    query.bindValue(":year_to", search_history.year_to);                      // INT
    query.bindValue(":languages", search_history.languages.join(", "));
    query.bindValue(":extensions", search_history.extensions.join(", "));
    query.bindValue(":match_a_phrase", search_history.match_a_phrase);
    query.bindValue(":time", search_history.time);
    query.bindValue(":id", search_history.id);

    if (!query.exec()) {
        SSLog::le("add item failed: " + query.lastError().text());
        return false;
    }
    return true;
}

bool DatabaseManger::delete_item_by_id(const QString& id) {
    QSqlQuery query(this->db);
    query.prepare(SingSongZepe::DELETE_ITEM_BY_ID_SQL.arg(this->table_name));
    query.bindValue(":id", id);

    if (!query.exec()) {
        SSLog::le("delete item failed: " + query.lastError().text());
        return false;
    }
    return true;
}

template <>
bool DatabaseManger::update_item(const SearchHistory& search_history, const QString& id) {
    QSqlQuery query(this->db);
    query.prepare(SingSongZepe::UPDATE_SEARCH_HISTORY_ITEM_SQL);

    query.bindValue(":search_type", search_history.search_type);
    query.bindValue(":key_word", search_history.key_word);
    query.bindValue(":exact_matching", search_history.exact_matching);
    query.bindValue(":year_from", search_history.year_from);
    query.bindValue(":year_to", search_history.year_to);
    query.bindValue(":languages", search_history.languages.join(", "));
    query.bindValue(":extensions", search_history.extensions.join(", "));
    query.bindValue(":match_a_phrase", search_history.match_a_phrase);
    query.bindValue(":time", search_history.time);
    query.bindValue(":id", id);

    if (!query.exec()) {
        SSLog::le("update item failed: " + query.lastError().text());
        return false;
    }
    return true;
}

template <>
SearchHistory DatabaseManger::search_by_id(const QString& id) {
    QSqlQuery query(this->db);
    query.prepare(SingSongZepe::SEARCH_ITEM_BY_ID_SQL.arg(this->table_name));
    query.bindValue(":id", id);

    if (!query.exec() || !query.first()) {
        SSLog::lw("search item failed: " + query.lastError().text());
        return SearchHistory{}; // return an empty SearchHistory object
    }

    if (query.value("search_type").toString() == SearchConstants::GENERAL_SEARCH) {
        return SearchHistory(GeneralSearch(
                                 query.value("search_type").toString(),
                                 query.value("key_word").toString(),
                                 query.value("exact_matching").toBool(),
                                 query.value("year_from").toInt(),
                                 query.value("year_to").toInt(),
                                 query.value("languages").toString().split(", "),
                                 query.value("extensions").toString().split(", ")
                             ),
                             query.value("time").toString(),
                             query.value("id").toString()
                             );
    }
    else {
        return SearchHistory(FulltextSearch(
                                 query.value("search_type").toString(),
                                 query.value("key_word").toString(),
                                 query.value("exact_matching").toBool(),
                                 query.value("year_from").toInt(),
                                 query.value("year_to").toInt(),
                                 query.value("languages").toString().split(", "),
                                 query.value("extensions").toString().split(", "),
                                 query.value("match_a_phrase").toBool()
                             ),
                             query.value("time").toString(),
                             query.value("id").toString()
                             );
    }

}

template <>
QList<SearchHistory> DatabaseManger::search_all()
{
    QList<SearchHistory> searches;

    QSqlQuery query(db);
    query.prepare(SingSongZepe::SEARCH_ALL_SQL.arg(this->table_name));

    if (!query.exec()) {
        SSLog::le("Failed to execute query");
        SSLog::le("Error: " + query.lastError().text());
        return searches;
    }

    while (query.next()) {
        QString search_type = query.value("search_type").toString();
        QString key_word = query.value("key_word").toString();

        QString id = query.value("id").toString();

        if (search_type == SearchConstants::GENERAL_SEARCH) {
            searches.append(SearchHistory(GeneralSearch(
                                            query.value("search_type").toString(),
                                            query.value("key_word").toString(),
                                            query.value("exact_matching").toBool(),
                                            query.value("year_from").toInt(),
                                            query.value("year_to").toInt(),
                                            query.value("languages").toString().split(", "),
                                            query.value("extensions").toString().split(", ")
                                        ),
                                        query.value("time").toString(),
                                        query.value("id").toString()
                                        )
                            );
        } else {
            searches.append(SearchHistory(FulltextSearch(
                                              query.value("search_type").toString(),
                                              query.value("key_word").toString(),
                                              query.value("exact_matching").toBool(),
                                              query.value("year_from").toInt(),
                                              query.value("year_to").toInt(),
                                              query.value("languages").toString().split(", "),
                                              query.value("extensions").toString().split(", "),
                                              query.value("match_a_phrase").toBool()
                                              ),
                                          query.value("time").toString(),
                                          query.value("id").toString()
                                          )
                            );
        }
    }

    return searches;
}




