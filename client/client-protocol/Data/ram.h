#ifndef RAM_H
#define RAM_H
#include <iostream>
#include <QJsonObject>

#include "serverMessage.h"

using namespace std;


class Ram : public ServerMessage
{
public:
    Ram();
    double getCapacite() const;
    void setCapacite(double value);

    double getUtiliser() const;
    void setUtiliser(double value);

    double getDisponible() const;
    void setDisponible(double value);

    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;

private:
    QString nom;
    double capacite;
    double utiliser;
    double disponible;
};

#endif // RAM_H
