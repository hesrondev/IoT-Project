#include "disksactivity.h"
DisksActivity::DisksActivity() : ServerMessage("disks")
{

}
void DisksActivity::updateData()
{
}
void DisksActivity::read(const QJsonObject &json)
{
    type = json["type"].toString();

    disks.clear();
    QJsonArray disksArray = json["disks"].toArray();
    for(int i = 0 ; i < disksArray.size(); ++i)
    {
        QJsonObject disksObject = disksArray[i].toObject();
        Disque disk;
        disk.read(disksObject);
        disks.append(disk);
    }
}
void DisksActivity::write(QJsonObject &json) const
{
    json["type"] = type;

    QJsonArray disksArray;
    foreach(Disque c , disks){
        QJsonObject disksObject;
        c.write(disksObject);
        disksArray.append(disksObject);
    }
    json["disks"] = disksArray;
}
DisksActivity::~DisksActivity()
{
}
