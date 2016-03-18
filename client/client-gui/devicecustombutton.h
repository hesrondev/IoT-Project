#ifndef DEVICECUSTOMBUTTON_H
#define DEVICECUSTOMBUTTON_H


#include <QPushButton>
#include <QProgressBar>
#include <QGridLayout>
#include <QLabel>
#include <QGroupBox>
#include <QPixmap>

class DeviceCustomButton : public QPushButton
{
public:
    DeviceCustomButton(QString deviceName, int deviceType = 1);
};

#endif // DEVICECUSTOMBUTTON_H
