#ifndef MEMORYTABDETAILS_H
#define MEMORYTABDETAILS_H

#include <QProgressBar>

#include "performancegraph.h"


class MemoryTabDetails : public PerformanceGraph
{
public:
    MemoryTabDetails(QString title, QString subTitle, QString graphLegend);
};

#endif // MEMORYTABDETAILS_H
