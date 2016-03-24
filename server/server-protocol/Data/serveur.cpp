#include "serveur.h"

Serveur::Serveur(QList<Client *> clients) : Component("SERVER"), listClients(clients)
{
     nom = "serveur";
     ip = "192.168.1.1";
     port = 1010;
}

void Serveur::read(const QJsonObject &json)
{
    type = json["type"].toString();
    nom = json["nom"].toString();
    ip = json["ip"].toString();
    port = json["port"].toInt();

    listClients.clear();
    QJsonArray clientArray = json["lclient"].toArray();

    for(int i = 0 ; i < clientArray.size(); ++i)
    {
        QJsonObject clientObject = clientArray[i].toObject();
        Client client;
        client.read(clientObject);
        listClients.append(&client);
    }
 }

void Serveur::write(QJsonObject &json)
{
    json["type"] = type;
    json["nom"] = nom ;
    json["ip"] = ip;
    json["port"] = port;

    QJsonArray clientArray;
    foreach(Client* c , listClients){
        QJsonObject clientObject;

        c->write(clientObject);
        clientArray.append(clientObject);
    }
    json["lclient"] = clientArray;

}

void Serveur::updateData()
{

}

void Serveur::updateData(QList<Client *> lc)
{
    listClients = lc;
}

Serveur::~Serveur()
{

}

