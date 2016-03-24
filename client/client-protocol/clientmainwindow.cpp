#include "clientmainwindow.h"

ClientMainWindow::ClientMainWindow() : MainWindow()
{
    // Observers
    cpu.addObserver(_centralWidget->performanceTab()->getProcessorDetails());
    network.addObserver(_centralWidget->performanceTab()->getNetworkDetails());
    ram.addObserver(_centralWidget->performanceTab()->getMemoryDetails());


    // Socket and signals

    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(socket, SIGNAL(connected()), this, SLOT(connecte()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(deconnecte()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));

    // server login widget
    connect(serverLogin, SIGNAL(serverConnectionSignal(QString,QString,QString,QString)), this, SLOT(on_boutonConnexion_clicked(QString,QString,QString,QString)));

    // deconnexion
    connect(_menuBar->actionDisconnect, SIGNAL(triggered(bool)), this, SLOT(deconnexion()));

    // paramétrage

    connect(settingsDisplay, SIGNAL(componentsParams(int,int,int,int,int)), this, SLOT(updateComponentsParams(int,int,int,int,int)));
    connect(settingsDisplay, SIGNAL(globalParam(int)), this, SLOT(updateGlobalParam(int)));

    tailleMessage = 0;
}


/* *** Traitement des messages reçus *** */

void ClientMainWindow::messageProcessing(QString message)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(message.toUtf8());
    QJsonObject json;

    if (!jsonDoc.isNull())
    {
        if (jsonDoc.isObject())
        {
            json = jsonDoc.object();

            // Traitement du message selon le type de l'objet

            QString type = json["type"].toString();

            QJsonDocument doc(json);
            QString message(doc.toJson(QJsonDocument::Compact));

            cout << message.toStdString() << endl << endl;

            if (type.compare("CPU") == 0)
            {
                cpu.read(json);
            }
            else if (type.compare("DISK") == 0)
            {
                disk.read(json);
            }
            else if (type.compare("PROCESS") == 0)
            {
                process.read(json);
            }
            else if (type.compare("RAM") == 0)
            {
                ram.read(json);
            }
            else if (type.compare("NETWORK") == 0)
            {
                network.read(json);
            }
            else if (type.compare("SERVER") == 0)
            {
                server.read(json);
            }
        }
        else
            qDebug() << "jsonDoc is not an object" << endl;
     }

     else
        qDebug() << "INVALID JSON\n" << message << endl;
}


// Envoi d'un message au serveur

void ClientMainWindow::sendDataToServer(const QString &message)
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On prépare le paquet à envoyer
    out << (quint16) 0;
    out << message;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    // On envoie le paquet
    socket->write(paquet);
}


// Tentative de connexion au serveur
void ClientMainWindow::on_boutonConnexion_clicked(const QString &ip, const QString &port, const QString &clientName, const QString &mdp)
{
    // On annonce sur la fenêtre qu'on est en train de se connecter
    displayStatus(tr("Tentative de connexion en cours..."));

    // nom du client
    client.setNom(clientName);

    socket->abort(); // On désactive les connexions précédentes s'il y en a
    socket->connectToHost(ip, port.toInt()); // On se connecte au serveur demandé
}

// On a reçu un paquet (ou un sous-paquet)
void ClientMainWindow::donneesRecues()
{
    /* Même principe que lorsque le serveur reçoit un paquet :
    On essaie de récupérer la taille du message
    Une fois qu'on l'a, on attend d'avoir reçu le message entier (en se basant sur la taille annoncée tailleMessage)
    */
    QDataStream in(socket);

    if (tailleMessage == 0)
    {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
             return;

        in >> tailleMessage;
    }

    if (socket->bytesAvailable() < tailleMessage)
        return;

    // Si on arrive jusqu'à cette ligne, on peut récupérer le message entier
    QString messageRecu;
    in >> messageRecu;

    /// Traitement du message ici !

    messageProcessing(messageRecu);

    // On remet la taille du message à 0 pour pouvoir recevoir de futurs messages
    tailleMessage = 0;
}

// Ce slot est appelé lorsque la connexion au serveur a réussi
void ClientMainWindow::connecte()
{
    displayStatus(tr("Connexion réussie !"));
    sendClientData();

    // activation du bouton de déconnexion
    _menuBar->actionDisconnect->setEnabled(true);

}

// Ce slot est appelé lorsqu'on est déconnecté du serveur
void ClientMainWindow::deconnecte()
{
    displayStatus(tr("Déconnecté du serveur"));
    _menuBar->actionDisconnect->setEnabled(false);
}

void ClientMainWindow::deconnexion()
{
    socket->abort();
    _menuBar->actionDisconnect->setEnabled(false);
}

// Ce slot est appelé lorsqu'il y a une erreur

void ClientMainWindow::erreurSocket(QAbstractSocket::SocketError erreur)
{
    switch(erreur) // On affiche un message différent selon l'erreur qu'on nous indique
    {
        case QAbstractSocket::HostNotFoundError:
            displayStatus(tr("ERREUR : le serveur n'a pas pu être trouvé. Vérifiez l'IP et le port."));
            break;
        case QAbstractSocket::ConnectionRefusedError:
            displayStatus(tr("ERREUR : le serveur a refusé la connexion. Vérifiez si le programme \"serveur\" a bien été lancé. Vérifiez aussi l'IP et le port."));
            break;
        case QAbstractSocket::RemoteHostClosedError:
            displayStatus(tr("ERREUR : le serveur a coupé la connexion."));
            break;
        default:
            displayStatus(tr("ERREUR : ") + socket->errorString() + tr(""));
        break;
    }
}


// Réglages des paramètres d'acquisition :: SLOT --> envoyer au serveur

void ClientMainWindow::updateComponentsParams(int pro, int cpu, int mem, int disk, int eth)
{
    client.setComponentsParams(pro, cpu, mem, disk, eth);
    sendClientData();
}


void ClientMainWindow::updateGlobalParam(int glo)
{
    client.setGlobalFq(glo);
    sendClientData();
}


// Envoie des données du client

void ClientMainWindow::sendClientData()
{
    QJsonObject  js;
    client.write(js);

    QJsonDocument doc(js);
    QString message(doc.toJson(QJsonDocument::Compact));

    sendDataToServer(message);
}
