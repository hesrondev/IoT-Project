#include "serverMessage.h"

ServerMessage::ServerMessage(const QString &value)
{
     type = value;  // type de message
     //observer = NULL;   // observer
}


/* Ajout d'un observer
void ServerMessage::addObserver(const Observer *obs)
{
    if (obs != NULL)
        observer = obs;
}*/

