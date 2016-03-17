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
    col2Label = new QLabel("4%");
    col3Label = new QLabel("2,45 GHz");

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
