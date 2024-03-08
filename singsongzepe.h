#ifndef SINGSONGZEPE_H
#define SINGSONGZEPE_H

#include <QString>

class SingSongZepe
{
public:
    SingSongZepe();
    ~SingSongZepe();

    static const QString sslog;
    static const QString SINGSONGZEPE_;

    //project name
    static const QString SSZPSENBON_;

    // web info
    static const QString zlibrary_url;
    static const QString subfix_general;
    static const QString subfix_fulltext;

    // html parse for book
    static const QString BOOK_RESULT_PARSE_FILE;

    // utils for constructing of book_infos
    static const QString URL_;
    static const QString COVER_;
    static const QString TITLE_;
    static const QString PUBLISHER_;
    static const QString AUTHORS_;
    static const QString FILE_INFO_;
    static const QString LANGUAGE_;
    static const QString RATING_;

};

#endif // SINGSONGZEPE_H
