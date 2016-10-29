#include "mainwindow.h"
#include <QApplication>
#include <qjson-qt5/parser.h>
#include <qjson-qt5/qjson_export.h>
#include <qjson-qt5/serializer.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <qDebug>
#include <QFile>


QJsonObject ObjectFromString(const QString& in)
{
    QJsonObject obj;

    QJsonDocument doc = QJsonDocument::fromJson(in.toUtf8());

    // check validity of the document
    if(!doc.isNull())
    {
        if(doc.isObject())
        {
            obj = doc.object();

        }
        else
        {
            qDebug() << "Document is not an object" << endl;
        }
    }
    else
    {
        qDebug() << "Invalid JSON...\n" << in << endl;
    }

    return obj;
}

int main(int argv, char* argc[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();


    QFile file("cube2.babylon");

    bool a = file.open(QIODevice::ReadOnly);

    qDebug() << a;
    QString json = QString(file.readAll());
    file.close();

    // ADD COMMENT
    QJsonObject obj = ObjectFromString(json);
 //   qDebug() << obj;
    QJsonArray mesh = obj["meshes"].toArray();

    qDebug() << mesh[0];
    QJsonObject obj2 = mesh[0].toObject();
    QJsonArray arr = obj2["indices"].toArray();
    qDebug() << arr[1];


    return 0;
}
