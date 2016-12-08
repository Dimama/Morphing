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
    camera.cpp \
    drawer.cpp \
    message.cpp

HEADERS  += mainwindow.h \
    mesh.h \
    structures.h \
    b_error.h \
    fileerrors.h \
    camera.h \
    drawer.h \
    message.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -fopenmp
QMAKE_LFLAGS   += -fopenmp

LIBS    += -lqjson-qt5 -lgomp -lpthread
