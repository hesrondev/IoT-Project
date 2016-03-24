#ifndef LISTPROCESSES_H
#define LISTPROCESSES_H


#include <QList>
#include "processus.h"

class ProcessesActivity
{
public:
    ProcessesActivity();
    void updateData();

    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;

    ~ProcessesActivity();

private:

    QList <Processus> processes;
};

#endif // LISTPROCESSES_H
