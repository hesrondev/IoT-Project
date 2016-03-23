#ifndef SERVERMESSAGE_H
#define SERVERMESSAGE_H
#include <iostream>
#include <QString>
#include "client-gui/observer.h"

using namespace std;

class ServerMessage
{
public:
    ServerMessage(const QString &value);

    void addObserver(Observer *obs);

protected:

    QString type;
    Observer *observer;

};

#endif // SERVERMESSAGE_H
