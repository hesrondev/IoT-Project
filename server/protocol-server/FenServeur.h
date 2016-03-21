#ifndef HEADER_FENSERVEUR
#define HEADER_FENSERVEUR

#include <QtWidgets>
#include <QtNetwork>
#include <string>
#include <iostream>
#include <QTimer>

#include "Data/serverMessage.h"
#include "Data/client.h"


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
