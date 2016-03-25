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

    updateObserver();
}

void Ram::write(QJsonObject &json) const
{
    json["type"] = type;
    json["nom"] = nom;
    json["capacite"] = capacite;
    json["utilise"] = utiliser;
    json["disponible"] = disponible;
}

void Ram::updateObserver()
{

        if (observer != NULL)
        {
            QString cp = QString::number(utiliser) + " Mo";
            QString cpFree = QString::number(disponible) + " Mo";
            QString cpMax = QString::number(capacite) + " Mo";

            int per = (int) ((utiliser * 100) / capacite);

            ((MemoryTabDetails*)observer)->updateData(nom, cp, cpFree, cpMax, per);
            ((MemoryTabDetails*)observer)->addData(1, utiliser);

            ((PerformanceCustomButton*)buttonObserver)->updateValues(QString::number(per)+" %", cp);
        }

}

