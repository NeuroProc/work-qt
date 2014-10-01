#-------------------------------------------------
#
# Project created by QtCreator 2014-09-30T14:05:43
#
#-------------------------------------------------
QT += core

TARGET = trapezium
TEMPLATE = lib

DEFINES += TRAPEZIUM_LIBRARY

#INCLUDEPATH += ../LAB1/

SOURCES += trapezium.cpp\
            ../LAB1/shape.cpp


HEADERS += trapezium.h\
        trapezium_global.h\
        ../LAB1/shape.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
