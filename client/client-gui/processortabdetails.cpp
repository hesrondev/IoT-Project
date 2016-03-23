#include "processortabdetails.h"

ProcessorTabDetails::ProcessorTabDetails(QString title, QString subTitle, QString graphLegend) :
    PerformanceGraph(title, subTitle, graphLegend)
{
    // labels
    QLabel *useLabel = new QLabel("Utilisation");
    useValueLabel = new QLabel("17%");
    useValueLabel->setObjectName("perf-value");

    QLabel *speedLabel = new QLabel("Vitesse");
    speedValueLabel = new QLabel("1,50 Ghz");
    speedValueLabel->setObjectName("perf-value");

    QLabel *processLabel = new QLabel("Processus");
    processValueLabel = new QLabel("15");
    processValueLabel->setObjectName("perf-value");

    QLabel *threadLabel = new QLabel("Threads");
    threadValueLabel = new QLabel("90");
    threadValueLabel->setObjectName("perf-value");

    QLabel *timeLabel = new QLabel("Durée de fonctionnement");
    timeValueLabel = new QLabel("2:55:26:03");
    timeValueLabel->setObjectName("perf-value");

    // spec labels

    QLabel *speedMaxLabel = new QLabel("Vitesse maximale:");
    speedMaxValueLabel = new QLabel("3,40 GHz");
    speedMaxValueLabel->setObjectName("perf-value-small");

    QLabel *coreLabel = new QLabel("Coeurs:");
    coreValueLabel = new QLabel("4");
    coreValueLabel->setObjectName("perf-value-small");

    // Footer Widget

    QWidget *footerWidget = new QWidget();
    QHBoxLayout *footerHLayout = new QHBoxLayout();
    footerHLayout->setMargin(0);
    footerHLayout->setSpacing(10);
    QGridLayout *footerGLayout = new QGridLayout();
    footerGLayout->setMargin(0);
    footerGLayout->setHorizontalSpacing(15);

    footerWidget->setLayout(footerHLayout);

    // spec widget
    QWidget *specWidget = new QWidget();
    QVBoxLayout *specVLayout = new QVBoxLayout();
    QGridLayout *specGLayout = new QGridLayout();

    specVLayout->setMargin(0);
    specVLayout->addLayout(specGLayout);
    specVLayout->addStretch(1);
    specWidget->setLayout(specVLayout);

    // footer layering
    footerHLayout->addLayout(footerGLayout);
    footerHLayout->addWidget(specWidget);
    footerHLayout->addStretch(1);

    // layering footer

    footerGLayout->addWidget(useLabel, 0, 0);
    footerGLayout->addWidget(speedLabel, 0, 1);
    footerGLayout->addWidget(useValueLabel, 1, 0);
    footerGLayout->addWidget(speedValueLabel, 1, 1);
    footerGLayout->addWidget(processLabel, 2, 0);
    footerGLayout->addWidget(threadLabel, 2, 1);
    footerGLayout->addWidget(processValueLabel, 3, 0);
    footerGLayout->addWidget(threadValueLabel, 3, 1);
    footerGLayout->addWidget(timeLabel, 4, 0, 1, 2);
    footerGLayout->addWidget(timeValueLabel, 5, 0, 1, 2);

    // caractéritiques

    specGLayout->addWidget(speedMaxLabel, 0, 0);
    specGLayout->addWidget(speedMaxValueLabel, 0, 1);
    specGLayout->addWidget(coreLabel, 1, 0);
    specGLayout->addWidget(coreValueLabel, 1, 1);


    // Groupbox infos layering
    vlayout->addWidget(footerWidget);
    vlayout->addStretch(1);
}


// Mise à jour des éléments du serveur

void ProcessorTabDetails::updateData(const QString &nom, const QString &tU, const QString &speed, const QString &maxSpeed,
                                 const QString &cores, const QString &processes, const QString &threads)
{
    subTitleLabel->setText(nom);
    useValueLabel->setText(tU);
    speedValueLabel->setText(speed);
    speedMaxValueLabel->setText(maxSpeed);
    coreValueLabel->setText(cores);
    processValueLabel->setText(processes);
    threadValueLabel->setText(threads);
    timeValueLabel->setText("XXXX-TIME-XXXX");
}
