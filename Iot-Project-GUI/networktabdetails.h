#ifndef NETWORKTABDETAILS_H
#define NETWORKTABDETAILS_H

#include "performancegraph.h"

class NetworkTabDetails : public PerformanceGraph
{
public:
    NetworkTabDetails(QString title, QString subTitle, QString graphLegend);
};

#endif // NETWORKTABDETAILS_H
