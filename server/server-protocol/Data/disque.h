#ifndef DISQUE_H
#define DISQUE_H
#include <iostream>
#include <QJsonObject>

#include "component.h"

using namespace std;


class Disque : public Component
{
public:
    Disque();

    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;

    void updateData();
    virtual ~Disque();

private:
    QString nom;
    double capaciteUtiliser;
    double capaciteLibre;
    double memoireMax;
};

#endif // DISQUE_H
