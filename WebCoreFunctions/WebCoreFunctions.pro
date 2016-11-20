#-------------------------------------------------
#
# Project created by QtCreator 2016-10-27T19:42:42
#
#-------------------------------------------------

QT       += core gui webenginewidgets

TARGET = WebCoreFunctions
TEMPLATE = lib

DEFINES += WEBCOREFUNCTIONS_LIBRARY

SOURCES += \
    utilwebcore.cpp \
    webbaseclass.cpp \
    weboperations.cpp \
    webtableengine.cpp

HEADERS +=\
        webcorefunctions_global.h \
    localdefinitions.h \
    utilwebcore.h \
    webbaseclass.h \
    weboperations.h \
    webtableengine.h \
    tabledefinitions.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
