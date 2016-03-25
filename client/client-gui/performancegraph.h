#ifndef PERFORMANCEGRAPH_H
#define PERFORMANCEGRAPH_H

#include <iostream>
#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QVector>

#include "qwt_plot.h"
#include "qwt_plot_curve.h"
#include "qwt_plot_grid.h"

using namespace std;

class PerformanceGraph : public QWidget
{
    Q_OBJECT

public:
    PerformanceGraph(QString title, QString subTitle, QString graphLegend);

    void addData(int i, double y);

public slots:
    void appendPoint(int i, double y);
    void drawCurve(int i);


signals:
    void drawSignal(int i, double y);

protected:
    QVBoxLayout *vlayout;

    // labels
    QLabel *titleLabel;
    QLabel *subTitleLabel;
    QLabel *graphLegendLabel;

    //
    QTimer *timer;
    // Les deux tableaux de données
    QVector<double> XDATA;
    QVector<double> YDATA_1;
    QVector<double> YDATA_2;

    int maxSize;

    QwtPlot plot;
    QwtPlotGrid gridPlot;
    QwtPlotCurve curve1;
    QwtPlotCurve curve2;

};

#endif // PERFORMANCEGRAPH_H
