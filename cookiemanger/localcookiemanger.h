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
    static const QString RESULT_USEFUL_COOKIE;
    static const QString RESULT_UNUSEFUL_COOKIE;

public:
    void load_cookies();
    const Cookie& get_one_cookie();
    bool check_cookie_useful(const Cookie& cookie) const;

public:
    QList<Cookie>* cookie_pool;
    int cookie_index;            // pointer to a cookie that useful
    int cookie_count;
};

#endif // LOCALCOOKIEMANGER_H
