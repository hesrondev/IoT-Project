#include "servertab.h"

ServerTab::ServerTab()
{

    //

    row_count = 0;

    //
    QLabel *legendLabel = new QLabel("Liste des clients connectés au serveur.");
    legendLabel->setFixedHeight(40);

    // TabWidget

    tableWidget = new QTableWidget();
    tableWidget->setColumnCount(6);

    // resize to contents
    tableWidget->setColumnWidth(0, 300);
    tableWidget->setColumnWidth(4, 120);

    listHeaders << "Nom du client" << "ID de connexion" << "Adresse IP" << "Statut" << "Début de connexion" << "Fin de connexion";
    tableWidget->setHorizontalHeaderLabels(listHeaders);
    tableWidget->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);


    // Layering

    QVBoxLayout *vl = new QVBoxLayout();
    setLayout(vl);
    vl->addWidget(legendLabel);
    vl->addWidget(tableWidget);
}

void ServerTab::setTableRowCount(int count)
{
    tableWidget->clearContents();
    tableWidget->setRowCount(count);
    row_count = 0;
}


//  ajout d'un nouveau client

void ServerTab::addClientLine(const QString &nom, const QString &id, const QString &ip, const QString &status, const QString &dateDeb, const QString &dateFin)
{
    tableWidget->setItem(row_count, 0, new QTableWidgetItem(nom));
    tableWidget->setItem(row_count, 1, new QTableWidgetItem(id));
    tableWidget->setItem(row_count, 2, new QTableWidgetItem(ip));
    tableWidget->setItem(row_count, 3, new QTableWidgetItem(status));
    tableWidget->setItem(row_count, 4, new QTableWidgetItem(dateDeb));
    tableWidget->setItem(row_count, 5, new QTableWidgetItem(dateFin));

    row_count++;
}
