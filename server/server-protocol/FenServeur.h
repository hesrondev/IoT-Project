#ifndef HEADER_FENSERVEUR
#define HEADER_FENSERVEUR

#include <QtWidgets>
#include <QtNetwork>
#include <string>
#include <iostream>
#include <QTimer>

#include "Data/cpu.h"
#include "Data/processesactivity.h"
#include "Data/ram.h"
#include "Data/network.h"
#include "Data/serveur.h"
#include "Data/disksactivity.h"
#include "Data/client.h"
#include "Data/component.h"


class FenServeur : public QWidget
{
    Q_OBJECT

    public:
    // initialisation du serveur et les widgets
        FenServeur();
     // envoyer a tout les client connecter le message
        void envoyerATous(const QString &message);
        void sendDataToClient(QTcpSocket *soc, const QString &message);
     // trouver client par socket
        Client *findClientBySocket(QTcpSocket *socket);

     // traitement des messages reçus
        void messageProcessing(QTcpSocket *soc, QString message);


    private slots:
        // apeller lors qu'un client se connecte
        void nouvelleConnexion();
        // apeler a chaque sous paket recu
        void donneesRecues();
        // apeler lorsque le client se dectonect
        void deconnexionClient();

        // broadcaster
        // void sendVMData();
        void sendProcessesData(QTcpSocket * soc);
        void sendCpuData(QTcpSocket * soc);
        void sendRamData(QTcpSocket * soc);
        void sendDiskData(QTcpSocket * soc);
        void sendNetworkData(QTcpSocket * soc);
        void sendServerData(QTcpSocket * soc);

        void sendAllData(QTcpSocket *soc);

signals:
        void sendProcessesDataSignal(QTcpSocket *socket);

    private:
        QLabel *etatServeur;
        QPushButton *boutonQuitter;
    // le serveur sur le reseau
        QTcpServer *serveurTcp;
      // liste des client
        QList<Client *> clients;
      // liste des clients déconnectés
        QList<Client *> oldClients;
       // la taille du message
        quint16 tailleMessage;

        ProcessesActivity processes;
        DisksActivity disks;
        Cpu *cpu;
        Ram *ram;
        Network *network;
        Serveur *server;
};

#endif
