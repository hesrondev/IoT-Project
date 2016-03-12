#include "apphistorytab.h"

AppHistoryTab::AppHistoryTab()
{

    //

    QLabel *legendLabel = new QLabel("Historique des applications depuis la connexion au serveur.");
    legendLabel->setFixedHeight(40);


    // TabWidget

    QTableWidget *tableWidget = new QTableWidget();
    tableWidget->setColumnCount(6);

    // resize to contents
    tableWidget->setColumnWidth(0, 300);

    QStringList listHeaders;
    listHeaders << "Nom" << "PID" << "Statut" << "UID" << "Date de début" << "Date de fin";
    tableWidget->setHorizontalHeaderLabels(listHeaders);
    tableWidget->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);


    // Layering

    QVBoxLayout *vl = new QVBoxLayout();
    setLayout(vl);
    vl->addWidget(legendLabel);
    vl->addWidget(tableWidget);
}
