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
    topui.cpp \
    chartable.cpp \
    socket.cpp \
    recongnizer.cpp \
    drawWidget.cpp

HEADERS  += \
    topui.h \
    chartable.h \
    socket.h \
    common.h \
    recongnizer.h \
    drawWidget.h

