#ifndef DISQUE_H
#define DISQUE_H
#include <iostream>
#include <QJsonObject>

#include "serverMessage.h"
#include "client-gui/disktabdetails.h"

using namespace std;


class Disque : public ServerMessage
{
public:
    Disque();

    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;

    void updateObserver();

private:
    QString nom;
    double capaciteUtiliser;
    double capaciteLibre;
    double memoireMax;
};

#endif // DISQUE_H
