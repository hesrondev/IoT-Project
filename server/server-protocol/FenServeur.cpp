#include "FenServeur.h"
#include "ui_main.h"


FenServeur::FenServeur()
{
    // Création et disposition des widgets de la fenêtre

    setWindowTitle(tr("Serveur"));

    etatServeur = new QLabel;
    etatServeur->setAlignment(Qt::AlignCenter);

    boutonQuitter = new QPushButton(tr("Quitter"));
    connect(boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(etatServeur);
    layout->addWidget(boutonQuitter);
    setLayout(layout);


    // Gestion du serveur this permet que lorsque la fenetre est detruit le serveur aussi

    serveur = new QTcpServer(this);
    if (!serveur->listen(QHostAddress::Any, 50885))     // Démarrage du serveur sur toutes les IP disponibles et sur le port 50585
    {
        etatServeur->setText(tr("Le serveur n'a pas pu être démarré. Raison :<br />") + serveur->errorString());
    }
    else
    {
        etatServeur->setText(tr("Le serveur a été démarré sur le port <strong>") + QString::number(serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter."));
        connect(serveur, SIGNAL(newConnection()), this, SLOT(nouvelleConnexion()));
    }

    tailleMessage = 0;
}


// Brodcasting du message à tous les clients

void FenServeur::envoyerATous(const QString &message)
{
    // Préparation du paquet qui va contenir le paquet à envoyer sur le réseau
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << (quint16) 0; // On écrit 0 au début du paquet pour réserver la place pour écrire la taille
    out << message; // On ajoute le message à la suite
    out.device()->seek(0); // On se replace au début du paquet
    out << (quint16) (paquet.size() - sizeof(quint16)); // On écrase le 0 qu'on avait réservé par la longueur du message


    // Envoi du paquet préparé à tous les clients connectés au serveur

    for (int i = 0; i < clients.size(); i++)
        clients[i]->socket->write(paquet);
}

void FenServeur::sendDataToClient(QTcpSocket *soc, const QString &message)
{
    // Préparation du paquet qui va contenir le paquet à envoyer sur le réseau
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << (quint16) 0; // On écrit 0 au début du paquet pour réserver la place pour écrire la taille
    out << message; // On ajoute le message à la suite
    out.device()->seek(0); // On se replace au début du paquet
    out << (quint16) (paquet.size() - sizeof(quint16)); // On écrase le 0 qu'on avait réservé par la longueur du message

    soc->write(paquet);
}


// Trouver un client en connaissant son socket

Client *FenServeur::findClientBySocket(QTcpSocket *socket)
{
    for (int i = 0; i < clients.size(); i++)
    {
        if (clients[i]->socket == socket)
            return clients[i];
    }

    return NULL;
}



/* ****** SLOTS ********* */

void FenServeur::nouvelleConnexion()
{
    /// On signale la connexion à tous les clients [MESSAGE PERSO -- MAJ Serveur]
    envoyerATous(tr("Un nouveau client vient de se connecter"));

    // récupérer la socket correspondant au nouveau client
    QTcpSocket * socketClient= serveur->nextPendingConnection();

    Client *nouveauClient = new Client(clients.size() + 1, socketClient);

    //conserve la liste des clients connectés
    clients << nouveauClient;

    // readyRead() : signale que le client a envoyé des données
    connect(nouveauClient->socket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));

    //disconnected() : signale que le client s'est déconnecté
    connect(nouveauClient->socket, SIGNAL(disconnected()), this, SLOT(deconnexionClient()));

    // timers

    connect(nouveauClient->processTimer, SIGNAL(timeoutSignal(QTcpSocket*)), this, SLOT(sendProcessesData(QTcpSocket*)));
    connect(nouveauClient->cpuTimer, SIGNAL(timeoutSignal(QTcpSocket*)), this, SLOT(sendCpuData(QTcpSocket*)));
    connect(nouveauClient->ramTimer, SIGNAL(timeoutSignal(QTcpSocket*)), this, SLOT(sendRamData(QTcpSocket*)));
    connect(nouveauClient->networkTimer, SIGNAL(timeoutSignal(QTcpSocket*)), this, SLOT(sendNetworkData(QTcpSocket*)));
    connect(nouveauClient->diskTimer, SIGNAL(timeoutSignal(QTcpSocket*)), this, SLOT(sendDiskData(QTcpSocket*)));
    connect(nouveauClient->serverTimer, SIGNAL(timeoutSignal(QTcpSocket*)), this, SLOT(sendServerData(QTcpSocket*)));

    nouveauClient->startTimers();

}

void FenServeur::donneesRecues(){
    // 1 : on reçoit un paquet (ou un sous-paquet) d'un des clients

    // On détermine quel client envoie le message (recherche du QTcpSocket du client)
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas trouvé le client à l'origine du signal, on arrête la méthode
        return;

    // Si tout va bien, on continue : on récupère le message
    QDataStream in(socket);

    if (tailleMessage == 0) // Si on ne connaît pas encore la taille du message, on essaie de la récupérer
    {
        if (socket->bytesAvailable() < (int)sizeof(quint16)) // On n'a pas reçu la taille du message en entier
             return;

        in >> tailleMessage; // Si on a reçu la taille du message en entier, on la récupère
    }

    // Si on connaît la taille du message, on vérifie si on a reçu le message en entier
    if (socket->bytesAvailable() < tailleMessage) // Si on n'a pas encore tout reçu, on arrête la méthode
        return;


    // Si ces lignes s'exécutent, c'est qu'on a reçu tout le message : on peut le récupérer !
    QString message;
    in >> message;

    /// RECEPTION MESSAGE CLIENT
    /// TRAITEMENT
    /// MODIFICATION DU CLIENT CONCERNE
    ///
    // 2 : on renvoie le message à tous les clients
    envoyerATous(message);

    // 3 : remise de la taille du message à 0 pour permettre la réception des futurs messages
    tailleMessage = 0;

}


void FenServeur::deconnexionClient()
{
    envoyerATous(tr("Un client vient de se déconnecter"));

    // On détermine quel client se déconnecte
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas trouvé le client à l'origine du signal, on arrête la méthode
        return;

    Client *client = findClientBySocket(socket);

    if (client != NULL)
    {
        clients.removeOne(client);
        // Changer le statut du client
        client->disconnect();

        // stoper les timers
        client->stopTimers();

        // supprimer plus tard poue éviter de faire planter qt
        client->socket->deleteLater();

    }
}

// Processes data

void FenServeur::sendProcessesData(QTcpSocket *soc)
{
    Processus sm;
    QJsonObject  js;
    sm.write(js);

    QJsonDocument doc(js);
    QString message(doc.toJson(QJsonDocument::Compact));

    cout << message.toStdString() << endl << endl;

    sendDataToClient(soc, message);
}

// Cpu data

void FenServeur::sendCpuData(QTcpSocket* soc)
{
    Cpu sm;
    QJsonObject  js ;
    sm.write(js);

    QJsonDocument doc(js);
    QString message(doc.toJson(QJsonDocument::Compact));

    cout << message.toStdString() << endl << endl;

    sendDataToClient(soc, message);
}

// Ram data

void FenServeur::sendRamData(QTcpSocket *soc)
{
    Ram sm;
    QJsonObject  js ;
    sm.write(js);

    QJsonDocument doc(js);
    QString message(doc.toJson(QJsonDocument::Compact));

    cout << message.toStdString() << endl << endl;

    sendDataToClient(soc, message);
}

// Disk data

void FenServeur::sendDiskData(QTcpSocket *soc)
{
    Disque sm;
    QJsonObject  js ;
    sm.write(js);

    QJsonDocument doc(js);
    QString message(doc.toJson(QJsonDocument::Compact));

    cout << message.toStdString() << endl << endl;

    sendDataToClient(soc, message);
}

// Network data

void FenServeur::sendNetworkData(QTcpSocket *soc)
{
    Network sm;

    //sm.setIpv4(ipv4);
    //sm.setIpv6(ipv6);

    QJsonObject  js ;
    sm.write(js);

    QJsonDocument doc(js);
    QString message(doc.toJson(QJsonDocument::Compact));

    cout << message.toStdString() << endl << endl;

    sendDataToClient(soc, message);
}

// Server data

void FenServeur::sendServerData(QTcpSocket *soc)
{
    Serveur sm(clients);
    // sm.setIp(serveur->serverAddress().toString());  // MAJ de l'adresse du serveur

    QJsonObject  js ;
    sm.write(js);

    QJsonDocument doc(js);
    QString message(doc.toJson(QJsonDocument::Compact));

    cout << message.toStdString() << endl << endl;

    sendDataToClient(soc, message);
}

void FenServeur::sendAllDataSlot(QTcpSocket *soc)
{

}
