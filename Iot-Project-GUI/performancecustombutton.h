#ifndef PERFORMANCECUSTOMBUTTON_H
#define PERFORMANCECUSTOMBUTTON_H

#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>

class PerformanceCustomButton : public QPushButton
{
public:
    PerformanceCustomButton(QPixmap icon, QString title);

private:

    QLabel *iconLabel;
    QLabel *titleLabel;
    QLabel *col2Label;
    QLabel *col3Label;
};

#endif // PERFORMANCECUSTOMBUTTON_H
