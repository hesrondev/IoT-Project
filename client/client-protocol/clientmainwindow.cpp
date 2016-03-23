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

    tailleMessage = 0;


    //
}


/* *** Traitement des messages re�us *** */

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

            cout << type.toStdString() << endl;

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


// Tentative de connexion au serveur
void ClientMainWindow::on_boutonConnexion_clicked(const QString &ip, const QString &port, const QString &clientName, const QString &mdp)
{
    // On annonce sur la fen�tre qu'on est en train de se connecter
    displayStatus(tr("Tentative de connexion en cours..."));

    // nom du client
    client.setNom(clientName);

    socket->abort(); // On d�sactive les connexions pr�c�dentes s'il y en a
    socket->connectToHost(ip, port.toInt()); // On se connecte au serveur demand�
}

// Envoi d'un message au serveur
void ClientMainWindow::on_boutonEnvoyer_clicked()
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On pr�pare le paquet � envoyer
    QString messageAEnvoyer = " ";

    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(paquet); // On envoie le paquet
}

// Appuyer sur la touche Entr�e a le m�me effet que cliquer sur le bouton "Envoyer"
void ClientMainWindow::on_message_returnPressed()
{
    on_boutonEnvoyer_clicked();
}

// On a re�u un paquet (ou un sous-paquet)
void ClientMainWindow::donneesRecues()
{
    /* M�me principe que lorsque le serveur re�oit un paquet :
    On essaie de r�cup�rer la taille du message
    Une fois qu'on l'a, on attend d'avoir re�u le message entier (en se basant sur la taille annonc�e tailleMessage)
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


    // Si on arrive jusqu'� cette ligne, on peut r�cup�rer le message entier
    QString messageRecu;
    in >> messageRecu;

    /// Traitement du message ici !

    displayStatus(messageRecu);
    messageProcessing(messageRecu);

    // On remet la taille du message � 0 pour pouvoir recevoir de futurs messages
    tailleMessage = 0;
}

// Ce slot est appel� lorsque la connexion au serveur a r�ussi
void ClientMainWindow::connecte()
{
    displayStatus(tr("Connexion r�ussie !"));
    //boutonConnexion->setEnabled(true);
}

// Ce slot est appel� lorsqu'on est d�connect� du serveur
void ClientMainWindow::deconnecte()
{
    displayStatus(tr("D�connect� du serveur"));
}

// Ce slot est appel� lorsqu'il y a une erreur
void ClientMainWindow::erreurSocket(QAbstractSocket::SocketError erreur)
{
    switch(erreur) // On affiche un message diff�rent selon l'erreur qu'on nous indique
    {
        case QAbstractSocket::HostNotFoundError:
            displayStatus(tr("ERREUR : le serveur n'a pas pu �tre trouv�. V�rifiez l'IP et le port."));
            break;
        case QAbstractSocket::ConnectionRefusedError:
            displayStatus(tr("ERREUR : le serveur a refus� la connexion. V�rifiez si le programme \"serveur\" a bien �t� lanc�. V�rifiez aussi l'IP et le port."));
            break;
        case QAbstractSocket::RemoteHostClosedError:
            displayStatus(tr("ERREUR : le serveur a coup� la connexion."));
            break;
        default:
            displayStatus(tr("ERREUR : ") + socket->errorString() + tr(""));
        break;
    }

    //boutonConnexion->setEnabled(true);
}
