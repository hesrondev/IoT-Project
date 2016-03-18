#ifndef PERFORMANCEGRAPH_H
#define PERFORMANCEGRAPH_H

#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>

class PerformanceGraph : public QWidget
{
public:
    PerformanceGraph(QString title, QString subTitle, QString graphLegend);

protected:
    QVBoxLayout *vlayout;

    // labels
    QLabel *titleLabel;
    QLabel *subTitleLabel;
    QLabel *graphLegendLabel;

};

#endif // PERFORMANCEGRAPH_H
