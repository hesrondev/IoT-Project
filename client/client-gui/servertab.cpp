#include "servertab.h"

ServerTab::ServerTab()
{
    //
    QLabel *legendLabel = new QLabel("Liste des clients connectés au serveur.");
    legendLabel->setFixedHeight(40);

    // TabWidget

    QTableWidget *tableWidget = new QTableWidget();
    tableWidget->setColumnCount(6);

    // resize to contents
    tableWidget->setColumnWidth(0, 300);
    tableWidget->setColumnWidth(4, 120);

    QStringList listHeaders;
    listHeaders << "Nom du client" << "ID de connexion" << "Adresse IP" << "Statut" << "Début de connexion" << "Fin de connexion";
    tableWidget->setHorizontalHeaderLabels(listHeaders);
    tableWidget->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);


    // Layering

    QVBoxLayout *vl = new QVBoxLayout();
    setLayout(vl);
    vl->addWidget(legendLabel);
    vl->addWidget(tableWidget);
}
