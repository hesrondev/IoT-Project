#ifndef DATA_H
#define DATA_H
#include <iostream>
using namespace std;
#include"cpu.h"
#include"DisksActivity.h"
#include"network.h"
#include"ProcessesActivity.h"
#include"ram.h"
#include"serveur.h"
#include"client.h"

class Data
{

public:
    Data(ProcessesActivity *processes, Cpu *cp, DisksActivity *disks, Network *net, Ram *mem, Serveur *serv);
    void read(const QJsonObject &json);
    void write(QJsonObject &json);

    void updateData(QList<Client *> clients);

private:

    QString type;

    Cpu *cpu;
    DisksActivity *diskactivity;
    Network *network;
    ProcessesActivity *processesActivity;
    Ram *ram;
    Serveur *serveur;
};
#endif // DATA_H
