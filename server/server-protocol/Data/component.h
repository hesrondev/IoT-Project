#ifndef SERVERMESSAGE_H
#define SERVERMESSAGE_H
#include <iostream>
#include <QString>

using namespace std;

class Component
{
public:
    Component(const QString &value);
    virtual void updateData() = 0;
    virtual ~Component();

protected:

    QString type;

};

#endif // SERVERMESSAGE_H
