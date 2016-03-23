#ifndef RAM_H
#define RAM_H
#include <iostream>
#include <QJsonObject>

#include "serverMessage.h"
#include "client-gui/memorytabdetails.h"
#include "client-gui/observer.h"

using namespace std;


class Ram : public ServerMessage
{
public:
    Ram();

    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;

    void updateObserver();

private:
    QString nom;
    double capacite;
    double utiliser;
    double disponible;
};

#endif // RAM_H
