#-------------------------------------------------
#
# Project created by QtCreator 2010-08-17T09:04:07
#
#-------------------------------------------------

QT  += core gui
CONFIG += qwt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET  = demo_qwtbarzoom
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS += mainwindow.h

FORMS   += mainwindow.ui


include(qwt.pri)


SOURCES += scrollzoomer.cpp\
        scrollbar.cpp

HEADERS += scrollzoomer.h\
        scrollbar.h
