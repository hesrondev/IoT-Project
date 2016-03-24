#include "client.h"

Client::Client()
{
}

Client::Client(int id, QTcpSocket *socket) : dateDebutConnexion(QDateTime::currentDateTime()), dateDerniereConnexion(QDateTime::currentDateTime())
{
    this->socket = socket;

    type = "CLIENT";
    adresseIp ="192.168.1.1";
    IdConnexion = id;
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

    processTimer = new TimerCustom(socket);
    cpuTimer = new TimerCustom(socket);
    ramTimer = new TimerCustom(socket);
    diskTimer = new TimerCustom(socket);
    networkTimer = new TimerCustom(socket);
    serverTimer = new TimerCustom(socket);
    globalTimer = new TimerCustom(socket);
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


    // Réactualisation des timers

    cout << "GLOBAL -- globalSendingState : " << globalSendingState << endl;

    stopTimers();
    startTimers();

}

void Client::write(QJsonObject &json)
{
    json["type"] = type;
    json["adresseIp"] =   adresseIp;
    json["IdConnexion"] = IdConnexion ;
    json["nom"] = nom;
    json["status"] =  status;
    json["dateDebutConnexion"] =  dateDebutConnexion.toString();

    // set last connection date

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

}


// Fonction d'arrêt de tous les minuteurs

void Client::stopTimers()
{

    processTimer->stop();
    cpuTimer->stop();
    ramTimer->stop();
    diskTimer->stop();
    networkTimer->stop();
    serverTimer->stop();

    globalTimer->stop();
}

void Client::startTimers()
{
    int ms = 1000;

    // si envoie global non activé
    if (!globalSendingState)
    {
        processTimer->start(ms * processFq);
        cpuTimer->start(ms * cpuFq);
        ramTimer->start(ms * ramFq);
        diskTimer->start(ms * diskFq);
        networkTimer->start(ms * networkFq);
        serverTimer->start(ms * serverFq);
    }
    else
        globalTimer->start(ms * globalFq);
}

void Client::disconnect()
{
    status = false;
}
