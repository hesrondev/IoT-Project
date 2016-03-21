#ifndef CPU_H
#define CPU_H
#include <iostream>
#include <QJsonObject>

#include "serverMessage.h"

using namespace std;


class Cpu : public ServerMessage
{
public:
    Cpu();
    QString getNom() const;
    void setNom(const QString &value);

    int getTauxUtilisation() const;
    void setTauxUtilisation(int value);

    double getVitesse() const;
    void setVitesse(double value);

    double getVitesseMax() const;
    void setVitesseMax(double value);

    int getNombreCoeurs() const;
    void setNombreCoeurs(int value);

    int getNombreProcessus() const;
    void setNombreProcessus(int value);

    int getNombreThreads() const;
    void setNombreThreads(int value);

    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;

private :
    QString nom ;
    int tauxUtilisation ;
    double vitesse;
    double vitesseMax;
    int nombreCoeurs;
    int nombreProcessus;
    int nombreThreads;


};

#endif // CPU_H
