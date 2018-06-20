#-------------------------------------------------
#
# Project created by QtCreator 2018-06-19T15:37:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TheGorgeRecipeBrowser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainrecipemodel.cpp \
    sortfilterrecipemodel.cpp

HEADERS  += mainwindow.h \
    mainrecipemodel.h \
    sortfilterrecipemodel.h

FORMS    += mainwindow.ui
