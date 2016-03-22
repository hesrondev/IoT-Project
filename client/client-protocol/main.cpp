#include <QApplication>
#include "clientmainwindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QFile file(":style/default-style");
    file.open(QFile::ReadOnly);
    QString designString = QLatin1String(file.readAll());

    qApp->setStyleSheet(designString);

    ClientMainWindow fenetre;
    fenetre.show();

    return app.exec();
}
