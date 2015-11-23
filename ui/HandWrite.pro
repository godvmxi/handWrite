#-------------------------------------------------
#
# Project created by QtCreator 2015-08-11T14:58:07
#
#-------------------------------------------------

QT       += core gui network

TARGET_PLAT   += ARM
eval( $${TARGET_PLAT} = ARM ){
    LIBS     +=  -L ./ -lzinnia
    message("arm mips plat")
}

#eval( $${TARGET_PLAT} = X86 ){
#    LIBS     += /usr/lib/libzinnia.so
#    message("x86/64 plat")
#}

#LIBS     += /usr/lib/libzinnia.so

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
    drawwidget.h \
    zinnia.h

