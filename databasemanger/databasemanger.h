#ifndef DATABASEMANGER_H
#define DATABASEMANGER_H

#include <QObject>
#include <QtSql/QSqlDatabase>

class DatabaseManger : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManger(const QString& db_file_path, QObject *parent = nullptr);
    ~DatabaseManger();

    template <typename ITEM>
    bool insert_item(const ITEM& item);

public:
    QSqlDatabase db;

signals:

};

#endif // DATABASEMANGER_H
