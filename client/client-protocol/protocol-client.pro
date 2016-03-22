QT += core widgets network

TARGET = protocol-client
CONFIG += release
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Data/client.cpp \
    Data/cpu.cpp \
    Data/disque.cpp \
    Data/network.cpp \
    Data/processus.cpp \
    Data/ram.cpp \
    Data/servermessage.cpp \
    Data/serveur.cpp \
    FenClient.cpp



RESOURCES += \
    ressources/ressources.qrc

HEADERS += \
    Data/client.h \
    Data/cpu.h \
    Data/disque.h \
    Data/network.h \
    Data/processus.h \
    Data/ram.h \
    Data/serverMessage.h \
    Data/serveur.h \
    FenClient.h

FORMS += \
    FenClient.ui

