#ifndef NETWORK_H
#define NETWORK_H
#include <iostream>
#include <QJsonObject>

#include "serverMessage.h"

using namespace std;

class Network : public ServerMessage
{
public:
    Network();
    double getDebitEnvoi() const;
    void setDebitEnvoi(double value);

    double getDebitRecu() const;
    void setDebitRecu(double value);

    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;

    void setIpv4(const QString &value);

    void setIpv6(const QString &value);

private:
    QString nom;
    double debitEnvoi;
    double debitRecu;
    QString ipv4;
    QString ipv6;

};

#endif // NETWORK_H
