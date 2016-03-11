#include "menubar.h"

MenuBar::MenuBar()
{
    initWidgets();
}

void MenuBar::initWidgets()
{

    menuFile = new QMenu(tr("&Fichier"));
    menuDisplay = new QMenu(tr("&Affichage"));
    menuHelp = new QMenu(tr("&Aide"));

    // Initialisation des actions

    actionQuit = new QAction(QIcon(":icons/exit"), "Quitter", menuFile);
    actionNewConnection = new QAction(QIcon(":icons/server"), "Nouvelle connexion", menuFile);
    actionRefresh = new QAction(QIcon(":icons/refresh"), "Actualiser", menuDisplay);
    actionSettings = new QAction(QIcon(":icons/settings"), "Paramètres", menuDisplay);
    actionAbout  = new QAction("A propos", menuHelp);

    // Setting


    addMenu(menuFile);
    menuFile->addAction(actionNewConnection);
    menuFile->addSeparator();
    menuFile->addAction(actionQuit);


    addMenu(menuDisplay);
    menuDisplay->addAction(actionRefresh);
    menuDisplay->addAction(actionSettings);


    addMenu(menuHelp);
    menuHelp->addAction(actionAbout);

}
