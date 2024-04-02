#include "databasemanger.h"

#include "sslog.h"
#include "singsongzepe.h"
#include "object/searchhistory.h""

#include <QFile>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

DatabaseManger::DatabaseManger(const QString& db_file_path, QObject *parent)
    : QObject{parent}
{
    // check exists
    if (!QFile::exists(db_file_path)) {
        SSLog::lw("database file lost, attempting to create one");
    }

    // connect
    db = QSqlDatabase::addDatabase(SingSongZepe::DB_KIND);
    db.setDatabaseName(db_file_path);
    SSLog::ln("database created successfully");

    if (!db.open()) {
        SSLog::le("can't open sqlite database");
        return;
    }
    SSLog::ln("database opened successfully");
}

DatabaseManger::~DatabaseManger() {

}

//
template <>
bool DatabaseManger::insert_item(const SearchHistory& search_history) {
    QSqlQuery query(this->db);
    query.prepare("INSERT INTO ");

    if (!query.exec()) {
        SSLog::le("add item failed: " + query.lastError().text());
        return false;
    }
    return true;
}
