#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QTabWidget>

#include "processtab.h"
#include "performancetab.h"
#include "apphistorytab.h"
#include "servertab.h"

class CentralWidget : public QTabWidget
{
public:
    CentralWidget();

private:

    ProcessTab *_processTab;
    PerformanceTab *_performanceTab;
    AppHistoryTab *_apphistoryTab;
    ServerTab *_serverTab;


};

#endif // CENTRALWIDGET_H
