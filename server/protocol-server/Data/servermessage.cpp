#include "serverMessage.h"

ServerMessage::ServerMessage(QList<Client*> clients) : cpu(), disque(), network(), processus(), ram(), serveur(clients)
{
     type ="type";
     nomServeur="nom";
}

Serveur ServerMessage::getServeur() const
{
    return serveur;
}

void ServerMessage::setServeur(const Serveur &value)
{
    serveur = value;
}

Ram ServerMessage::getRam() const
{
    return ram;
}

void ServerMessage::setRam(const Ram &value)
{
    ram = value;
}

Network ServerMessage::getNetwork() const
{
    return network;
}

void ServerMessage::setNetwork(const Network &value)
{
    network = value;
}

void ServerMessage::setProcessus(const Processus &value)
{

}

Disque ServerMessage::getDisque() const
{
    return disque;
}

void ServerMessage::setDisque(const Disque &value)
{
    disque = value;
}

Cpu ServerMessage::getCpu() const
{
    return cpu;
}

void ServerMessage::setCpu(const Cpu &value)
{
    cpu = value;
}

QString ServerMessage::getNomServeur() const
{
    return nomServeur;
}

void ServerMessage::setNomServeur(const QString &value)
{
    nomServeur = value;
}


QString ServerMessage::getType() const
{
    return type;
}

void ServerMessage::setType(const QString &value)
{
    type = value;
}


// Lecture et écriture des objets en JSON

void ServerMessage::read(const QJsonObject &json)
{
    type = json["type"].toString();
    nomServeur = json["nom"].toString();

    QJsonObject jsonCPU = json["cpu"].toObject();
    QJsonObject jsonDisk = json["disk"].toObject();
    QJsonObject jsonNetwork = json["network"].toObject();
    QJsonObject jsonProcess = json["process"].toObject();
    QJsonObject jsonRAM = json["ram"].toObject();
    QJsonObject jsonServer = json["server"].toObject();

    cpu.read(jsonCPU);
    disque.read(jsonDisk);
    processus.read(jsonProcess);
    network.read(jsonNetwork);
    ram.read(jsonRAM);
    serveur.read(jsonServer);
}

void ServerMessage::write(QJsonObject &json)
{
    json["type"] = type;
    json["nom"] = nomServeur;

    QJsonObject js;

    cpu.write(js);
    json["cpu"] = js;

    disque.write(js);
    json["disk"] = js;

    processus.write(js);
    json["process"] = js;

    network.write(js);
    json["network"] = js;

    ram.write(js);
    json["ram"] = js;

    serveur.write(js);
    json["server"] = js;

}
