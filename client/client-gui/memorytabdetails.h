#ifndef MEMORYTABDETAILS_H
#define MEMORYTABDETAILS_H

#include <QProgressBar>

#include "performancegraph.h"
#include "client-gui/observer.h"

class MemoryTabDetails : public PerformanceGraph, public Observer
{
public:
    MemoryTabDetails(QString title, QString subTitle, QString graphLegend);

    void updateData(const QString &nom, const QString &cp, const QString &cpFree, const QString &cpMax, const int &per);

public:
    QLabel *usedValueLabel;
    QLabel *freeValueLabel;
    QLabel *maxValueLabel;
    QProgressBar *memoryProgressBar;

};

#endif // MEMORYTABDETAILS_H
