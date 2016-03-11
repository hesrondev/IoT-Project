#include "centralwidget.h"

CentralWidget::CentralWidget()
{

    // init

    _processTab = new ProcessTab();
    _performanceTab = new PerformanceTab();
    _apphistoryTab = new AppHistoryTab();
    _serverTab = new ServerControllerTab();

    //

    addTab(_processTab, tr("&Processus"));
    addTab(_performanceTab, tr("&Performance"));
    addTab(_apphistoryTab, tr("&Historique des Apps"));
    addTab(_serverTab, tr("Serveur"));


}
