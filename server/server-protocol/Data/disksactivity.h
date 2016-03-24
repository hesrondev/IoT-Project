#ifndef LISTDISKS_H
#define LISTDISKS_H

#include <QList>
#include "disque.h"


class DisksActivity
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
