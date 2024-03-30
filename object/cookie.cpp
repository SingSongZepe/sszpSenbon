#include "cookie.h"

Cookie::Cookie() {}

Cookie::Cookie(const QString& cookie, bool vip) {
    this->cookie = cookie;
    this->vip = vip;
}

Cookie::~Cookie() {}
