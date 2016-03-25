#ifndef SERVERCONTROLLERTAB_H
#define SERVERCONTROLLERTAB_H

#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QLabel>

#include "observer.h"

class ServerTab : public QWidget, public Observer
{
public:
    ServerTab();

    void setTableRowCount(int count);
    void addClientLine(const QString &nom, const QString &id, const QString &ip,
                const QString &status, const QString &dateDeb, const QString &dateFin);
private:

    QTableWidget *tableWidget;
    QStringList listHeaders;

    int row_count;
};

#endif // SERVERCONTROLLERTAB_H
