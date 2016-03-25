#-------------------------------------------------
#
# Project created by QtCreator 2016-03-22T15:07:06
#
#-------------------------------------------------

QT       += widgets network
CONFIG   += qwt
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClientController
TEMPLATE = app


SOURCES +=\
    client-gui/aboutappdialog.cpp \
    client-gui/apphistorytab.cpp \
    client-gui/centralwidget.cpp \
    client-gui/devicecustombutton.cpp \
    client-gui/disktabdetails.cpp \
    client-gui/displaysettingsdialog.cpp \
    client-gui/mainwindow.cpp \
    client-gui/memorytabdetails.cpp \
    client-gui/menubar.cpp \
    client-gui/networktabdetails.cpp \
    client-gui/performancecustombutton.cpp \
    client-gui/performancegraph.cpp \
    client-gui/performancetab.cpp \
    client-gui/processortabdetails.cpp \
    client-gui/processtab.cpp \
    client-gui/serverlogindialog.cpp \
    client-gui/servertab.cpp \
    client-protocol/Data/client.cpp \
    client-protocol/Data/cpu.cpp \
    client-protocol/Data/disque.cpp \
    client-protocol/Data/network.cpp \
    client-protocol/Data/processus.cpp \
    client-protocol/Data/ram.cpp \
    client-protocol/Data/servermessage.cpp \
    client-protocol/Data/serveur.cpp \
    client-protocol/main.cpp \
    client-protocol/clientmainwindow.cpp \
    client-gui/observer.cpp \
    client-protocol/Data/data.cpp \
    client-protocol/Data/disksactivity.cpp \
    client-protocol/Data/processesactivity.cpp


HEADERS  += \
    client-gui/aboutappdialog.h \
    client-gui/apphistorytab.h \
    client-gui/centralwidget.h \
    client-gui/devicecustombutton.h \
    client-gui/disktabdetails.h \
    client-gui/displaysettingsdialog.h \
    client-gui/mainwindow.h \
    client-gui/memorytabdetails.h \
    client-gui/menubar.h \
    client-gui/networktabdetails.h \
    client-gui/performancecustombutton.h \
    client-gui/performancegraph.h \
    client-gui/performancetab.h \
    client-gui/processortabdetails.h \
    client-gui/processtab.h \
    client-gui/serverlogindialog.h \
    client-gui/servertab.h \
    client-protocol/Data/client.h \
    client-protocol/Data/cpu.h \
    client-protocol/Data/disque.h \
    client-protocol/Data/network.h \
    client-protocol/Data/processus.h \
    client-protocol/Data/ram.h \
    client-protocol/Data/serverMessage.h \
    client-protocol/Data/serveur.h \
    client-protocol/clientmainwindow.h \
    client-gui/observer.h \
    client-protocol/Data/data.h \
    client-protocol/Data/disksactivity.h \
    client-protocol/Data/processesactivity.h

RESOURCES += \
    ressources/ressources.qrc
