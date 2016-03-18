#ifndef DISKTABDETAILS_H
#define DISKTABDETAILS_H

#include <QGroupBox>

#include "performancegraph.h"
#include "devicecustombutton.h"

class DiskTabDetails : public PerformanceGraph
{
public:
    DiskTabDetails(QString title, QString subTitle, QString graphLegend);
};

#endif // DISKTABDETAILS_H
