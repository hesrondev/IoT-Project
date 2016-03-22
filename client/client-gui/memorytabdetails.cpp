#include "memorytabdetails.h"

MemoryTabDetails::MemoryTabDetails(QString title, QString subTitle, QString graphLegend) :
    PerformanceGraph(title, subTitle, graphLegend)
{

    // ProgressBar RAM use
    QLabel *ramLabel = new QLabel("Status de la RAM");

    QProgressBar *memoryProgressBar = new QProgressBar();
    memoryProgressBar->setMinimumHeight(40);

    // Values
    QHBoxLayout *hlayout = new QHBoxLayout();
    QGridLayout *glayout = new QGridLayout();
    glayout->setMargin(0);
    glayout->setHorizontalSpacing(20);

    hlayout->addLayout(glayout);
    hlayout->addStretch(1);

    QLabel *usedLabel = new QLabel("En cours d'utilisation");
    QLabel *usedValueLabel = new QLabel("3,2 Go");
    usedValueLabel->setObjectName("perf-value");

    QLabel *freeLabel = new QLabel("Disponible");
    QLabel *freeValueLabel = new QLabel("777 Mo");
    freeValueLabel->setObjectName("perf-value");

    glayout->addWidget(usedLabel, 0, 0);
    glayout->addWidget(freeLabel, 0, 1);
    glayout->addWidget(usedValueLabel, 1, 0);
    glayout->addWidget(freeValueLabel, 1, 1);

    // Layering
    vlayout->addWidget(ramLabel);
    vlayout->addWidget(memoryProgressBar);
    vlayout->addLayout(hlayout);
    vlayout->addStretch(1);
}
