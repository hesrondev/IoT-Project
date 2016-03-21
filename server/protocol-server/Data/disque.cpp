#include "disque.h"

Disque::Disque()
{
     nom ="disk";
     capaciteUtiliser =1.0;
     capaciteLibre =1.2;
     memoireMax =1.3;

}

QString Disque::getNom() const
{
    return nom;
}

void Disque::setNom(const QString &value)
{
    nom = value;
}

double Disque::getCapaciteUtiliser() const
{
    return capaciteUtiliser;
}

void Disque::setCapaciteUtiliser(double value)
{
    capaciteUtiliser = value;
}

double Disque::getCapaciteLibre() const
{
    return capaciteLibre;
}

void Disque::setCapaciteLibre(double value)
{
    capaciteLibre = value;
}

double Disque::getMemoireMax() const
{
    return memoireMax;
}

void Disque::setMemoireMax(double value)
{
    memoireMax = value;
}

void Disque::read(const QJsonObject &json)
{
    nom = json["nom"].toString();
    capaciteUtiliser = json["capaciteUtiliser"].toDouble();
    capaciteLibre  = json["capaciteLibre"].toDouble();
    memoireMax = json["memoireMax"].toDouble();;
}

void Disque::write(QJsonObject &json) const
{
     json["nom"] = nom;
     json["capaciteUtiliser"] = capaciteUtiliser;
     json["capaciteLibre"] = capaciteLibre;
     json["memoireMax"] = memoireMax;
}

