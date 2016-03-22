#-------------------------------------------------
#
# Project created by QtCreator 2016-03-11T11:32:33
#
#-------------------------------------------------

QT       += core gui
QT += widgets network
DEPENDPATH += .
INCLUDEPATH += .

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serveur
TEMPLATE = app


SOURCES += main.cpp\
        FenServeur.cpp \
    Data/servermessage.cpp \
    Data/cpu.cpp \
    Data/processus.cpp \
    Data/serveur.cpp \
    Data/ram.cpp \
    Data/disque.cpp \
    Data/network.cpp \
    Data/client.cpp

HEADERS  += FenServeur.h \
    Data/cpu.h \
    Data/processus.h \
    Data/serveur.h \
    Data/ram.h \
    Data/disque.h \
    Data/network.h \
    Data/client.h \
    Data/serverMessage.h

FORMS    += main.ui
