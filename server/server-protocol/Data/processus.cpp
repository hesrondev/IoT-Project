#include "processus.h"


Processus::Processus() : Component("PROCESS")
{
     nom = "processus1";
     pid = (int)rand() / RAND_MAX;
     status = true;
     utilisateur = "user1";
     uid = (int)rand() / RAND_MAX;
     taille = (double)rand() / RAND_MAX;
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

void Processus::updateData()
{
    nom ="processus1";
    pid = (int)rand() / RAND_MAX;
    status = true;
    utilisateur = "user1";
    uid = (int)rand() / RAND_MAX;
    taille = (double)rand() / RAND_MAX;
}

Processus::~Processus()
{

}

