#include "serveur.h"

Serveur::Serveur(QList<Client *> clients) : listClients(clients)
{
     nom = "serveur";
     ip = "192.168.1.1";
     port = 1010;
}

QString Serveur::getNom() const
{
    return nom;
}

void Serveur::setNom(const QString &value)
{
    nom = value;
}

QString Serveur::getIp() const
{
    return ip;
}

void Serveur::setIp(const QString &value)
{
    ip = value;
}

int Serveur::getPort() const
{
    return port;
}

void Serveur::setPort(int value)
{
    port = value;
}

QList<Client *> Serveur::getListClients() const
{
    return listClients;
}

void Serveur::setListClients(const QList<Client*> &value)
{
    listClients = value;
}

void Serveur::read(const QJsonObject &json)
{
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

