#-------------------------------------------------
#
# Project created by QtCreator 2016-10-28T10:48:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Morphing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mesh.cpp \
    vector3.cpp

HEADERS  += mainwindow.h \
    mesh.h \
    structures.h \
    vector3.h

FORMS    += mainwindow.ui

LIBS    += -lqjson-qt5
