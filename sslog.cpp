#include "sslog.h"

#include "singsongzepe.h"

const QString SSLogConstants::TYPE_NORMAL = "[NOR] ";
const QString SSLogConstants::TYPE_WARNING = "[WAR] ";
const QString SSLogConstants::TYPE_ERROR = "[ERR] ";

SSLog::SSLog() {

}

SSLog::~SSLog() {

}

// there pure function
// do not pass pointer or reference
void SSLog::ln(QString str) {
    qDebug() << SingSongZepe::sslog + SSLogConstants::TYPE_NORMAL + str;
}

void SSLog::lw(QString str) {
    qDebug() << SingSongZepe::sslog + SSLogConstants::TYPE_WARNING + str;
}

void SSLog::le(QString str) {
    qDebug() << SingSongZepe::sslog + SSLogConstants::TYPE_ERROR + str;
}
