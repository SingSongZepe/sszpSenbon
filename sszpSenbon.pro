QT       += core gui \
           network \
           sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    api.cpp \
    cookiemanger/remotecookiemanger.cpp \
    databasemanger/databasemanger.cpp \
    object/cookie.cpp \
    cookiemanger/localcookiemanger.cpp \
    event.cpp \
    function/savefile.cpp \
    main.cpp \
    mainwindow.cpp \
    object/bookfullinfo.cpp \
    object/helloworld.cpp \
    object/searchhistory.cpp \
    object/sfunctor.cpp \
    search.cpp \
    singlebookinfo.cpp \
    singsongzepe.cpp \
    sslog.cpp \
    sszpsenbon.cpp \
    utils.cpp \
    bookinfoitem.cpp \
    object/book_info.cpp \
    worker.cpp

HEADERS += \
    cookiemanger/remotecookiemanger.h \
    databasemanger/databasemanger.h \
    object/cookie.h \
    cookiemanger/localcookiemanger.h \
    function/savefile.h \
    mainwindow.h \
    object/bookfullinfo.h \
    object/helloworld.h \
    object/searchhistory.h \
    object/sfunctor.h \
    search.h \
    singlebookinfo.h \
    singsongzepe.h \
    sslog.h \
    object/book_info.h \
    bookinfoitem.h \
    worker.h

FORMS += \
    mainwindow.ui \
    bookinfoitem.ui \
    object/helloworld.ui \
    singlebookinfo.ui

TRANSLATIONS += \
    sszpSenbon_en_GB.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    file.qrc \
    image.qrc

DISTFILES += \
    book_result_parse.py \
    book_info.py \
    README.md \
    search_single_book_parse.py \
    cookies.json \
    check_cookie_useful.py




win32:CONFIG(release, debug|release): LIBS += -LC:/Users/Lenovo/AppData/Local/Programs/Python/Python311/libs/ -lpython311
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/Users/Lenovo/AppData/Local/Programs/Python/Python311/libs/ -lpython311_d
else:unix: LIBS += -LC:/Users/Lenovo/AppData/Local/Programs/Python/Python311/libs/ -lpython311

INCLUDEPATH += C:/Users/Lenovo/AppData/Local/Programs/Python/Python311/include
DEPENDPATH += C:/Users/Lenovo/AppData/Local/Programs/Python/Python311/include

