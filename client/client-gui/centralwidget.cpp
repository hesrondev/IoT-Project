#include "centralwidget.h"

CentralWidget::CentralWidget()
{

    // init

    _processTab = new ProcessTab();
    _performanceTab = new PerformanceTab();
    _apphistoryTab = new AppHistoryTab();
    _serverTab = new ServerTab();

    //

    addTab(_processTab, tr("&Processus"));
    addTab(_performanceTab, tr("&Performance"));
    addTab(_apphistoryTab, tr("&Historique des Apps"));
    addTab(_serverTab, tr("Serveur"));


}

ProcessTab *CentralWidget::processTab() const
{
    return _processTab;
}

PerformanceTab *CentralWidget::performanceTab() const
{
    return _performanceTab;
}

AppHistoryTab *CentralWidget::apphistoryTab() const
{
    return _apphistoryTab;
}

ServerTab *CentralWidget::serverTab() const
{
    return _serverTab;
}
