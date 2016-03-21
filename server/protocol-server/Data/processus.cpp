#include "processus.h"


Processus::Processus()
{
     nom ="processus1";
     pid =1;
     status=true;
     utilisateur="user1";
     uid =1;
     taille=1.2;
}

QString Processus::getNom() const
{
    return nom;
}

void Processus::setNom(const QString &value)
{
    nom = value;
}

int Processus::getPid() const
{
    return pid;
}

void Processus::setPid(int value)
{
    pid = value;
}

bool Processus::getStatus() const
{
    return status;
}

void Processus::setStatus(bool value)
{
    status = value;
}

QString Processus::getUtilisateur() const
{
    return utilisateur;
}

void Processus::setUtilisateur(const QString &value)
{
    utilisateur = value;
}

int Processus::getUid() const
{
    return uid;
}

void Processus::setUid(int value)
{
    uid = value;
}

double Processus::getTaille() const
{
    return taille;
}

void Processus::setTaille(double value)
{
    taille = value;
}

void Processus::read(const QJsonObject &json)
{
    nom = json["nom"].toString();
    pid = json["pid"].toInt();
    status = json["status"].toBool();
    utilisateur = json["utilisateur"].toString();
    uid = json["uid"].toInt();
    taille = json["taille"].toDouble();
}

void Processus::write(QJsonObject &json) const
{
      json["nom"] = nom;
      json["pid"] = pid;
      json["status"] = status;
      json["utilisateur"] = utilisateur;
      json["uid"] = uid ;
      json["taille"] = taille;

}

