TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += с++11
QMAKE_CXXFLAGS += -std=c++11 -stdlib=libc++

SOURCES += main.cpp \
    parser.cpp \
    mayers.cpp

HEADERS += \
    parser.h \
    mayers.h

