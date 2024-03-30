#ifndef COOKIE_H
#define COOKIE_H

#include <QString>

class Cookie
{
public:
    explicit Cookie();
    explicit Cookie(const QString& cookie, bool vip = false);
    ~Cookie();

public:
    void set_cookie(const QString& cookie);

public:
    QString cookie;
    bool vip;
};

#endif // COOKIE_H
