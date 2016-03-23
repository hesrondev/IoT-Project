#include "memorytabdetails.h"

MemoryTabDetails::MemoryTabDetails(QString title, QString subTitle, QString graphLegend) :
    PerformanceGraph(title, subTitle, graphLegend)
{

    // ProgressBar RAM use
    QLabel *ramLabel = new QLabel("Status de la RAM");

    memoryProgressBar = new QProgressBar();
    memoryProgressBar->setMinimumHeight(40);

    // Values
    QHBoxLayout *hlayout = new QHBoxLayout();
    QGridLayout *glayout = new QGridLayout();
    glayout->setMargin(0);
    glayout->setHorizontalSpacing(20);

    hlayout->addLayout(glayout);
    hlayout->addStretch(1);

    QLabel *usedLabel = new QLabel("En cours d'utilisation");
    usedValueLabel = new QLabel("3200 Mo");
    usedValueLabel->setObjectName("perf-value");

    QLabel *freeLabel = new QLabel("Disponible");
    freeValueLabel = new QLabel("777 Mo");
    freeValueLabel->setObjectName("perf-value");

    QLabel *maxLabel = new QLabel("Capacité");
    maxValueLabel = new QLabel("4000 Mo");
    maxValueLabel->setObjectName("perf-value");

    glayout->addWidget(usedLabel, 0, 0);
    glayout->addWidget(freeLabel, 0, 1);
    glayout->addWidget(usedValueLabel, 1, 0);
    glayout->addWidget(freeValueLabel, 1, 1);
    glayout->addWidget(maxLabel, 2, 0);
    glayout->addWidget(maxValueLabel, 3, 0);

    // Layering
    vlayout->addWidget(ramLabel);
    vlayout->addWidget(memoryProgressBar);
    vlayout->addLayout(hlayout);
    vlayout->addStretch(1);
}


// MAJ de l'affichage

void MemoryTabDetails::updateData(const QString &nom, const QString &cp, const QString &cpFree, const QString &cpMax, const int &per)
{
    subTitleLabel->setText(nom);
    usedValueLabel->setText(cp);
    freeValueLabel->setText(cpFree);
    maxValueLabel->setText(cpMax);

    memoryProgressBar->setValue(per);
}
