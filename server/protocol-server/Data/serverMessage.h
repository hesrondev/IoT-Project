#ifndef SERVERMESSAGE_H
#define SERVERMESSAGE_H
#include <iostream>
#include <QJsonObject>

#include"cpu.h"
#include"disque.h"
#include"network.h"
#include"processus.h"
#include"ram.h"
#include"serveur.h"

using namespace std;

class ServerMessage
{
public:
    ServerMessage(QList<Client *> clients);
    QString getType() const;
    void setType(const QString &value);

    QString getNomServeur() const;
    void setNomServeur(const QString &value);

    Cpu getCpu() const;
    void setCpu(const Cpu &value);

    Disque getDisque() const;
    void setDisque(const Disque &value);

    Network getNetwork() const;
    void setNetwork(const Network &value);

    Processus getProcessur() const;
    void setProcessur(const Processus &value);

    Ram getRam() const;
    void setRam(const Ram &value);

    Serveur getServeur() const;
    void setServeur(const Serveur &value);
    void read(const QJsonObject &json);
    void write(QJsonObject &json);

private:
    QString type;
    QString nomServeur;
    Cpu cpu;
    Disque disque;
    Network network;
    Processus processus;
    Ram ram;
    Serveur serveur;

};

#endif // SERVERMESSAGE_H
