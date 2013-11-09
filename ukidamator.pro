#-------------------------------------------------
#
# Project created by QtCreator 2013-09-23T19:42:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ukidamator
TEMPLATE = app


SOURCES += main.cpp\
        programwindow.cpp \
    converter.cpp

HEADERS  += programwindow.h \
    converter.h

FORMS    += programwindow.ui

TRANSLATIONS = ukidamator_ru_RU.ts

win32: CONFIG += static

RC_FILE = icon.rc

RESOURCES += \
    resources.qrc
