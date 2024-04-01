#include "localcookiemanger.h"

#include "singsongzepe.h"
#include "mainwindow.h"

#undef slots
#include "Python.h"
#define slots Q_SLOTS

const QString LocalCookieManger::COOKIES_JSON_FILE = ":/:/cookies.json";
const QString LocalCookieManger::RESULT_USEFUL_COOKIE = "1";
const QString LocalCookieManger::RESULT_UNUSEFUL_COOKIE = "0";

LocalCookieManger::LocalCookieManger() {
    this->cookie_pool = new QList<Cookie>;
    this->load_cookies();
    this->cookie_index = 0;
    this->cookie_count = this->cookie_pool->size();
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

// get one useful cookie for downloading
const Cookie& LocalCookieManger::get_one_cookie() {
    for (int i = this->cookie_index; i < this->cookie_pool->size(); i++) {
        if (LocalCookieManger::check_cookie_useful(this->cookie_pool->at(i))) {
            this->cookie_index = i;
            return this->cookie_pool->at(i);
        }
    }
    SSLog::le("can't download book, there is no cookie(or useful cookie) in cookie json file");
    return Cookie();
}

bool LocalCookieManger::check_cookie_useful(const Cookie& cookie) const {
    QByteArray data = MainWindow::request_url_with_cookie(SingSongZepe::zlibrary_url, cookie.cookie);

    PyObject* pymodule = PyImport_ImportModule(SingSongZepe::PYTHON_CHECK_COOKIE_USEFUL.toStdString().c_str());
    if (!pymodule) {
        SSLog::le("can't open the module file");
        return false;
    }

    PyObject* callable = PyObject_GetAttrString(pymodule, SingSongZepe::FUNCTION_CHECK_COOKIE_USEFUL.toStdString().c_str());

    // argument
    PyObject* tuple = PyTuple_New(1);
    std::string stri = data.toStdString();
    PyObject* d = PyUnicode_FromString(stri.c_str());
    PyTuple_SET_ITEM(tuple, 0, d);

    PyObject* rep = PyObject_CallObject(callable, tuple);
    PyObject* py_result = PyObject_Str(rep);
    QString result = QString::fromUtf8(PyUnicode_AsUTF8(py_result));
    if (result == LocalCookieManger::RESULT_USEFUL_COOKIE) {
        return true;
    } return false;
}






