#include "serverlogindialog.h"

ServerLoginDialog::ServerLoginDialog()
{

    // Params
    setModal(true);
    setWindowTitle("Connexion au serveur");
    setWindowIcon(QIcon(":icons/server"));
    resize(230, 250);
    // Initializations

    QLabel *addressLabel = new QLabel("Addresse du serveur");
    QLabel *portLabel = new QLabel("Port :");

    addressLE = new QLineEdit();
    addressLE->setText("localhost");
    portLE  = new QLineEdit();
    portLE->setText("50885");

    nameLE  = new QLineEdit();
    nameLE->setPlaceholderText("Nom du client");
    passwordLE  = new QLineEdit();
    passwordLE->setPlaceholderText("Mot de passe server");
    passwordLE->setEchoMode(QLineEdit::Password);
    rememberCBox = new QCheckBox("Retenir mon choix");

    cancelBtn = new QPushButton("Annuler");
    validBtn = new QPushButton("Valider");
    cancelBtn->setMinimumHeight(25);
    validBtn->setMinimumHeight(25);

    // Layout

    QGridLayout *glayout = new QGridLayout();
    glayout->addWidget(addressLabel, 0, 0);
    glayout->addWidget(portLabel, 0, 1);
    glayout->addWidget(addressLE, 1, 0);
    glayout->addWidget(portLE, 1, 1);
    glayout->addWidget(nameLE, 2, 0, 1, 2);
    glayout->addWidget(passwordLE, 3, 0, 1, 2);
    glayout->addWidget(rememberCBox, 4, 0);
    glayout->addWidget(validBtn, 5, 0);
    glayout->addWidget(cancelBtn, 5, 1);

    // GroupLayout

    QGroupBox *groupbox = new QGroupBox();
    groupbox->setMinimumSize(200, 150);
    groupbox->setLayout(glayout);


    QHBoxLayout *hl = new QHBoxLayout();
    hl->addWidget(groupbox, 0, Qt::AlignCenter);

    setLayout(hl);


    // signals

    connect(validBtn, SIGNAL(clicked(bool)), this, SLOT(validBtnClicked()));
    connect(cancelBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
}


// slots

void ServerLoginDialog::validBtnClicked()
{
    hide();
    emit serverConnectionSignal(addressLE->text(), portLE->text(), nameLE->text(), passwordLE->text());
}
