#ifndef PROCESSORTABDETAILS_H
#define PROCESSORTABDETAILS_H

#include "performancegraph.h"
#include "observer.h"

class ProcessorTabDetails : public PerformanceGraph, public Observer
{

public:
    ProcessorTabDetails(QString title, QString subTitle, QString graphLegend);

    void updateData(const QString &nom, const QString &tU, const QString &speed, const QString &maxSpeed,
                const QString &cores, const QString &processes, const QString &threads);

private:

    QLabel *useValueLabel;

    QLabel *speedValueLabel;

    QLabel *processValueLabel;

    QLabel *threadValueLabel;

    QLabel *timeValueLabel;

    QLabel *speedMaxValueLabel;

    QLabel *coreValueLabel;


};

#endif // PROCESSORTABDETAILS_H
