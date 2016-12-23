#-------------------------------------------------
#
# Project created by QtCreator 2016-06-24T12:16:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = atow
TEMPLATE = app

SOURCES += main.cpp\
    atow.cpp \
    component.cpp \
    editor.cpp \
    viewer.cpp \
    staticdata.cpp

HEADERS  += atow.h \
    component.h \
    editor.h \
    viewer.h \
    staticdata.h

FORMS    += atow.ui \
    editor.ui \
    viewer.ui
