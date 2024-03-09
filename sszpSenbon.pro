QT       += core gui \
           network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    api.cpp \
    event.cpp \
    main.cpp \
    mainwindow.cpp \
    object/helloworld.cpp \
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
    mainwindow.h \
    object/helloworld.h \
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
    image.qrc

DISTFILES += \
    book_result_parse.py \
    book_info.py \
    README.md



win32:CONFIG(release, debug|release): LIBS += -LC:/Users/Lenovo/AppData/Local/Programs/Python/Python311 -lpython311
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/Users/Lenovo/AppData/Local/Programs/Python/Python311 -lpython311
else:unix: LIBS += -LC:/Users/Lenovo/AppData/Local/Programs/Python/Python311/ -lpython311

INCLUDEPATH += C:/Users/Lenovo/AppData/Local/Programs/Python/Python311/include
DEPENDPATH += C:/Users/Lenovo/AppData/Local/Programs/Python/Python311/include
