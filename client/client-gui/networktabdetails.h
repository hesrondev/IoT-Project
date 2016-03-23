#ifndef NETWORKTABDETAILS_H
#define NETWORKTABDETAILS_H

#include "performancegraph.h"
#include "client-gui/observer.h"

class NetworkTabDetails : public PerformanceGraph, public Observer
{
public:
    NetworkTabDetails(QString title, QString subTitle, QString graphLegend);

    void updateData(const QString &nom, const QString &de, const QString &dr, const QString &ipv4, const QString &ipv6);

private:
    QLabel *dataInValueLabel;
    QLabel *dataOutValueLabel;
    QLabel *ipv4ValueLabel;
    QLabel *ipv6ValueLabel;
};

#endif // NETWORKTABDETAILS_H
