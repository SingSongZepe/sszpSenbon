#ifndef SSLOG_H
#define SSLOG_H

#include <QDebug>
#include <QString>

class SSLog
{
public:
    SSLog();
    ~SSLog();

    static void ln(QString str);
    static void lw(QString str);
    static void le(QString str);
};

class SSLogConstants
{
public:
    static const QString TYPE_NORMAL;
    static const QString TYPE_WARNING;
    static const QString TYPE_ERROR;
};

#endif // SSLOG_H
