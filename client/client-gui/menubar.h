#ifndef MENU_H
#define MENU_H

#include <QMenuBar>
#include <QMenu>
#include <QAction>

class MenuBar : public QMenuBar
{

    friend class MainWindow;
    friend class ClientMainWindow;

public:
    MenuBar();

    void initWidgets();

private:

    QMenu *menuFile;
    QMenu *menuDisplay;
    QMenu *menuHelp;

    QAction *actionQuit;
    QAction *actionNewConnection;
    QAction *actionDisconnect;
    QAction *actionRefresh;
    QAction *actionSettings;
    QAction *actionAbout;
};

#endif // MENU_H
