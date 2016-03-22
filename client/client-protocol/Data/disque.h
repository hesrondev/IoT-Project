#ifndef DISQUE_H
#define DISQUE_H
#include <iostream>
#include <QJsonObject>

#include "serverMessage.h"

using namespace std;


class Disque : public ServerMessage
{
public:
    Disque();
    QString getNom() const;
    void setNom(const QString &value);

    double getCapaciteUtiliser() const;
    void setCapaciteUtiliser(double value);

    double getCapaciteLibre() const;
    void setCapaciteLibre(double value);

    double getMemoireMax() const;
    void setMemoireMax(double value);

    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;

private:
    QString nom;
    double capaciteUtiliser;
    double capaciteLibre;
    double memoireMax;
};

#endif // DISQUE_H
