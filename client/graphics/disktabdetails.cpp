#include "disktabdetails.h"

DiskTabDetails::DiskTabDetails(QString title, QString subTitle, QString graphLegend) :
    PerformanceGraph(title, subTitle, graphLegend)
{


    // Layering

    vlayout->addStretch(1);
}
