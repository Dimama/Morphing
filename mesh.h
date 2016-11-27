#ifndef MESH_H
#define MESH_H

#include "structures.h"
#include "fileerrors.h"
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
    ~Mesh();
    Mesh& operator= (const Mesh&);

    void LoadNormalsFromMesh(const Mesh& mesh);
    void CalculateFaceNormals(int);
    void Morph(const vector<Face>& faces, int speed);
    vector<Face> CalculateMorphingFaces(const Mesh& mesh);
    static Mesh LoadFromJSON(const char* filename);
    int isEqual(const Mesh&);
    QString& getName();
    void setName(const QString& name);

    void setRotation(int x, int y, int z);
    QVector3D getRotation() const;
    QVector3D getPosition() const;

    const vector<Face>& getFaces();
    const vector<Face>& getFaces() const ;

private:
    QString name;
    vector<Vertex> vertices;
    vector<Face> faces;
    QVector3D position;
    QVector3D rotation;

    static  QJsonObject ObjectFromString(const QString& in);

};

#endif // MESH_H
