#-------------------------------------------------
#
# Project created by QtCreator 2014-09-19T21:47:26
#
#-------------------------------------------------

QT       += core gui
CONFIG   += qwt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = divm2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graph.cpp

HEADERS  += mainwindow.h \
    graph.h \
    lagrange.h \
    newton.h

FORMS    += mainwindow.ui

#include ( /usr/local/share/qt4/mkspecs/features/qwt.prf )
