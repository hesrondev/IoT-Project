#ifndef SERVEUR_H
#define SERVEUR_H
#include <iostream>
#include <QList>
#include"client.h"
using namespace std;




class Serveur
{
public:
    Serveur(QList<Client *> clients);
    QString getNom() const;
    void setNom(const QString &value);

    QString getIp() const;
    void setIp(const QString &value);

    int getPort() const;
    void setPort(int value);

    QList<Client*> getListClients() const;
    void setListClients(const QList<Client*> &value);

    void read(const QJsonObject &json);
    void write(QJsonObject &json);

private:
    QString nom;
    QString ip;
    int port;
    QList <Client*> listClients;
};

#endif // SERVEUR_H
