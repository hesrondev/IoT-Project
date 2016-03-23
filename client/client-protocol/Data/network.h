#ifndef NETWORK_H
#define NETWORK_H
#include <iostream>
#include <QJsonObject>

#include "serverMessage.h"
#include "client-gui/networktabdetails.h"
#include "client-gui/observer.h"

using namespace std;

class Network : public ServerMessage
{
public:
    Network();

    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;

    void updateObserver();

private:
    QString nom;
    double debitEnvoi;
    double debitRecu;
    QString ipv4;
    QString ipv6;

};

#endif // NETWORK_H
