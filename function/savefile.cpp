#include "savefile.h"

#include "sslog.h"

#include <QFile>

bool SaveFile::save_file(const QString& content, const QString& file_name, const QString& file_path) {
    QString full_file_path = file_path + "/" + file_name;
    SSLog::ln(QString("File will be saved as: %1").arg(full_file_path));
    QFile pf(full_file_path);
    if (!pf.open(QIODevice::WriteOnly | QIODevice::Text)) {
        SSLog::le("Error: Cannot open file for writing");
        return false;
    }

    QTextStream out(&pf);
    out << content;
    pf.close();
    return true;
}
