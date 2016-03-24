#include "network.h"

Network::Network() : Component("network")
{
    nom = "network";
    debitEnvoi = (double)rand() / RAND_MAX;
    debitRecu = (double)rand() / RAND_MAX;
    ipv4 = "0.0.0.0";
    ipv6 = "XXX-ipv6-XXX";
}


void Network::read(const QJsonObject &json)
{
    type = json["type"].toString();
    nom = json["nom"].toString();
    debitEnvoi = json["debitEnvoi"].toDouble();
    debitRecu = json["debitRecu"].toDouble();
    ipv4 = json["ipv4"].toString();
    ipv6 = json["ipv6"].toString();
}

void Network::write(QJsonObject &json) const
{
    json["type"] = type;
    json["nom"] = nom;
    json["debitEnvoi"] = debitEnvoi;
    json["debitRecu"] = debitRecu;
    json["ipv4"] = ipv4;
    json["ipv6"] = ipv6;
}

void Network::updateData()
{
    nom = "network";
    debitEnvoi = (double)rand() / RAND_MAX;
    debitRecu = (double)rand() / RAND_MAX;
    ipv4 = "0.0.0.0";
    ipv6 = "XXX-ipv6-XXX";
}

void Network::setIpv4(const QString &value)
{
    ipv4 = value;
}

void Network::setIpv6(const QString &value)
{
    ipv6 = value;
}

Network::~Network()
{

}
