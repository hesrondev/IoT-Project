#ifndef SERVEUR_H
#define SERVEUR_H

#include <iostream>
#include <QList>

#include "client.h"
#include "serverMessage.h"
#include "client-gui/servertab.h"

using namespace std;


class Serveur : public ServerMessage
{
public:
    Serveur();
    Serveur(QList<Client *> lc);

    void read(const QJsonObject &json);
    void write(QJsonObject &json);

    // observer
    void updateObserver();

private:
    QString nom;
    QString ip;
    int port;
    QList <Client*> clients;
};

#endif // SERVEUR_H
