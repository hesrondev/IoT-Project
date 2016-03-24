#ifndef LISTPROCESSES_H
#define LISTPROCESSES_H
#include "processus.h"
#include <iostream>
#include <QJsonObject>
#include <QList>
#include<QJsonArray>
class ProcessesActivity
{
public:
    ProcessesActivity();
    void updateData();
    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;
    ~ProcessesActivity();
private:
    QString type;
    QList <Processus *> processes;
};
#endif // LISTPROCESSES_H
