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
    processFqSB = new QSpinBox();

    processLayout->addWidget(processFqLabel, 0, 0, 1, 3);
    processLayout->addWidget(processFqSB, 0, 3);

    // Groupe CPU
    QGroupBox *cpuGroup = new QGroupBox("CPU");
    QGridLayout *cpuLayout = new QGridLayout();
    cpuGroup->setLayout(cpuLayout);

    QLabel *cpuFqLabel = new QLabel("Fréquence d'acquisition");
    cpuFqSB = new QSpinBox();

    cpuLayout->addWidget(cpuFqLabel, 0, 0, 1, 3);
    cpuLayout->addWidget(cpuFqSB, 0, 3);

    // Groupe Mémoire
    QGroupBox *memoryGroup = new QGroupBox("Mémoire");
    QGridLayout *memoryLayout = new QGridLayout();
    memoryGroup->setLayout(memoryLayout);

    QLabel *memoryFqLabel = new QLabel("Fréquence d'acquisition");
    memoryFqSB = new QSpinBox();

    memoryLayout->addWidget(memoryFqLabel, 0, 0, 1, 3);
    memoryLayout->addWidget(memoryFqSB, 0, 3);

    // Groupe DISK group
    QGroupBox *diskGroup = new QGroupBox("Disques");
    QGridLayout *diskLayout = new QGridLayout();
    diskGroup->setLayout(diskLayout);

    QLabel *diskFqLabel = new QLabel("Fréquence d'acquisition");
    diskFqSB = new QSpinBox();

    diskLayout->addWidget(diskFqLabel, 0, 0, 1, 3);
    diskLayout->addWidget(diskFqSB, 0, 3);


    // Groupe Ethernet
    QGroupBox *ethGroup = new QGroupBox("Ethernet");
    QGridLayout *ethLayout = new QGridLayout();
    ethGroup->setLayout(ethLayout);

    QLabel *ethFqLabel = new QLabel("Fréquence d'acquisition");
    ethFqSB = new QSpinBox();

    ethLayout->addWidget(ethFqLabel, 0, 0, 1, 3);
    ethLayout->addWidget(ethFqSB, 0, 3);

    // By group Layering

    byCompsGroup = new QGroupBox;
    byCompsGroup->setObjectName("perf-graph");

    QVBoxLayout *vlayout = new QVBoxLayout();
    byCompsGroup->setLayout(vlayout);
    vlayout->addWidget(processGroup);
    vlayout->addWidget(cpuGroup);
    vlayout->addWidget(memoryGroup);
    vlayout->addWidget(diskGroup);
    vlayout->addWidget(ethGroup);

    // section envoi général

    globalGroup = new QGroupBox;
    globalGroup->setObjectName("perf-graph");

    QLabel *globLabel = new QLabel("Fréquence d'acquisition");
    globalSB = new QSpinBox();
    QGridLayout *globLayout = new QGridLayout();
    globalGroup->setLayout(globLayout);
    globLayout->addWidget(globLabel, 0, 0, 1, 3);
    globLayout->addWidget(globalSB, 0, 3);


    // checkboxes
    byCompsCB = new QCheckBox("Acquisition par composants");
    globCB = new QCheckBox("Acquisition globale");

    // Button
    validButton = new QPushButton("Valider les modifications");    
    validButton->setFixedHeight(30);

    vlayout->addWidget(validButton);


    QVBoxLayout *genLayout = new QVBoxLayout();
    genLayout->addWidget(byCompsCB);
    genLayout->addWidget(byCompsGroup);
    genLayout->addWidget(globCB);
    genLayout->addWidget(globalGroup);
    genLayout->addWidget(validButton);

    setLayout(genLayout);

    // states management

    globCB->setChecked(true);
    byCompsGroup->setEnabled(false);

    // signals

    connect(byCompsCB, SIGNAL(clicked(bool)), this, SLOT(enableCompsGroup()));
    connect(globCB, SIGNAL(clicked(bool)), this, SLOT(enableGlobalGroup()));
    connect(validButton, SIGNAL(clicked(bool)), this, SLOT(on_validButton_clicked()));
}


// Gestion des états

void DisplaySettingsDialog::enableCompsGroup()
{
    byCompsGroup->setEnabled(true);
    globCB->setChecked(false);
    globalGroup->setEnabled(false);
}

void DisplaySettingsDialog::enableGlobalGroup()
{
    byCompsGroup->setEnabled(false);
    byCompsCB->setChecked(false);
    globalGroup->setEnabled(true);
}

// Appuie sur le bouton valider

void DisplaySettingsDialog::on_validButton_clicked()
{
    hide();

    // si le paramètre global est activé
    if (globCB->isChecked())
        emit globalParam(globalSB->value());
    else
        emit componentsParams(processFqSB->value(), cpuFqSB->value(),
                              memoryFqSB->value(), diskFqSB->value(), ethFqSB->value());
}


/*
 * Destructeur
 */

DisplaySettingsDialog::~DisplaySettingsDialog()
{

}

