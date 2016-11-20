#-------------------------------------------------
#
# Project created by QtCreator 2016-10-27T18:07:16
#
#-------------------------------------------------

QT       += core gui webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Parking
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    mainwindow.cpp

HEADERS  += login.h \
    mainwindow.h

RESOURCES += \
    htmlcontext.qrc




unix:!macx: LIBS += -L$$PWD/../WebCoreFunctions/ -lWebCoreFunctions

INCLUDEPATH += $$PWD/../WebCoreFunctions
DEPENDPATH += $$PWD/../WebCoreFunctions

unix:!macx: LIBS += -L$$PWD/../Principal/ -lPrincipal

INCLUDEPATH += $$PWD/../Principal
DEPENDPATH += $$PWD/../Principal
