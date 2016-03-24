#include "data.h"

Data::Data(ProcessesActivity *processes, Cpu *cp, DisksActivity *disks, Network *net, Ram *mem, Serveur *serv)
{
    type = "data";

    processesActivity = processes;
    cpu = cp;
    diskactivity = disks;
    network = net;
    ram = mem;
    serveur = serv;
}

void Data::read(const QJsonObject &json)
{
    QJsonObject jsonObject;
    type = json["type"].toString();
    jsonObject = json["cpu"].toObject();
    cpu->read(jsonObject);

    jsonObject = json["diskactivity"].toObject();
    diskactivity->read(jsonObject);

    jsonObject = json["network"].toObject();
    network->read(jsonObject);

    jsonObject = json["processesActivity"].toObject();
    processesActivity->read(jsonObject);

    jsonObject = json["ram"].toObject();
    ram->read(jsonObject);

    jsonObject = json["serveur"].toObject();
    serveur->read(jsonObject);
}

void Data::write(QJsonObject &json)
{
    QJsonObject jsonObject;
    json["type"] = type;

    cpu->write(jsonObject);
    json["cpu"] = jsonObject;

    diskactivity->write(jsonObject);
    json["diskactivity"] = jsonObject;

    network->write(jsonObject);
    json["network"] = jsonObject;

    processesActivity->write(jsonObject);
    json["processesActivity"] = jsonObject;

    ram->write(jsonObject);
    json["ram"] = jsonObject;

    serveur->write(jsonObject);
    json["serveur"] = jsonObject;
}

Data::~Data()
{

}
