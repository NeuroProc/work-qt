#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T18:39:30
#
#-------------------------------------------------

QT       += core gui
#QT       += crypt
CONFIG += crypto

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = passworder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    crypter.cpp

HEADERS  += mainwindow.h \
    crypter.h

FORMS    += mainwindow.ui
