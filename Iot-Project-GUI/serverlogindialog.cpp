#include "serverlogindialog.h"

ServerLoginDialog::ServerLoginDialog()
{

    // Params
    setModal(true);
    setWindowTitle("Connexion au serveur");
    setWindowIcon(QIcon(":icons/server"));

    // Initializations

    QLabel *addressLabel = new QLabel("Addresse du serveur");
    QLabel *portLabel = new QLabel("Port :");
    QLabel *passwordLabel = new QLabel("Mot de passe");

    addressLE = new QLineEdit();
    portLE  = new QLineEdit();
    passwordLE  = new QLineEdit();
    passwordLE->setEchoMode(QLineEdit::Password);
    rememberCBox = new QCheckBox("Retenir mon choix");

    cancelBtn = new QPushButton("Annuler");
    validBtn = new QPushButton("Valider");

    // Layout

    QGridLayout *glayout = new QGridLayout();
    glayout->addWidget(addressLabel, 0, 0);
    glayout->addWidget(portLabel, 0, 1);
    glayout->addWidget(addressLE, 1, 0);
    glayout->addWidget(portLE, 1, 1);
    glayout->addWidget(passwordLabel, 2, 0, 1, 2);
    glayout->addWidget(passwordLE, 3, 0, 1, 2);
    glayout->addWidget(rememberCBox, 4, 0);
    glayout->addWidget(validBtn, 5, 0);
    glayout->addWidget(cancelBtn, 5, 1);

    // GroupLayout

    QGroupBox *groupbox = new QGroupBox();
    groupbox->setLayout(glayout);


    QHBoxLayout *hl = new QHBoxLayout();
    hl->addWidget(groupbox, 0, Qt::AlignCenter);

    setLayout(hl);
}
