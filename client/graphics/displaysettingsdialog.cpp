#include "displaysettingsdialog.h"

DisplaySettingsDialog::DisplaySettingsDialog()
{
    // Params
    setModal(true);
    setWindowTitle("Paramètres d'affichage");
    setWindowIcon(QIcon(":icons/settings"));

    // Initializations
    initWidgets();
}

void DisplaySettingsDialog::initWidgets()
{
    // Groupe Processus
    QGroupBox *processGroup = new QGroupBox("Processus");
    QGridLayout *processLayout = new QGridLayout();
    processGroup->setLayout(processLayout);

    QLabel *processFqLabel = new QLabel("Fréquence d'acquisition");
    processFqLE = new QSpinBox();

    processLayout->addWidget(processFqLabel, 0, 0, 1, 3);
    processLayout->addWidget(processFqLE, 0, 3);

    // Groupe CPU
    QGroupBox *cpuGroup = new QGroupBox("CPU");
    QGridLayout *cpuLayout = new QGridLayout();
    cpuGroup->setLayout(cpuLayout);

    QLabel *cpuFqLabel = new QLabel("Fréquence d'acquisition");
    cpuFqLE = new QSpinBox();

    cpuLayout->addWidget(cpuFqLabel, 0, 0, 1, 3);
    cpuLayout->addWidget(cpuFqLE, 0, 3);

    // Groupe Mémoire
    QGroupBox *memoryGroup = new QGroupBox("Mémoire");
    QGridLayout *memoryLayout = new QGridLayout();
    memoryGroup->setLayout(memoryLayout);

    QLabel *memoryFqLabel = new QLabel("Fréquence d'acquisition");
    memoryFqLE = new QSpinBox();

    memoryLayout->addWidget(memoryFqLabel, 0, 0, 1, 3);
    memoryLayout->addWidget(memoryFqLE, 0, 3);

    // Groupe DISK group
    QGroupBox *diskGroup = new QGroupBox("Disques");
    QGridLayout *diskLayout = new QGridLayout();
    diskGroup->setLayout(diskLayout);

    QLabel *diskFqLabel = new QLabel("Fréquence d'acquisition");
    diskFqLE = new QSpinBox();

    diskLayout->addWidget(diskFqLabel, 0, 0, 1, 3);
    diskLayout->addWidget(diskFqLE, 0, 3);


    // Groupe Ethernet
    QGroupBox *ethGroup = new QGroupBox("Ethernet");
    QGridLayout *ethLayout = new QGridLayout();
    ethGroup->setLayout(ethLayout);

    QLabel *ethFqLabel = new QLabel("Fréquence d'acquisition");
    ethFqLE = new QSpinBox();

    ethLayout->addWidget(ethFqLabel, 0, 0, 1, 3);
    ethLayout->addWidget(ethFqLE, 0, 3);

    // Button
    validButton = new QPushButton("Valider les modifications");

    // Layering

    QVBoxLayout *vlayout = new QVBoxLayout();
    vlayout->addWidget(processGroup);
    vlayout->addWidget(cpuGroup);
    vlayout->addWidget(memoryGroup);
    vlayout->addWidget(diskGroup);
    vlayout->addWidget(ethGroup);
    vlayout->addWidget(validButton);

    setLayout(vlayout);
}



/*
 * Destructeur
 */

DisplaySettingsDialog::~DisplaySettingsDialog()
{

}
