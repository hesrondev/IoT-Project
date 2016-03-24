#ifndef PROCESSUS_H
#define PROCESSUS_H

#include <iostream>
#include <QJsonObject>

#include "component.h"

using namespace std;

class Processus : public Component
{
public:
    Processus();

    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;

    void updateData();

    virtual ~Processus();

private:
    QString nom;
    int pid;
    bool status;
    QString utilisateur;
    int uid ;
    double taille;
};

#endif // PROCESSUS_H
