#ifndef HEADER_FENSERVEUR
#define HEADER_FENSERVEUR

#include <QtWidgets>
#include <QtNetwork>
#include <string>
#include <iostream>
#include <QTimer>

#include "Data/cpu.h"
#include "Data/processus.h"
#include "Data/ram.h"
#include "Data/network.h"
#include "Data/serveur.h"
#include "Data/disque.h"
#include "Data/client.h"
#include "Data/serverMessage.h"


class FenServeur : public QWidget
{
    Q_OBJECT

    public:
    // initialisation du serveur et les widgets
        FenServeur();
     // envoyer a tout les client connecter le message
        void envoyerATous(const QString &message);
    // trouver client par socket
        Client *findClientBySocket(QTcpSocket *socket);

    private slots:
        // apeller lors qu'un client se connecte
        void nouvelleConnexion();
        // apeler a chaque sous paket recu
        void donneesRecues();
        // apeler lorsque le client se dectonect
        void deconnexionClient();

        // broadcaster
        void sendVMData();
        void sendProcessesData();
        void sendCpuData();
        void sendRamData();
        void sendDiskData();
        void sendNetworkData();
        void sendServerData();

    private:
        QLabel *etatServeur;
        QPushButton *boutonQuitter;
    // le serveur sur le reseau
        QTcpServer *serveur;
      // liste des client
        QList<Client *> clients;
       // la taille du message
        quint16 tailleMessage;
};

#endif
