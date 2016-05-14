#-------------------------------------------------
#
# Project created by QtCreator 2016-05-07T11:29:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled2
TEMPLATE = app


SOURCES += main.cpp\
        welcomewindow.cpp \
    mainwindow.cpp \
    game.cpp \
    endwindow.cpp

HEADERS  += welcomewindow.h \
    mainwindow.h \
    game.h \
    ball.h \
    endwindow.h

FORMS    += welcomewindow.ui \
    mainwindow.ui \
    endwindow.ui

RESOURCES += \
    pics.qrc
