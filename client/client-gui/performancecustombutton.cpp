#include "performancecustombutton.h"

PerformanceCustomButton::PerformanceCustomButton(QPixmap icon, QString title)
{
    // class attributes
    setObjectName("performance-custom-button");

    // Custom button for performance items

    // icon
    iconLabel = new QLabel("");
    iconLabel->setPixmap(icon.scaled(36, 36, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // title
    titleLabel = new QLabel(title);
    titleLabel->setObjectName("perf-btn-title");


    // display columns
    col2Label = new QLabel("");
    col3Label = new QLabel("");

    col2Label->setObjectName("perf-btn-subTitle");
    col3Label->setObjectName("perf-btn-subTitle");


    // Layering

    QGridLayout *gridlayout = new QGridLayout();

    gridlayout->addWidget(iconLabel, 0, 0, 3, 2);
    gridlayout->addWidget(titleLabel, 0, 2, 1, 2);
    gridlayout->addWidget(col2Label, 1, 2);
    gridlayout->addWidget(col3Label, 1, 3);

    QHBoxLayout *hl = new QHBoxLayout();
    hl->addLayout(gridlayout);
    hl->addStretch(1);

    setLayout(hl);
}

void PerformanceCustomButton::updateValues(const QString &v1, const QString &v2)
{
    col2Label->setText(v1);
    col3Label->setText(v2);
}
