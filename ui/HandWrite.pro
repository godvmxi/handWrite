#-------------------------------------------------
#
# Project created by QtCreator 2015-08-11T14:58:07
#
#-------------------------------------------------

QT       += core gui network
LIBS     += /usr/lib/libzinnia.so

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HandWrite
TEMPLATE = app


SOURCES += main.cpp \
    chartable.cpp \
    recongnizer.cpp \
    charitem.cpp \
    controlpanel.cpp \
    topwrap.cpp \
    tophw.cpp \
    drawwidget.cpp

HEADERS  += \
    chartable.h \
    common.h \
    recongnizer.h \
    charitem.h \
    controlpanel.h \
    topwrap.h \
    tophw.h \
    drawwidget.h

