#include "mainwindow.h"

MainWindow::MainWindow()
{

    // Specifications

    resize(1200, 600);
    initWidgets();
    setWindowIcon(QIcon(":icons/monitor"));

    // Signals

    connect(_menuBar->actionQuit, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(_menuBar->actionNewConnection, SIGNAL(triggered(bool)), this, SLOT(loginServerSlot()));
    connect(_menuBar->actionSettings, SIGNAL(triggered(bool)), this, SLOT(displaySettingsSlot()));
    connect(_menuBar->actionAbout, SIGNAL(triggered(bool)), this, SLOT(aboutAppSlot()));

}

// Initialisation des widgets

void MainWindow::initWidgets()
{
    // Menu bar

    _menuBar = new MenuBar();
    setMenuBar(_menuBar);

    // Central Widget

    _centralWidget = new CentralWidget();
    setCentralWidget(_centralWidget);

    _centralWidget->setObjectName("central-widget");

    // footer widget

    _statusBar = new QStatusBar();
    _statusBar->setFixedHeight(30);

    setStatusBar(_statusBar);


    // logins server

    serverLogin = new ServerLoginDialog();

    // Param dialog

    settingsDisplay = new DisplaySettingsDialog();
}


// Affichage d'un statut

void MainWindow::displayStatus(const QString &message)
{
    _statusBar->showMessage(message, 2000);
}

/* Slots
 *
 */

void MainWindow::loginServerSlot()
{    
    serverLogin->show();
}


void MainWindow::displaySettingsSlot()
{

    settingsDisplay->show();
}

void MainWindow::aboutAppSlot()
{
    AboutAppDialog *aboutApp = new AboutAppDialog();
    aboutApp->show();
}


/*
 * Destructeur
 */

MainWindow::~MainWindow()
{

}
