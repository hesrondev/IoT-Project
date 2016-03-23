#ifndef CPU_H
#define CPU_H
#include <iostream>
#include <QJsonObject>

#include "serverMessage.h"
#include "client-gui/processortabdetails.h"

using namespace std;


class Cpu : public ServerMessage
{
public:
    Cpu();

    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;

    void updateObserver();

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
