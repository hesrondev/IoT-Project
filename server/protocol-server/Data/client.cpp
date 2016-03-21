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

void Client::write(QJsonObject &json) const
{
    json["adresseIp"] =   adresseIp;
    json["IdConnexion"] = IdConnexion ;
    json["nom"] = nom;
    json["status"] =  status;
    json["dateDebutConnexion"] =  dateDebutConnexion.toString();
    json["dateDerniereConnexion"] =  dateDerniereConnexion.toString();
}
