#include "performancetab.h"

PerformanceTab::PerformanceTab()
{


    // Group buttons box
    QGroupBox *gbox = new QGroupBox();
    gbox->setMinimumWidth(230);

    QVBoxLayout *vl = new QVBoxLayout();
    vl->setMargin(1);
    gbox->setLayout(vl);

    // Buttons
    PerformanceCustomButton *processorButton = new PerformanceCustomButton(QPixmap(":icons/processor"), "Processeur");
    PerformanceCustomButton *memoryButton = new PerformanceCustomButton(QPixmap(":icons/memory"), "Mémoire");
    PerformanceCustomButton *diskButton = new PerformanceCustomButton(QPixmap(":icons/disk"), "Disques");
    PerformanceCustomButton *networkButton = new PerformanceCustomButton(QPixmap(":icons/network"), "Réseau");

    processorButton->setFixedHeight(55);
    memoryButton->setFixedHeight(55);
    diskButton->setFixedHeight(55);
    networkButton->setFixedHeight(55);

    // buttons layering

    vl->addWidget(processorButton);
    vl->addWidget(memoryButton);
    vl->addWidget(diskButton);
    vl->addWidget(networkButton);
    vl->addStretch(1);

    /* *******  Selected item details ****** */

    QGroupBox *detailsGBox = new QGroupBox("Informations");
    vlayout = new QVBoxLayout();
    vlayout->setMargin(15);
    detailsGBox->setLayout(vlayout);

    processorDetails = new ProcessorTabDetails("Processeur", "Intel core i7", "Pourcentage d'utilisation");
    memoryDetails = new MemoryTabDetails("Mémoire", "4,0 Go DDR3", "Utilisation de la mémoire");
    diskDetails = new DiskTabDetails("Disques (C: D:)", "SATA XREHYUFHT556", "Temps d'activité");
    networkDetails = new NetworkTabDetails("Ethernet", "Atheros Qualcom Intel X", "Débit");

    vlayout->addWidget(networkDetails);

    // Layering

    QHBoxLayout *hl = new QHBoxLayout();
    hl->addWidget(gbox, 0, Qt::AlignLeft);
    hl->addWidget(detailsGBox, 1);
    setLayout(hl);



    // Signals

    QObject::connect(processorButton, SIGNAL(clicked(bool)), this, SLOT(setProcessorDetails()));
    QObject::connect(memoryButton, SIGNAL(clicked(bool)), this, SLOT(setMemoryDetails()));
    QObject::connect(diskButton, SIGNAL(clicked(bool)), this, SLOT(setDiskDetails()));
    QObject::connect(networkButton, SIGNAL(clicked(bool)), this, SLOT(setNetworkDetails()));
}


//

void PerformanceTab::resetVLayout()
{
    if (processorDetails->parentWidget() != 0)
        processorDetails->setParent(NULL);

    if (memoryDetails->parentWidget() != 0)
        memoryDetails->setParent(NULL);

    if (diskDetails->parentWidget() != 0)
        diskDetails->setParent(NULL);

    if (networkDetails->parentWidget() != 0)
        networkDetails->setParent(NULL);
}


/*
 * Slots
 */

void PerformanceTab::setProcessorDetails()
{
    resetVLayout();
    vlayout->addWidget(processorDetails);
}

void PerformanceTab::setMemoryDetails()
{
    resetVLayout();
    vlayout->addWidget(memoryDetails);
}

void PerformanceTab::setDiskDetails()
{
    resetVLayout();
    vlayout->addWidget(diskDetails);
}

void PerformanceTab::setNetworkDetails()
{
    resetVLayout();
    vlayout->addWidget(networkDetails);
}
