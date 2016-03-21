#include "client.h"

Client::Client()
{
}

Client::Client(QTcpSocket *socket) : dateDebutConnexion(QDateTime::currentDateTime()), dateDerniereConnexion(QDateTime::currentDateTime())
{
    this->socket = socket;

    adresseIp ="192.168.1.1";
    IdConnexion =10 ;
    nom ="client";
    status = true;

    // timers
    frequency = 1;  // nombre de fois par seconde
    defaultTimer = new QTimer();

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
    //dateDerniereConnexion.setDate(QDate::currentDate());
    //dateDerniereConnexion.setTime(QTime::currentTime());
    dateDerniereConnexion = QDateTime::currentDateTime();
    json["dateDerniereConnexion"] =  dateDerniereConnexion.toString();
}


// Fonction d'arrêt de tous les minuteurs

void Client::stopTimers()
{
    defaultTimer->stop();
}
