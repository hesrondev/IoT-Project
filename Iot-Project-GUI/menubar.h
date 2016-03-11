#ifndef MENU_H
#define MENU_H

#include <QMenuBar>
#include <QMenu>
#include <QAction>

class MenuBar : public QMenuBar
{

    friend class MainWindow;

public:
    MenuBar();

    void initWidgets();

private:

    QMenu *menuFile;
    QMenu *menuDisplay;
    QMenu *menuHelp;

    QAction *actionQuit;
    QAction *actionNewConnection;
    QAction *actionRefresh;
    QAction *actionSettings;
    QAction *actionAbout;
};

#endif // MENU_H
