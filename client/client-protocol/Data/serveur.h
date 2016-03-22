#ifndef SERVEUR_H
#define SERVEUR_H

#include <iostream>
#include <QList>

#include"client.h"
#include"serverMessage.h"

using namespace std;


class Serveur : public ServerMessage
{
public:
    Serveur();
    Serveur(QList<Client *> clients);

    void read(const QJsonObject &json);
    void write(QJsonObject &json);

private:
    QString nom;
    QString ip;
    int port;
    QList <Client*> listClients;
};

#endif // SERVEUR_H
