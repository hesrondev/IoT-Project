#ifndef RAM_H
#define RAM_H
#include <iostream>
#include <QJsonObject>

#include "component.h"

using namespace std;


class Ram : public Component
{
public:
    Ram();

    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;

    void updateData();

    virtual ~Ram();

private:
    QString nom;
    double capacite;
    double utiliser;
    double disponible;
};

#endif // RAM_H
