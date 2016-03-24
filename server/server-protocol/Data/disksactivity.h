#ifndef LISTDISKS_H
#define LISTDISKS_H
#include "disque.h"
#include <iostream>
#include <QJsonObject>
#include <QList>
#include<QJsonArray>

class DisksActivity
{
public:
    DisksActivity();
    void updateData();
    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;
    ~DisksActivity();

private:
    QString type;
    QList <Disque> disks;
};
#endif // LISTDISKS_H
