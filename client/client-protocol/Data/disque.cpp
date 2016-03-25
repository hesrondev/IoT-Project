#include "disque.h"

Disque::Disque() : ServerMessage("DISK")
{
     nom ="disk";
     capaciteUtiliser =1.0;
     capaciteLibre =1.2;
     memoireMax =1.3;

}

void Disque::read(const QJsonObject &json)
{
    type = json["type"].toString();
    nom = json["nom"].toString();
    capaciteUtiliser = json["capaciteUtiliser"].toDouble();
    capaciteLibre  = json["capaciteLibre"].toDouble();
    memoireMax = json["memoireMax"].toDouble();;

    updateObserver();
}

void Disque::write(QJsonObject &json) const
{
    json["type"] = type;
    json["nom"] = nom;
    json["capaciteUtiliser"] = capaciteUtiliser;
    json["capaciteLibre"] = capaciteLibre;
    json["memoireMax"] = memoireMax;
}

void Disque::updateObserver()
{

    if (observer != NULL)
    {
        QString cpUsed = QString::number(capaciteUtiliser) + " Go";
        QString cpFree = QString::number(capaciteLibre) + " Go";
        QString cpMax = QString::number(memoireMax) + " Go";

        ((DiskTabDetails*)observer)->updateData(nom, cpUsed, cpFree, cpMax);
        //((DiskTabDetails*)observer)->addData(1, capaciteUtiliser);
    }
}

