#ifndef NETWORK_H
#define NETWORK_H
#include <iostream>
#include <QJsonObject>

using namespace std;

class Network
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
