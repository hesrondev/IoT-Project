#include "ram.h"

Ram::Ram() : ServerMessage("RAM")
{
    nom = "Mémoire RAM";
    capacite = (double)rand() / RAND_MAX;
    utiliser = (double)rand() / RAND_MAX;
    disponible = (double)rand() / RAND_MAX;
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
    type = json["type"].toString();
    nom = json["nom"].toString();
    capacite = json["capacite"].toDouble();
    utiliser = json["utilise"].toDouble();
    disponible= json["disponible"].toDouble();
}

void Ram::write(QJsonObject &json) const
{
    json["type"] = type;
    json["nom"] = nom;
    json["capacite"] = capacite;
    json["utilise"] = utiliser;
    json["disponible"] = disponible;
}

