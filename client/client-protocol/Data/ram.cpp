#include "ram.h"

Ram::Ram() : ServerMessage("RAM")
{
    nom = "Mémoire RAM";
    capacite = 1.2;
    utiliser = 1.3;
    disponible = 2.5;
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

