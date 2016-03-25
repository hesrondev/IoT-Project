#include "networktabdetails.h"

NetworkTabDetails::NetworkTabDetails(QString title, QString subTitle, QString graphLegend) :
    PerformanceGraph(title, subTitle, graphLegend)
{

    //
    QLabel *dataInLabel = new QLabel("Recevoir");
    dataInValueLabel = new QLabel("");
    dataInValueLabel->setObjectName("perf-value");

    QLabel *dataOutLabel = new QLabel("Envoyer");
    dataOutValueLabel = new QLabel("");
    dataOutValueLabel->setObjectName("perf-value");

    // Spec

    QLabel *ipv4Label = new QLabel("Adresse IPv4:");
    QLabel *ipv6Label = new QLabel("Adresse IPv6:");
    ipv4ValueLabel = new QLabel("");
    ipv6ValueLabel = new QLabel("");

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

void NetworkTabDetails::updateData(const QString &nom, const QString &de, const QString &dr, const QString &ipv4, const QString &ipv6)
{
    subTitleLabel->setText(nom);
    dataInValueLabel->setText(de);
    dataOutValueLabel->setText(dr);
    ipv4ValueLabel->setText(ipv4);
    ipv6ValueLabel->setText(ipv6);
}
