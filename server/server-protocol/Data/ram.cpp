#include "ram.h"

Ram::Ram() : Component("ram")
{
    nom = "Mémoire RAM";
    capacite = (double)rand() / RAND_MAX;
    utiliser = (double)rand() / RAND_MAX;
    disponible = (double)rand() / RAND_MAX;
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

void Ram::updateData()
{
    nom = "Mémoire RAM";
    capacite = (double)rand() / RAND_MAX;
    utiliser = (double)rand() / RAND_MAX;
    disponible = (double)rand() / RAND_MAX;
}

Ram::~Ram()
{

}

