#include "performancegraph.h"

PerformanceGraph::PerformanceGraph(QString title, QString subTitle, QString graphLegend)
{

    vlayout = new QVBoxLayout();
    vlayout->setMargin(15);
    vlayout->setSpacing(10);
    setLayout(vlayout);

    // Header "title widget"

    QWidget *titleWidget = new QWidget();
    QHBoxLayout *titleLayout = new QHBoxLayout();
    titleLayout->setMargin(0);
    titleWidget->setLayout(titleLayout);

    // Labels
    titleLabel = new QLabel(title);
    titleLabel->setAlignment(Qt::AlignLeft);

    subTitleLabel = new QLabel(subTitle);
    subTitleLabel->setAlignment(Qt::AlignRight);

    titleLayout->addWidget(titleLabel);
    titleLayout->addWidget(subTitleLabel);

    // Center "Graph Widget"
    QWidget *graphWidget = new QWidget();
    QGridLayout *graphlayout = new QGridLayout();
    graphlayout->setMargin(0);
    graphWidget->setLayout(graphlayout);

    // labels
    graphLegendLabel = new QLabel(graphLegend);
    graphLegendLabel->setAlignment(Qt::AlignLeft);
    graphLegendLabel->setFixedHeight(15);

    QLabel *graphLevelLabel = new QLabel("100%");
    graphLevelLabel->setAlignment(Qt::AlignRight);

    QLabel *graphMaxTimeLabel = new QLabel("60 secondes");
    graphMaxTimeLabel->setAlignment(Qt::AlignLeft);
    graphMaxTimeLabel->setFixedHeight(15);

    QLabel *graphMinTimeLabel = new QLabel("0");
    graphMinTimeLabel->setAlignment(Qt::AlignRight);

    // Graph groupbox
    QGroupBox *graphGBox = new QGroupBox();
    graphGBox->setMinimumHeight(200);

    // center layering
    graphlayout->addWidget(graphLegendLabel, 0, 0);
    graphlayout->addWidget(graphLevelLabel, 0, 1);
    graphlayout->addWidget(graphGBox, 1, 0, 5, 2);
    graphlayout->addWidget(graphMaxTimeLabel, 7, 0);
    graphlayout->addWidget(graphMinTimeLabel, 7, 1);

    // Groupbox infos layering

    vlayout->addWidget(titleWidget);
    vlayout->addWidget(graphWidget);

}
