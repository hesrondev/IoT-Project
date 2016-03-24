#include "client.h"

Client::Client()
{
}

Client::Client(int id, QTcpSocket *socket) : dateDebutConnexion(QDateTime::currentDateTime()), dateDerniereConnexion(QDateTime::currentDateTime())
{
    this->socket = socket;

    adresseIp = "0.0.0.0";
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

    processTimer = new QTimer();
    cpuTimer = new QTimer();
    ramTimer = new QTimer();
    diskTimer = new QTimer();
    networkTimer = new QTimer();
    serverTimer = new QTimer();
}

void Client::read(const QJsonObject &json)
{
    adresseIp = json["adresseIp"].toString();
    IdConnexion = json["adresseIp"].toInt();
    nom = json["nom"].toString();
    status = json["status"].toBool();
    dateDebutConnexion.fromString(json["dateDebutConnexion"].toString());
    dateDerniereConnexion.fromString(json["dateDerniereConnexion"].toString());
}

void Client::write(QJsonObject &json)
{
    json["adresseIp"] =   adresseIp;
    json["IdConnexion"] = IdConnexion ;
    json["nom"] = nom;
    json["status"] =  status;
    json["dateDebutConnexion"] =  dateDebutConnexion.toString();

    // set last connection date

    dateDerniereConnexion = QDateTime::currentDateTime();
    json["dateDerniereConnexion"] =  dateDerniereConnexion.toString();
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
}

void Client::startTimers()
{
    int ms = 1000;

    processTimer->start(ms * processFq);
    cpuTimer->start(ms * cpuFq);
    ramTimer->start(ms * ramFq);
    diskTimer->start(ms * diskFq);
    networkTimer->start(ms * networkFq);
    serverTimer->start(ms * serverFq);
}

void Client::disconnect()
{
    status = false;
}


/* **** Getters and Setters *** */

int Client::getIdConnexion() const
{
    return IdConnexion;
}

void Client::setIdConnexion(int value)
{
    IdConnexion = value;
}

QString Client::getNom() const
{
    return nom;
}

void Client::setNom(const QString &value)
{
    nom = value;
}
