#include "cpu.h"

Cpu::Cpu() : ServerMessage("CPU")
{
     nom = "Processeur";
     tauxUtilisation = 1;
     vitesse = 2;
     vitesseMax = 2.0;
     nombreCoeurs = 3;
     nombreProcessus = 4;
     nombreThreads = 7;
}


// methode json read
void Cpu::read(const QJsonObject &json)
{
    type = json["type"].toString();
    nom = json["nom"].toString();
    tauxUtilisation = json["tauxUtilisation"].toInt();
    vitesse = json["vitesse"].toDouble();
    vitesseMax = json["vitesseMax"].toDouble();
    nombreCoeurs= json["nombreCoeurs"].toInt();
    nombreProcessus=json["nombreProcessus"].toInt();
    nombreThreads= json["nombreThreads"].toInt();
}
// methode json write
void Cpu::write(QJsonObject &json) const
{
    json["type"] = type;
    json["nom"]=  nom ;
    json["tauxUtilisation"]= tauxUtilisation ;
    json["vitesse"]= vitesse;
    json["vitesseMax"]= vitesseMax;
    json["nombreCoeurs"]= nombreCoeurs;
    json["nombreProcessus"]= nombreProcessus;
    json["nombreThreads"]= nombreThreads;
}

