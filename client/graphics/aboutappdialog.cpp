#include "aboutappdialog.h"

AboutAppDialog::AboutAppDialog()
{
    // Params
    setModal(true);
    setWindowTitle("A propos du logiciel");

    QVBoxLayout *vl = new QVBoxLayout;
    setLayout(vl);

    QLabel *aboutLabel = new QLabel("A propos de IoTProject-Client");

    vl->addWidget(aboutLabel, 0, Qt::AlignCenter);
}
