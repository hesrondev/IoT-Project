#include "client.h"

Client::Client() : ServerMessage("CLIENT"), dateDebutConnexion(QDateTime::currentDateTime()), dateDerniereConnexion(QDateTime::currentDateTime())
{
    adresseIp = "0.0.0.0";
    IdConnexion = 0;
    nom ="client";
    status = true;

    // timers, nombre de fois par seconde

    processFq = 1;
    cpuFq = 1;
    ramFq = 1;
    diskFq = 1;
    networkFq = 1;
    serverFq = 1;
    globalFq = 1;

    globalSendingState = true;
}

void Client::read(const QJsonObject &json)
{
    type = json["type"].toString();
    adresseIp = json["adresseIp"].toString();
    IdConnexion = json["adresseIp"].toInt();
    nom = json["nom"].toString();
    status = json["status"].toBool();
    dateDebutConnexion.fromString(json["dateDebutConnexion"].toString());
    dateDerniereConnexion.fromString(json["dateDerniereConnexion"].toString());

    // timers

    processFq = json["processFq"].toInt();
    cpuFq = json["cpuFq"].toInt();
    ramFq = json["ramFq"].toInt();
    diskFq = json["diskFq"].toInt();
    networkFq = json["networkFq"].toInt();
    serverFq = json["serverFq"].toInt();
    globalFq = json["globalFq"].toInt();

    globalSendingState = json["globalSendingState"].toBool();

}

void Client::write(QJsonObject &json)
{
    json["type"] = type;
    json["adresseIp"] =   adresseIp;
    json["IdConnexion"] = IdConnexion ;
    json["nom"] = nom;
    json["status"] =  status;
    json["dateDebutConnexion"] =  dateDebutConnexion.toString();

    dateDerniereConnexion = QDateTime::currentDateTime();
    json["dateDerniereConnexion"] =  dateDerniereConnexion.toString();

    // timers

    json["processFq"] = processFq;
    json["cpuFq"] = cpuFq;
    json["ramFq"] = ramFq;
    json["diskFq"] = diskFq;
    json["networkFq"] = networkFq;
    json["serverFq"] = serverFq;
    json["globalFq"] = globalFq;

    json["globalSendingState"] = globalSendingState;

}

void Client::disconnect()
{
    status = false;
}

//

void Client::setComponentsParams(int pro, int cpu, int mem, int disk, int eth)
{
    processFq = pro;
    cpuFq = cpu;
    ramFq = mem;
    diskFq = disk;
    networkFq = eth;

    // global param off
    globalSendingState = false;
}

// Setters

void Client::setNom(const QString &value)
{
    nom = value;
}

void Client::setGlobalFq(int value)
{
    globalFq = value;

    // global param on
    globalSendingState = true;
}

void Client::setGlobalSendingState(bool value)
{
    globalSendingState = value;
}
