#include "mainwindow.h"

MainWindow::MainWindow()
{

    // Specifications

    resize(1200, 600);
    initWidgets();
    setWindowIcon(QIcon(":icons/monitor"));

    // Signals

    QObject::connect(_menuBar->actionQuit, SIGNAL(triggered(bool)), this, SLOT(quit()));
    QObject::connect(_menuBar->actionNewConnection, SIGNAL(triggered(bool)), this, SLOT(loginServerSlot()));
    QObject::connect(_menuBar->actionSettings, SIGNAL(triggered(bool)), this, SLOT(displaySettingsSlot()));
    QObject::connect(_menuBar->actionAbout, SIGNAL(triggered(bool)), this, SLOT(aboutAppSlot()));
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
}


/* Slots
 *
 */

void MainWindow::loginServerSlot()
{
    ServerLoginDialog *serverLogin = new ServerLoginDialog();

    serverLogin->show();
}

void MainWindow::displaySettingsSlot()
{
    DisplaySettingsDialog *displaySettings = new DisplaySettingsDialog();
    displaySettings->show();
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
