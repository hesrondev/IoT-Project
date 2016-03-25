#ifndef LISTDISKS_H
#define LISTDISKS_H
#include "disque.h"
#include <iostream>
#include <QJsonObject>
#include <QList>
#include<QJsonArray>

#include "serverMessage.h"


class DisksActivity : public ServerMessage
{
public:
    DisksActivity();
    void updateData();
    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;
    ~DisksActivity();

private:
    QList <Disque> disks;
};
#endif // LISTDISKS_H
