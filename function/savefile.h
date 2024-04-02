#ifndef SAVEFILE_H
#define SAVEFILE_H

#include "singsongzepe.h"

class SaveFile
{
public:
    static bool save_file(const QString& content, const QString& file_name, const QString& file_path = SingSongZepe::PATH_STORE_FILE_DOWNLOAD);
    static bool save_file(const QByteArray& content, const QString& file_name, const QString& file_path = SingSongZepe::PATH_STORE_FILE_DOWNLOAD);
};

#endif // SAVEFILE_H
