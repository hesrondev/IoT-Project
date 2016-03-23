#include "cpu.h"

Cpu::Cpu() : ServerMessage("CPU")
{
     nom ="cpu";
     tauxUtilisation = (int)rand() / RAND_MAX;
     vitesse = (double)rand() / RAND_MAX;
     vitesseMax = (double)rand() / RAND_MAX;
     nombreCoeurs = (int)rand() / RAND_MAX;
     nombreProcessus = (int)rand() / RAND_MAX;
     nombreThreads = (int)rand() / RAND_MAX;
}


QString Cpu::getNom() const
{
    return nom;
}

void Cpu::setNom(const QString &value)
{
    nom = value;
}

int Cpu::getTauxUtilisation() const
{
    return tauxUtilisation;
}

void Cpu::setTauxUtilisation(int value)
{
    tauxUtilisation = value;
}

double Cpu::getVitesse() const
{
    return vitesse;
}

void Cpu::setVitesse(double value)
{
    vitesse = value;
}

double Cpu::getVitesseMax() const
{
    return vitesseMax;
}

void Cpu::setVitesseMax(double value)
{
    vitesseMax = value;
}

int Cpu::getNombreCoeurs() const
{
    return nombreCoeurs;
}

void Cpu::setNombreCoeurs(int value)
{
    nombreCoeurs = value;
}

int Cpu::getNombreProcessus() const
{
    return nombreProcessus;
}

void Cpu::setNombreProcessus(int value)
{
    nombreProcessus = value;
}

int Cpu::getNombreThreads() const
{
    return nombreThreads;
}

void Cpu::setNombreThreads(int value)
{
    nombreThreads = value;
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

