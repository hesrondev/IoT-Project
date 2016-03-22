#include "networktabdetails.h"

NetworkTabDetails::NetworkTabDetails(QString title, QString subTitle, QString graphLegend) :
    PerformanceGraph(title, subTitle, graphLegend)
{

    //
    QLabel *dataInLabel = new QLabel("Recevoir");
    QLabel *dataInValueLabel = new QLabel("566 bits/s");
    dataInValueLabel->setObjectName("perf-value");

    QLabel *dataOutLabel = new QLabel("Envoyer");
    QLabel *dataOutValueLabel = new QLabel("126 bits/s");
    dataOutValueLabel->setObjectName("perf-value");

    // Spec

    QLabel *ipv4Label = new QLabel("Adresse IPv4:");
    QLabel *ipv6Label = new QLabel("Adresse IPv6:");
    QLabel *ipv4ValueLabel = new QLabel("196.3.65.2");
    QLabel *ipv6ValueLabel = new QLabel("2001:0db8:0000:85a3:0000:0000:ac1f:8001:");
    ipv4ValueLabel->setObjectName("perf-value-small");
    ipv6ValueLabel->setObjectName("perf-value-small");
    // layering specifications

    QGridLayout *glayout = new QGridLayout();
    glayout->setMargin(0);
    glayout->setHorizontalSpacing(20);
    glayout->setAlignment(Qt::AlignLeft);

    glayout->addWidget(dataInLabel, 0, 0);
    glayout->addWidget(dataOutLabel, 0, 1);
    glayout->addWidget(ipv4Label, 0, 2);
    glayout->addWidget(ipv4ValueLabel, 0, 3);

    glayout->addWidget(dataInValueLabel, 1, 0, 2, 1);
    glayout->addWidget(dataOutValueLabel, 1, 1, 2, 1);
    glayout->addWidget(ipv6Label, 1, 2);
    glayout->addWidget(ipv6ValueLabel, 1, 3);

    // Layering
    vlayout->addLayout(glayout);
    vlayout->addStretch(1);
}
