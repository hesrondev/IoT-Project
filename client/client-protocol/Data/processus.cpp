#include "processus.h"


Processus::Processus() : ServerMessage("PROCESS")
{
     nom ="processus1";
     pid =1;
     status=true;
     utilisateur="user1";
     uid =1;
     taille=1.2;
}

void Processus::read(const QJsonObject &json)
{
    type = json["type"].toString();
    nom = json["nom"].toString();
    pid = json["pid"].toInt();
    status = json["status"].toBool();
    utilisateur = json["utilisateur"].toString();
    uid = json["uid"].toInt();
    taille = json["taille"].toDouble();
}

void Processus::write(QJsonObject &json) const
{
    json["type"] = type;
    json["nom"] = nom;
    json["pid"] = pid;
    json["status"] = status;
    json["utilisateur"] = utilisateur;
    json["uid"] = uid ;
    json["taille"] = taille;
}

