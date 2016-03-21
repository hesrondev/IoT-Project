#include "network.h"

Network::Network()
{
    nom = "Network";
    debitEnvoi = 1.1;
    debitRecu = 1.2;
}

double Network::getDebitEnvoi() const
{
    return debitEnvoi;
}

void Network::setDebitEnvoi(double value)
{
    debitEnvoi = value;
}

double Network::getDebitRecu() const
{
    return debitRecu;
}

void Network::setDebitRecu(double value)
{
    debitRecu = value;
}

void Network::read(const QJsonObject &json)
{
    nom = json["nom"].toString();
    debitEnvoi = json["debitEnvoi"].toDouble();
    debitRecu = json["debitRecu"].toDouble();

}

void Network::write(QJsonObject &json) const
{
    json["nom"] = nom;
    json["debitEnvoi"] = debitEnvoi;
    json["debitRecu"] = debitRecu;
}

