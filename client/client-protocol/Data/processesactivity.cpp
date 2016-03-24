#include "processesactivity.h"
ProcessesActivity::ProcessesActivity()
{
    type = "processes";
}

void ProcessesActivity::updateData()
{
}

void ProcessesActivity::read(const QJsonObject &json)
{
    type = json["processes"].toString();

    // QList <Processus> processes;
    processes.clear();
    QJsonArray processesArray = json["processes"].toArray();
    for(int i = 0 ; i < processesArray.size(); ++i)
    {
        QJsonObject processesObject = processesArray[i].toObject();
        Processus processus;
        processus.read(processesObject);
        processes.append(&processus);
    }
}

void ProcessesActivity::write(QJsonObject &json) const
{
    json["type"] = type;

    QJsonArray processesArray;
    foreach(Processus* c , processes){
        QJsonObject processesObject;
        c->write(processesObject);
        processesArray.append(processesObject);
    }
    json["processes"] = processesArray;
}

ProcessesActivity::~ProcessesActivity()
{
}
