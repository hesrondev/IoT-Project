#include "network.h"

Network::Network() : ServerMessage("NETWORK")
{
    nom = "network";
    debitEnvoi = 1.1;
    debitRecu = 1.2;
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

    updateObserver();
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

void Network::updateObserver()
{

        if (observer != NULL)
        {
            QString de = QString::number(debitEnvoi) + " Kbits/s";
            QString dr = QString::number(debitRecu) + " Kbits/s";

            ((NetworkTabDetails*)observer)->updateData(nom, de, dr, ipv4, ipv6);
            ((NetworkTabDetails*)observer)->addData(1, debitEnvoi);
            ((NetworkTabDetails*)observer)->addData(2, debitRecu);

            ((PerformanceCustomButton*)buttonObserver)->updateValues(de, dr);
        }

}

