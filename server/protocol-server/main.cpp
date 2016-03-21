#include "FenServeur.h"
#include "Data/cpu.h"
#include <QJsonObject>
#include <QJsonDocument>

#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
       QApplication app(argc, argv);

        FenServeur fenetre;
        fenetre.show();

        /*
        Cpu cpu;
        QJsonObject  js ;
        cpu.write(js);

        QJsonDocument doc(js);

        QString str(doc.toJson(QJsonDocument::Compact));

        cout << str.toStdString() << endl;
        
        Cpu cpu_2;

        QJsonDocument doc2 = QJsonDocument::fromJson(str.toUtf8());
        QJsonObject js2;

        if (!doc2.isNull())
        {
            if (doc2.isObject())
            {
                js2 = doc2.object();
            }

            else
                qDebug() << "doc2 is not an object" << endl;
        }

        else
            qDebug() << "INVALID JSON\n" << str << endl;

        cpu_2.read(js2);

        cout << cpu_2.getNom().toStdString() << endl;*/

        return app.exec();
}

