#ifndef CLIENT_H
#define CLIENT_H
#include <QtNetwork>
#include <iostream>
#include <QDateTime>
#include <QDate>

using namespace std;

class Client
{
    friend class FenServeur;

public:
    Client();
    Client(QTcpSocket *socket);
    void read(const QJsonObject &json);
    void write(QJsonObject &json);
    void stopTimers();

private:
    QTcpSocket* socket;
    QTimer *defaultTimer;
    int frequency;

    QString adresseIp;
    int IdConnexion ;
    QString nom;
    bool status;
    QDateTime dateDebutConnexion;
    QDateTime dateDerniereConnexion;
};

#endif // CLIENT_H
