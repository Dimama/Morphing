#include "mesh.h"

/* ПЕРЕНЕСТИ В *.H */

#include <qDebug>
#include <QFile>

Mesh::Mesh()
{

}

Mesh::Mesh(const Mesh &mesh)
{
    this->name = mesh.name;
    this->faces = mesh.faces;
    this->vertices = mesh.vertices;
    this->position = mesh.position;
    this->rotation = mesh.rotation;
}

Mesh &Mesh::operator=(const Mesh &mesh)
{
    this->name = mesh.name;
    this->faces = mesh.faces;
    this->vertices = mesh.vertices;
    this->position = mesh.position;
    this->rotation = mesh.rotation;

    return *this;
}

Mesh Mesh::LoadFromJSON(const char *filename)
{
    QFile file(filename);
    bool a = file.open(QIODevice::ReadOnly);

    if(!a)
    {
        // Выбросить ошибку открытия файла
    }

    qDebug() << a;

    // читаем текст из Json
    QString json = QString(file.readAll());

    file.close();


    /* Парсинг */
    QJsonObject json_obj = ObjectFromString(json);
    QJsonArray mesh = json_obj["meshes"].toArray();
    QJsonObject obj = mesh[0].toObject();

    QJsonArray vertices = obj["positions"].toArray();
    QJsonArray indices = obj["indices"].toArray();
    QJsonArray normals = obj["normals"].toArray();
    QJsonArray position = obj["position"].toArray();
    QString name = obj["name"].toString();
    int verticesCount = vertices.size()/3;
    int facesCount = indices.size()/3;

    Mesh model;
    model.name  = name;

    for(int i = 0; i < verticesCount; i++)
    {
        double x = vertices[i*3].toDouble();
        double y = vertices[i*3+1].toDouble();
        double z = vertices[i*3+1].toDouble();

        double nx = normals[i*3].toDouble();
        double ny = normals[i*3+1].toDouble();
        double nz = normals[i*3+2].toDouble();

        Vertex v = {Vector3(x,y,z), Vector3(nx,ny,nz)};

        model.vertices.push_back(v);
    }

    for(int i = 0; i < facesCount; i++)
    {
        int a = indices[i].toInt();
        int b = indices[i*3+1].toInt();
        int c = indices[i*3+2].toInt();

        Face f = {model.vertices[a], model.vertices[b], model.vertices[c]};

        model.faces.push_back(f);
    }

    model.position = Vector3(position[0].toDouble(), position[1].toDouble(), position[2].toDouble());

    return model;
}

int Mesh::isEqual(const Mesh &mesh)
{
   if(this->faces.size() != mesh.faces.size())  // разное число граней
        return 2;
   if(this->name == mesh.name)  // одинаковые объекты
       return 1;
   return 0;   //  объекты разные с одинаковым числом граней
}

QJsonObject Mesh::ObjectFromString(const QString &in)
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
            // Выбросить ошибку
            qDebug() << "Document is not an object" << endl;
        }
    }
    else
    {
        // Выбросить ошибку
        qDebug() << "Invalid JSON...\n" << in << endl;
    }

    return obj;
}
