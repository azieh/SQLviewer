#-------------------------------------------------
#
# Project created by QtCreator 2015-09-23T12:36:24
#
#-------------------------------------------------

QT       += core gui \
         sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SherlySQLviewer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    browser.cpp

HEADERS  += mainwindow.h \
    browser.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
