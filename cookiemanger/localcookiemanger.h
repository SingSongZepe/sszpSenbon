#ifndef LOCALCOOKIEMANGER_H
#define LOCALCOOKIEMANGER_H

#include "object/cookie.h"
#include "sslog.h"

#include <QList>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

class LocalCookieManger
{
public:
    LocalCookieManger();
    ~LocalCookieManger();

public:
    static const QString COOKIES_JSON_FILE;

public:
    void load_cookies();
    const Cookie& get_one_cookie();

public:
    QList<Cookie>* cookie_pool;

};

#endif // LOCALCOOKIEMANGER_H
