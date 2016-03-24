#include "devicecustombutton.h"

DeviceCustomButton::DeviceCustomButton(QString deviceName, int deviceType)
{
    QGridLayout *glayout = new QGridLayout();
    glayout->setMargin(5);
    glayout->setVerticalSpacing(3);
    setLayout(glayout);

    // icon

    QString iconpath = "";

    if (deviceType == 1)
        iconpath = ":icons/hdd";

    else if (deviceType == 2)
         iconpath = ":icons/usb";

    QPixmap icon(iconpath);

    QLabel *iconLabel = new QLabel("");
    iconLabel->setPixmap(icon.scaled(36, 36, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QProgressBar *progressbar = new QProgressBar();
    QLabel *nameLabel = new QLabel(deviceName);
    QLabel *spaceLabel = new QLabel("150 Go libres sur 450Go");

    glayout->addWidget(nameLabel, 0, 1, 1, 1);
    glayout->addWidget(iconLabel, 1, 0, 2, 1);
    glayout->addWidget(progressbar, 1, 1, 1, 3);
    glayout->addWidget(spaceLabel, 2, 1);

    setFixedSize(270, 60);

}
