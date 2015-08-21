#-------------------------------------------------
#
# Project created by QtCreator 2015-08-11T14:58:07
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HandWrite
TEMPLATE = app


SOURCES += main.cpp \
    handwritecore.cpp \
    topui.cpp \
    chartable.cpp \
    socket.cpp

HEADERS  += \
    handwritecore.h \
    topui.h \
    chartable.h \
    socket.h \
    common.h

