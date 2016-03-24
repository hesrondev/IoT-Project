#ifndef CLIENT_H
#define CLIENT_H
#include <QtNetwork>
#include <iostream>
#include <QDateTime>
#include <QDate>

#include "timercustom.h"
using namespace std;

class Client
{
    friend class FenServeur;

public:
    Client();
    Client(int id, QTcpSocket *socket);
    void read(const QJsonObject &json);
    void write(QJsonObject &json);

    void stopTimers();
    void startTimers();

    void disconnect();

    int getIdConnexion() const;
    void setIdConnexion(int value);

private:
    QTcpSocket* socket;

    TimerCustom *processTimer;
    TimerCustom *cpuTimer;
    TimerCustom *ramTimer;
    TimerCustom *diskTimer;
    TimerCustom *networkTimer;
    TimerCustom *serverTimer;

    int processFq;
    int cpuFq;
    int ramFq;
    int diskFq;
    int networkFq;
    int serverFq;

    QString adresseIp;
    int IdConnexion ;
    QString nom;
    bool status;
    QDateTime dateDebutConnexion;
    QDateTime dateDerniereConnexion;
};

#endif // CLIENT_H
