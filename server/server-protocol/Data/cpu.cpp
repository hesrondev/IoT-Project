#include "cpu.h"

Cpu::Cpu() : Component("CPU")
{
     nom ="cpu";
     tauxUtilisation = (int)rand() / RAND_MAX;
     vitesse = (double)rand() / RAND_MAX;
     vitesseMax = (double)rand() / RAND_MAX;
     nombreCoeurs = (int)rand() / RAND_MAX;
     nombreProcessus = (int)rand() / RAND_MAX;
     nombreThreads = (int)rand() / RAND_MAX;
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

// Mise à jour

void Cpu::updateData()
{
    nom = "cpu";
    tauxUtilisation = (int)rand() / RAND_MAX;
    vitesse = (double)rand() / RAND_MAX;
    vitesseMax = (double)rand() / RAND_MAX;
    nombreCoeurs = (int)rand() / RAND_MAX;
    nombreProcessus = (int)rand() / RAND_MAX;
    nombreThreads = (int)rand() / RAND_MAX;
}

Cpu::~Cpu()
{

}

