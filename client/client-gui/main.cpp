#include "mainwindow.h"

#include <QApplication>
#include <QFile>

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(":style/default-style");
    file.open(QFile::ReadOnly);
    QString designString = QLatin1String(file.readAll());

    qApp->setStyleSheet(designString);

    MainWindow w;
    w.show();

    return a.exec();
}
