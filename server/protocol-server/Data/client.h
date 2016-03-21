#ifndef CLIENT_H
#define CLIENT_H
#include <QtNetwork>
#include <iostream>
#include <QDateTime>

using namespace std;

class Client
{
public:
    Client();
    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;

private:
    QTcpSocket* socket;
    QString adresseIp;
    int IdConnexion ;
    QString nom;
    bool status;
    QDateTime dateDebutConnexion;
    QDateTime dateDerniereConnexion;
};

#endif // CLIENT_H
