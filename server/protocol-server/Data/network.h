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

private:
    QString nom;
    double debitEnvoi;
    double debitRecu;

};

#endif // NETWORK_H
