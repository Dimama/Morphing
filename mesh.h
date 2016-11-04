#ifndef MESH_H
#define MESH_H

#include "structures.h"
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

#include <QVector3D>
#include <vector>
using std::vector;


/*  Класс объекта морфинга*/
class Mesh
{
public:
    Mesh();
    Mesh(const Mesh&);

    Mesh& operator= (const Mesh&);

    void LoadNormalsFromMesh(const vector<Face>& faces);
    void CalculateFaceNormals(int);
    void Morph(const vector<Face>& faces, int speed);
    vector<Face> CalculateMorphingFaces(const Mesh& mesh);
    static Mesh LoadFromJSON(const char* filename);
    int isEqual(const Mesh&);

    const vector<Face>& getFaces();

private:
    QString name;
    vector<Vertex> vertices;
    vector<Face> faces;
    QVector3D position;
    QVector3D rotation;

    static  QJsonObject ObjectFromString(const QString& in);

};

#endif // MESH_H
