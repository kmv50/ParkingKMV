#-------------------------------------------------
#
# Project created by QtCreator 2016-10-27T18:56:43
#
#-------------------------------------------------

QT       += core webenginewidgets

QT       -= gui

TARGET = WebCoreFunctions
TEMPLATE = lib

DEFINES += WEBCOREFUNCTIONS_LIBRARY

SOURCES += webcorefunctions.cpp

HEADERS += webcorefunctions.h\
    localdefinitions.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
