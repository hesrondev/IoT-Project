#ifndef DISKTABDETAILS_H
#define DISKTABDETAILS_H

#include <QGroupBox>

#include "performancegraph.h"
#include "devicecustombutton.h"

class DiskTabDetails : public PerformanceGraph
{
public:
    DiskTabDetails(QString title, QString subTitle, QString graphLegend);

    void updateData(const QString &nom, const QString &cpUsed, const QString &cpFree, const QString &cpMax);

private:

};

#endif // DISKTABDETAILS_H
