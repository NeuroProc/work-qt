#-------------------------------------------------
#
# Project created by QtCreator 2014-10-14T20:40:55
#
#-------------------------------------------------

QT       += core gui
CONFIG   += qwt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MIAPR3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    draw.cpp

HEADERS  += mainwindow.h \
    draw.h

FORMS    += mainwindow.ui
