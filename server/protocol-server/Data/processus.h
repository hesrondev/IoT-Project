#ifndef PROCESSUS_H
#define PROCESSUS_H

#include <iostream>
#include <QJsonObject>

using namespace std;

class Processus
{
public:
    Processus();
    QString getNom() const;
    void setNom(const QString &value);

    int getPid() const;
    void setPid(int value);

    bool getStatus() const;
    void setStatus(bool value);

    QString getUtilisateur() const;
    void setUtilisateur(const QString &value);

    int getUid() const;
    void setUid(int value);

    double getTaille() const;
    void setTaille(double value);

    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;

private:
    QString nom;
    int pid;
    bool status;
    QString utilisateur;
    int uid ;
    double taille;
};

#endif // PROCESSUS_H
