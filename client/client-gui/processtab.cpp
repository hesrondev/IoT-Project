#include "processtab.h"

ProcessTab::ProcessTab()
{


    // Toobar

    QToolBar *toolbar = new QToolBar();
    QAction *actionEndOfTask = new QAction(QIcon(":icons/stop"), "Fin de tâche", toolbar);
    QAction *actionRefreshTask = new QAction(QIcon(":icons/refresh"), "Fin de tâche", toolbar);

    toolbar->setIconSize(QSize(32, 32));

    toolbar->addAction(actionRefreshTask);
    toolbar->addAction(actionEndOfTask);


    // TabWidget

    QTableWidget *tableWidget = new QTableWidget();
    tableWidget->setColumnCount(6);

    // resize to contents
    tableWidget->setColumnWidth(0, 300);

    QStringList listHeaders;
    listHeaders << "Nom" << "PID" << "Statut" << "Utilisateur" << "UID" << "Taille";
    tableWidget->setHorizontalHeaderLabels(listHeaders);
    tableWidget->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);


    QLabel *legendLabel = new QLabel("Liste des processus en cours d'exécution");
    legendLabel->setFixedHeight(40);

    // Layering

    QVBoxLayout *vl = new QVBoxLayout();
    setLayout(vl);
    //vl->addWidget(toolbar);
    vl->addWidget(legendLabel);
    vl->addWidget(tableWidget);
}
