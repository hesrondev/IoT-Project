#ifndef RAM_H
#define RAM_H
#include <iostream>
#include <QJsonObject>

using namespace std;


class Ram
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
