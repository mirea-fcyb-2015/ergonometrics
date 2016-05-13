#-------------------------------------------------
#
# Project created by QtCreator 2016-05-01T13:05:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ergonometrics
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    control.cpp \
    mediator.cpp \
    parser.cpp \
    document.cpp \
    configuration.cpp \
    creator.cpp

HEADERS  += mainwindow.h \
    control.h \
    mediator.h \
    parser.h \
    document.h \
    criterion.h \
    configuration.h \
    creator.h \
    concrete_criterion.h

FORMS    += mainwindow.ui
