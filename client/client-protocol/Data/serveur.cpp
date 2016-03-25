#include "serveur.h"

Serveur::Serveur() : ServerMessage("server"), clients()
{
    nom = "serveur";
    ip = "0.0.0.0";
    port = 0;
}

Serveur::Serveur(QList<Client *> lc) : ServerMessage("server"), clients(lc)
{
     nom = "serveur";
     ip = "0.0.0.0";
     port = 0;
}

void Serveur::read(const QJsonObject &json)
{
    type = json["type"].toString();
    nom = json["nom"].toString();
    ip = json["ip"].toString();
    port = json["port"].toInt();

    clients.clear();
    QJsonArray clientArray = json["lclient"].toArray();

    for(int i = 0 ; i < clientArray.size(); ++i)
    {
        QJsonObject clientObject = clientArray[i].toObject();
        Client client;
        client.read(clientObject);
        clients.append(&client);
    }

    // MAJ
    updateObserver();
 }

void Serveur::write(QJsonObject &json)
{
    json["type"] = type;
    json["nom"] = nom ;
    json["ip"] = ip;
    json["port"] = port;

    QJsonArray clientArray;
    foreach(Client* c , clients){
        QJsonObject clientObject;

        c->write(clientObject);
        clientArray.append(clientObject);
    }
    json["lclient"] = clientArray;

}


// Update observer

void Serveur::updateObserver()
{
    if (observer != NULL)
    {
        ((ServerTab*)observer)->setTableRowCount(clients.size());

        // Pour chaque client on insère dans le tableau
        foreach (Client *cl, clients) {

            QString status = "connecté";

            QString format = "dd/MM/yyyy à hh:mm";
            QString dateDeb = cl->dateDebutConnexion.toString(format);
            QString dateFin = cl->dateDerniereConnexion.toString(format);

            if (!cl->status)
                status = "déconnecté";

            ((ServerTab*)observer)->addClientLine(cl->nom, QString::number(cl->IdConnexion),
                                                  cl->adresseIp, status, dateDeb, dateFin);

            qDebug() << "client : " << cl->nom << " " << dateDeb << endl;
        }
    }
}

