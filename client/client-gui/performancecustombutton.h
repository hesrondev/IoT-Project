#ifndef PERFORMANCECUSTOMBUTTON_H
#define PERFORMANCECUSTOMBUTTON_H

#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>

#include "observer.h"

class PerformanceCustomButton : public QPushButton, public Observer
{
public:
    PerformanceCustomButton(QPixmap icon, QString title);

    void updateValues(const QString &v1, const QString &v2);

private:

    QLabel *iconLabel;
    QLabel *titleLabel;
    QLabel *col2Label;
    QLabel *col3Label;
};

#endif // PERFORMANCECUSTOMBUTTON_H
