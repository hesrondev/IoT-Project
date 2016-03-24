#ifndef NETWORK_H
#define NETWORK_H
#include <iostream>
#include <QJsonObject>

#include "component.h"

using namespace std;

class Network : public Component
{
public:
    Network();

    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;

    void updateData();

    void setIpv4(const QString &value);

    void setIpv6(const QString &value);

    virtual ~Network();

private:
    QString nom;
    double debitEnvoi;
    double debitRecu;
    QString ipv4;
    QString ipv6;

};

#endif // NETWORK_H
