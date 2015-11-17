#-------------------------------------------------
#
# Project created by QtCreator 2015-09-23T12:36:24
#
#-------------------------------------------------

QT       += core gui
QT       +=sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET      = SherlySQLviewer
TEMPLATE    = app

CONFIG      += c++11\
                static


SOURCES     += main.cpp\
                mainwindow.cpp \
                browser.cpp \
                editstrategysettings.cpp

HEADERS     += mainwindow.h \
                browser.h \
                editstrategysettings.h

FORMS       += mainwindow.ui \
                editstrategysettings.ui

RESOURCES   += res.qrc

RC_FILE = SQLviewer.rc


