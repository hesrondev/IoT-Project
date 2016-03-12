#include "memorytabdetails.h"

MemoryTabDetails::MemoryTabDetails(QString title, QString subTitle, QString graphLegend) :
    PerformanceGraph(title, subTitle, graphLegend)
{

    // ProgressBar RAM use
    QLabel *ramLabel = new QLabel("Status de la RAM");
    QGroupBox *ramUseGBox = new QGroupBox();
    ramUseGBox->setMinimumHeight(70);

    //

    // Layering
    vlayout->addWidget(ramLabel);
    vlayout->addWidget(ramUseGBox);
    vlayout->addStretch(1);
}
