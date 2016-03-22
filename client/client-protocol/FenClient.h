#ifndef HEADER_FENCLIENT
#define HEADER_FENCLIENT

#include <QtWidgets>
#include <QtNetwork>
#include "ui_FenClient.h"

#include "Data/processus.h"
#include "Data/cpu.h"
#include "Data/ram.h"
#include "Data/disque.h"
#include "Data/network.h"
#include "Data/serveur.h"


class FenClient : public QWidget, private Ui::FenClient
{
    Q_OBJECT

    public:
        FenClient();
        // fonction du traitement des messages
        void messageProcessing(QString message);

    private slots:
        void on_boutonConnexion_clicked();
        void on_boutonEnvoyer_clicked();
        void on_message_returnPressed();
        void donneesRecues();
        void connecte();
        void deconnecte();
        void erreurSocket(QAbstractSocket::SocketError erreur);

    private:
        QTcpSocket *socket; // Repr�sente le serveur
        quint16 tailleMessage;

        // Composants de la VM
        Processus process;
        Cpu cpu;
        Ram ram;
        Disque disk;
        Network network;
        Serveur server;
};

#endif