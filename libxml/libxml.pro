#-------------------------------------------------
#
# Project created by QtCreator 2014-12-03T15:50:52
#
#-------------------------------------------------

QT       += xml

QT       -= gui

TARGET = libxml
TEMPLATE = lib

DEFINES += XMLEDITOR_LIBRARY

SOURCES += \
    xmleditor.cpp

HEADERS +=\
    xmleditor_global.h \
    xmleditor.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
