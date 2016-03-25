#ifndef CLIENT_H
#define CLIENT_H
#include <QtNetwork>
#include <iostream>
#include <QDateTime>
#include <QDate>

#include "serverMessage.h"

using namespace std;

class Client : public ServerMessage
{

    friend class Serveur;

public:
    Client();
    void read(const QJsonObject &json);
    void write(QJsonObject &json);
    void disconnect();

    void setComponentsParams(int pro, int cpu, int mem, int disk, int eth);

    void setGlobalFq(int value);

    void setGlobalSendingState(bool value);

    void setNom(const QString &value);

    void setMdpServer(const QString &value);

private:

    // gestion des timers

    int processFq;
    int cpuFq;
    int ramFq;
    int diskFq;
    int networkFq;
    int serverFq;
    int globalFq;

    // état de l'envoie par groupe
    bool globalSendingState;

    QString adresseIp;
    int IdConnexion ;
    QString nom;
    QString mdpServer;
    bool status;
    QDateTime dateDebutConnexion;
    QDateTime dateDerniereConnexion;
};

#endif // CLIENT_H
