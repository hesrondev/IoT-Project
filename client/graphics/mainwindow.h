#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    ~MainWindow();

public slots:
    void loginServerSlot();
    void displaySettingsSlot();
    void aboutAppSlot();

private:

    MenuBar *_menuBar;
    CentralWidget *_centralWidget;
};

#endif // MAINWINDOW_H
