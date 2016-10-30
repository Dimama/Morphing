#ifndef MESH_H
#define MESH_H

#include "structures.h"
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <vector>
using std::vector;


/*  Класс объекта морфинга*/
class Mesh
{
public:
    Mesh();
    Mesh(const Mesh&);

    Mesh& operator= (const Mesh&);

    static Mesh LoadFromJSON(const char* filename);

    int isEqual(const Mesh&);

private:
    QString name;
    vector<Vertex> vertices;
    vector<Face> faces;
    Vector3 position;
    Vector3 rotation;

   static  QJsonObject ObjectFromString(const QString& in);

};

#endif // MESH_H
