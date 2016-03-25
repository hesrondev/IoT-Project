#include "serverMessage.h"

ServerMessage::ServerMessage(const QString &value)
{
     type = value;  // type de message
     observer = NULL;   // observer
     buttonObserver = NULL;   // observer
}


// Ajout d'un observer
void ServerMessage::addObserver(Observer *obs)
{
    if (obs != NULL)
        observer = obs;
}

void ServerMessage::addButtonObserver(Observer *obs)
{
    if (obs != NULL)
        buttonObserver = obs;
}

