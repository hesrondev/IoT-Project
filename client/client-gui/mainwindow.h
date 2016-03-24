#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStatusBar>

#include "menubar.h"
#include "centralwidget.h"
#include "serverlogindialog.h"
#include "displaysettingsdialog.h"
#include "aboutappdialog.h"

using namespace std;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();

    // Fonctions

    void initWidgets();

    void displayStatus(const QString &message);

    ~MainWindow();

public slots:
    void loginServerSlot();
    void displaySettingsSlot();
    void aboutAppSlot();

protected:

    MenuBar *_menuBar;
    CentralWidget *_centralWidget;
    QStatusBar *_statusBar;

    ServerLoginDialog *serverLogin;
    DisplaySettingsDialog *settingsDisplay;
};

#endif // MAINWINDOW_H
