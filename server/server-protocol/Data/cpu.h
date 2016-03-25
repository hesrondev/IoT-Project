#ifndef CPU_H
#define CPU_H
#include <iostream>
#include <QJsonObject>

#include "component.h"

using namespace std;


class Cpu : public Component
{
public:
    Cpu();
    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;

    void updateData();
    virtual ~Cpu();

private :

    QString nom ;
    double tauxUtilisation ;
    double vitesse;
    double vitesseMax;
    int nombreCoeurs;
    int nombreProcessus;
    int nombreThreads;


};

#endif // CPU_H
