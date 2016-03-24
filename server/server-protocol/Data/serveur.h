#ifndef SERVEUR_H
#define SERVEUR_H

#include <iostream>
#include <QList>

#include"client.h"
#include"component.h"

using namespace std;


class Serveur : public Component
{
public:
    Serveur(QList<Client *> clients);

    void read(const QJsonObject &json);
    void write(QJsonObject &json);

    void updateData();
    void updateData(QList <Client*> lc);

    virtual ~Serveur();

private:
    QString nom;
    QString ip;
    int port;
    QList <Client*> listClients;
};

#endif // SERVEUR_H
