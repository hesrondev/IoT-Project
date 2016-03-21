#include "ram.h"

Ram::Ram()
{
    nom = "Mémoire RAM";
    capacite =1.2;
    utiliser=1.3;
    disponible=2.5;
}

double Ram::getCapacite() const
{
    return capacite;
}

void Ram::setCapacite(double value)
{
    capacite = value;
}

double Ram::getUtiliser() const
{
    return utiliser;
}

void Ram::setUtiliser(double value)
{
    utiliser = value;
}

double Ram::getDisponible() const
{
    return disponible;
}

void Ram::setDisponible(double value)
{
    disponible = value;
}

void Ram::read(const QJsonObject &json)
{
    nom = json["nom"].toString();
    capacite = json["capacite"].toDouble();
    utiliser = json["utilise"].toDouble();
    disponible= json["disponible"].toDouble();
}

void Ram::write(QJsonObject &json) const
{
    json["nom"] = nom;
    json["capacite"] = capacite;
    json["utilise"] = utiliser;
    json["disponible"] = disponible;
}

