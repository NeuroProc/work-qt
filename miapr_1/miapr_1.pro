#-------------------------------------------------
#
# Project created by QtCreator 2014-09-12T14:37:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = miapr_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    draw.cpp \
    classifier.cpp \
    paintw.cpp

HEADERS  += mainwindow.h \
    draw.h \
    classifier.h \
    paintw.h

FORMS    += mainwindow.ui
