#ifndef HEADER_FENCLIENT
#define HEADER_FENCLIENT

#include <QtWidgets>
#include <QtNetwork>

#include "Data/processus.h"
#include "Data/cpu.h"
#include "Data/ram.h"
#include "Data/disque.h"
#include "Data/network.h"
#include "Data/serveur.h"
#include "Data/data.h"

#include "client-gui/mainwindow.h"


class ClientMainWindow : public MainWindow
{
    Q_OBJECT

    public:
        ClientMainWindow();

        // fonction du traitement des messages
        void messageProcessing(QString message);
        void sendDataToServer(const QString &message);
        void sendClientData();

    private slots:
        void on_boutonConnexion_clicked(const QString &ip, const QString &port, const QString &clientName, const QString &mdp);
        void donneesRecues();
        void connecte();
        void deconnecte();
        void deconnexion();
        void erreurSocket(QAbstractSocket::SocketError erreur);

    // fréquence d'acquisition
        void updateComponentsParams(int pro, int cpu, int mem, int disk, int eth);
        void updateGlobalParam(int glo);


    private:
        QTcpSocket *socket; // Représente le serveur
        quint16 tailleMessage;

        // Composants de la VM
        Client client;
        ProcessesActivity processes;
        DisksActivity disks;
        Cpu cpu;
        Ram ram;
        Network network;
        Serveur server;

        // Toutes les données
        Data allData;
};

#endif
