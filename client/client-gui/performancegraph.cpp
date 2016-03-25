#include "performancegraph.h"

PerformanceGraph::PerformanceGraph(QString title, QString subTitle, QString graphLegend) : XDATA(), YDATA_1(), YDATA_2()
{

    // Initialisation de la courbe


    plot.setAutoReplot(true);
    plot.enableAxis(QwtPlot::xBottom, false);
    plot.enableAxis(QwtPlot::yLeft, false);

    curve1.setPen( Qt::darkBlue );
    curve1.setStyle( QwtPlotCurve::Lines );
    curve1.setRenderHint( QwtPlotItem::RenderAntialiased );

    curve2.setPen( Qt::green );
    curve2.setStyle( QwtPlotCurve::Lines );
    curve2.setRenderHint( QwtPlotItem::RenderAntialiased );

    // remplissage des tableaux

    maxSize = 60;

    XDATA.reserve(maxSize);
    YDATA_1.reserve(maxSize);
    YDATA_2.reserve(maxSize);

    for(double i = 0; i < 60; i++) {
        XDATA.push_back(i); // on rempli de 0 à 59
        YDATA_1.push_back(0); // on rempliT tout à 0
        YDATA_2.push_back(0); // on rempliT tout à 0
    }

    curve1.attach(&plot);
    curve2.attach(&plot);

    // timer
    timer = new QTimer;

    // IG

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

    titleLabel->setObjectName("perf-infos-title");
    subTitleLabel->setObjectName("perf-infos-subTitle");

    titleLayout->addWidget(titleLabel);
    titleLayout->addWidget(subTitleLabel);

    // Center "Graph Widget"
    QWidget *graphWidget = new QWidget();
    QGridLayout *graphlayout = new QGridLayout();
    graphlayout->setMargin(0);
    graphlayout->setVerticalSpacing(1);
    graphWidget->setLayout(graphlayout);

    // labels
    graphLegendLabel = new QLabel(graphLegend);
    graphLegendLabel->setAlignment(Qt::AlignLeft);
    graphLegendLabel->setFixedHeight(15);
    graphLegendLabel->setObjectName("perf-graph-legend");

    QLabel *graphLevelLabel = new QLabel("100%");
    graphLevelLabel->setAlignment(Qt::AlignRight);
    graphLevelLabel->setObjectName("perf-graph-legend");

    QLabel *graphMaxTimeLabel = new QLabel("60 secondes");
    graphMaxTimeLabel->setAlignment(Qt::AlignLeft);
    graphMaxTimeLabel->setFixedHeight(15);
    graphMaxTimeLabel->setObjectName("perf-graph-legend");

    QLabel *graphMinTimeLabel = new QLabel("0");
    graphMinTimeLabel->setAlignment(Qt::AlignRight);
    graphMinTimeLabel->setObjectName("perf-graph-legend");

    // Graph groupbox
    QGroupBox *graphGBox = new QGroupBox();
    graphGBox->setMinimumHeight(200);
    graphGBox->setObjectName("perf-graph");
    QVBoxLayout *vl = new QVBoxLayout;
    vl->setMargin(0);
    graphGBox->setLayout(vl);

    vl->addWidget(&plot);


    // center layering
    graphlayout->addWidget(graphLegendLabel, 0, 0);
    graphlayout->addWidget(graphLevelLabel, 0, 1);
    graphlayout->addWidget(graphGBox, 1, 0, 5, 2);
    graphlayout->addWidget(graphMaxTimeLabel, 7, 0);
    graphlayout->addWidget(graphMinTimeLabel, 7, 1);

    // Groupbox infos layering

    vlayout->addWidget(titleWidget);
    vlayout->addWidget(graphWidget);

    // signals

    connect(this, SIGNAL(drawSignal(int,double)), this, SLOT(appendPoint(int,double)));

}


// On met à jour le tableau, on ajoute au fond on dépile devant
void PerformanceGraph::addData(int i, double y)
{
    emit drawSignal(i, y);
}

void PerformanceGraph::appendPoint(int i, double y)
{
    /*
    // curve 1
    if (i == 1)
    {
        for (int i = 0; i < YDATA_1.size()-1; i++) {
            YDATA_1[i] = YDATA_1[i+1];
        }
        YDATA_1[maxSize-1] = y;

        drawCurve(1);
    }

    // curve 2
    else if (i == 2)
    {
        for (int i = 0; i < YDATA_2.size()-1; i++) {
            YDATA_2[i] = YDATA_2[i+1];
        }
        YDATA_2[maxSize-1] = y;

        drawCurve(2);
    }


    std::cout << "drawing..." << std::endl;
    */

}

void PerformanceGraph::drawCurve(int i)
{
    /*
    // On trace

    if (i == 1)
        curve1.setSamples(XDATA, YDATA_1);

    else
        curve2.setSamples(XDATA, YDATA_2);
        */
}
