#ifndef SERVERMESSAGE_H
#define SERVERMESSAGE_H
#include <iostream>
#include <QString>

using namespace std;

class ServerMessage
{
public:
    ServerMessage(const QString &value);

protected:

    QString type;


};

#endif // SERVERMESSAGE_H
