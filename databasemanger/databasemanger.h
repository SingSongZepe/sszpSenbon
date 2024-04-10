#ifndef DATABASEMANGER_H
#define DATABASEMANGER_H

#include <QObject>
#include <QtSql/QSqlDatabase>

class DatabaseManger : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManger(const QString& db_file_path, const QString& table_name, const QString& connect_name, QObject *parent = nullptr);
    ~DatabaseManger();

    template <typename ITEM>
    bool insert_item(const ITEM& item);

    bool delete_item_by_id(const QString& id);

    template <typename ITEM>
    bool update_item(const ITEM& item, const QString& id);

    template <typename ITEM>
    ITEM search_by_id(const QString& id);

    template <typename ITEM>
    QList<ITEM> search_all();

public:
    QSqlDatabase db;
    QString table_name;

signals:

};

#endif // DATABASEMANGER_H
