#-------------------------------------------------
#
# Project created by QtCreator 2016-10-30T12:36:25
#
#-------------------------------------------------

QT       += webenginewidgets

TARGET = Principal
TEMPLATE = lib

DEFINES += PRINCIPAL_LIBRARY

SOURCES += principal.cpp

HEADERS += principal.h\
        principal_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

LIBS += -L$$PWD/../WebCoreFunctions/ -lWebCoreFunctions

INCLUDEPATH += $$PWD/../WebCoreFunctions
DEPENDPATH += $$PWD/../WebCoreFunctions

RESOURCES += \
    htmlforms.qrc
