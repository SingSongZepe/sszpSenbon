#include "localcookiemanger.h"

const QString LocalCookieManger::COOKIES_JSON_FILE = ":/:/cookies.json";

LocalCookieManger::LocalCookieManger() {
    this->cookie_pool = new QList<Cookie>;
    load_cookies();
}

LocalCookieManger::~LocalCookieManger() {
    delete cookie_pool;
}

void LocalCookieManger::load_cookies() {
    QFile pf(LocalCookieManger::COOKIES_JSON_FILE);
    if (!pf.open(QIODevice::ReadOnly | QIODevice::Text)) {
        SSLog::ln("can't open json file for cookie");
        return;
    }

    QByteArray json_data = pf.readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(json_data);
    QJsonArray json_array = json_doc.array();

    for (const QJsonValue& value : json_array) {
        QJsonObject obj = value.toObject();
        QString cookie = obj["cookie"].toString();
        bool vip = obj["vip"].toBool();

        this->cookie_pool->append(Cookie(cookie, vip));
    }

    pf.close();
}

const Cookie& LocalCookieManger::get_one_cookie() {
    return cookie_pool->constFirst();
}


