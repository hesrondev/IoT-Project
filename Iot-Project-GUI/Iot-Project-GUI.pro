#-------------------------------------------------
#
# Project created by QtCreator 2016-03-09T23:18:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Iot-Project-GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    menubar.cpp \
    centralwidget.cpp \
    processtab.cpp \
    performancetab.cpp \
    apphistorytab.cpp \
    serverlogindialog.cpp \
    displaysettingsdialog.cpp \
    aboutappdialog.cpp \
    performancecustombutton.cpp \
    processortabdetails.cpp \
    memorytabdetails.cpp \
    disktabdetails.cpp \
    networktabdetails.cpp \
    servercontrollertab.cpp \
    performancegraph.cpp

HEADERS  += mainwindow.h \
    menubar.h \
    centralwidget.h \
    processtab.h \
    performancetab.h \
    apphistorytab.h \
    serverlogindialog.h \
    displaysettingsdialog.h \
    aboutappdialog.h \
    performancecustombutton.h \
    processortabdetails.h \
    memorytabdetails.h \
    disktabdetails.h \
    networktabdetails.h \
    servercontrollertab.h \
    performancegraph.h

FORMS    += mainwindow.ui

RESOURCES += \
    ressources/ressources.qrc
