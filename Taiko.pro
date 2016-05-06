#-------------------------------------------------
#
# Project created by QtCreator 2016-05-03T23:29:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    time.cpp \
    score.cpp \
    taiko.cpp \
    player.cpp \
    hit.cpp \
    taiko2.cpp \
    hit2.cpp \
    result.cpp \
    how.cpp

HEADERS  += mainwindow.h \
    game.h \
    time.h \
    score.h \
    taiko.h \
    player.h \
    hit.h \
    taiko2.h \
    hit2.h \
    result.h \
    how.h

FORMS    += mainwindow.ui \
    result.ui \
    how.ui

RESOURCES += \
    res.qrc
