#include "disktabdetails.h"

DiskTabDetails::DiskTabDetails(QString title, QString subTitle, QString graphLegend) :
    PerformanceGraph(title, subTitle, graphLegend)
{

    // Disques

    QGroupBox *devicesGBox = new QGroupBox("Périphériques et lecteurs");
    QGridLayout *deviceLayout = new QGridLayout();
    deviceLayout->setAlignment(Qt::AlignLeft);
    devicesGBox->setLayout(deviceLayout);

    deviceLayout->addWidget(new DeviceCustomButton("Disque (C:)", 1), 0, 0);
    deviceLayout->addWidget(new DeviceCustomButton("Disque (D:)", 1), 0, 1);
    deviceLayout->addWidget(new DeviceCustomButton("Disque (D:)", 2), 1, 0);

    // Layering

    vlayout->addWidget(devicesGBox);
    vlayout->addStretch(1);
}
