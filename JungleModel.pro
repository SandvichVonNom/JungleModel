#-------------------------------------------------
#
# Project created by QtCreator 2015-04-09T17:08:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JungleModel
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    stats.cpp \
    calc.cpp

HEADERS  += mainwindow.h \
    stats.h \
    calc.h

FORMS    += mainwindow.ui \
    stats.ui

RESOURCES += \
    config.qrc
