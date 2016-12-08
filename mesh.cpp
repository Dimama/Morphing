#include "mesh.h"

Mesh::Mesh()
{

}

Mesh::Mesh(const Mesh &mesh)
{
    this->name = mesh.name;
    this->faces = mesh.faces;
    this->position = mesh.position;
    this->rotation = mesh.rotation;
}

Mesh::~Mesh()
{
    if(this->faces.size() > 0)
        this->faces.clear();
}

Mesh &Mesh::operator=(const Mesh &mesh)
{
    this->name = mesh.name;
    this->faces = mesh.faces;
    this->position = mesh.position;
    this->rotation = mesh.rotation;

    return *this;
}


void Mesh::LoadNormalsFromMesh(const Mesh &mesh)
{
    for(unsigned int i = 0; i < this->faces.size(); i++)
    {
        this->faces[i].A.Normal = mesh.faces[i].A.Normal;
        this->faces[i].B.Normal = mesh.faces[i].B.Normal;
        this->faces[i].C.Normal = mesh.faces[i].C.Normal;
    }
}
void Mesh::CalculateFaceNormals(int i)
{
    QVector3D v1 = this->faces[i].A.Coord - this->faces[i].B.Coord;
    QVector3D v2 = this->faces[i].C.Coord - this->faces[i].A.Coord;

    QVector3D normal = QVector3D::crossProduct(v1,v2);
    normal.normalize();

    this->faces[i].A.Normal = normal;
    this->faces[i].B.Normal = normal;
    this->faces[i].C.Normal = normal;
}

void Mesh::Morph(const vector<Face> &faces, int speed)
{
    for(unsigned int i = 0; i < this->faces.size(); i++)
    {
        this->faces[i].A.Coord += speed * (faces[i].A.Coord/1000);
        this->faces[i].B.Coord += speed * (faces[i].B.Coord/1000);
        this->faces[i].C.Coord += speed * (faces[i].C.Coord/1000);
        this->CalculateFaceNormals(i);
    }
}



vector<Face> Mesh::CalculateMorphingFaces(const Mesh &mesh)
{
    vector<Face> faces;

    for (unsigned int i = 0; i < this->faces.size(); i++)
    {
        Face f;
        f.A.Coord = mesh.faces[i].A.Coord - this->faces[i].A.Coord;
        f.B.Coord = mesh.faces[i].B.Coord - this->faces[i].B.Coord;
        f.C.Coord = mesh.faces[i].C.Coord - this->faces[i].C.Coord;

        f.A.Normal = mesh.faces[i].A.Normal;
        f.B.Normal = mesh.faces[i].B.Normal;
        f.C.Normal = mesh.faces[i].C.Normal;

        faces.push_back(f);
    }

    return faces;
}

Mesh Mesh::LoadFromJSON(const char *filename)
{
    QFile file(filename);
    bool a = file.open(QIODevice::ReadOnly);

    if(!a)
    {
        throw E_OpenFile();
    }

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

    vector<Vertex> tmp_vertices;
    for(int i = 0; i < verticesCount; i++)
    {
        double x = vertices[i*3].toDouble();
        double y = vertices[i*3+1].toDouble();
        double z = vertices[i*3+2].toDouble();

        double nx = normals[i*3].toDouble();
        double ny = normals[i*3+1].toDouble();
        double nz = normals[i*3+2].toDouble();

        Vertex v = {QVector3D(x,y,z), QVector3D(nx,ny,nz), QVector3D(0,0,0)};

        tmp_vertices.push_back(v);
    }


    for(int i = 0; i < facesCount; i++)
    {
        int a = indices[i*3].toInt();
        int b = indices[i*3+1].toInt();
        int c = indices[i*3+2].toInt();

        Face f = {tmp_vertices[a], tmp_vertices[b], tmp_vertices[c]};

        model.faces.push_back(f);
    }
    tmp_vertices.clear();

    model.position = QVector3D(position[0].toDouble(), position[1].toDouble(), position[2].toDouble());

    return model;
}

int Mesh::isEqual(const Mesh &mesh)
{
   if(this->faces.size() != mesh.faces.size())  // разное число граней
        return 2;
   if(this->name == mesh.name)  // одинаковые объекты
       return 1;
   return 0;    //  объекты разные с одинаковым числом граней
}

const vector<Face> &Mesh::getFaces()
{
    return this->faces;
}

const vector<Face> &Mesh::getFaces() const
{
    return this->faces;
}

QJsonObject Mesh::ObjectFromString(const QString &in)
{
    QJsonObject obj;

    QJsonDocument doc = QJsonDocument::fromJson(in.toUtf8());

    if(!doc.isNull())
    {
        if(doc.isObject())
        {
            obj = doc.object();
        }
        else
        {
            throw E_ReadFile();
        }
    }
    else
    {
        throw E_ReadFile();
    }

    return obj;
}

QString &Mesh::getName()
{
    return this->name;
}

void Mesh::setName(const QString &name)
{
    this->name = name;
}

void Mesh::setRotation(int x, int y, int z)
{
    this->rotation.setX(this->rotation.x() + x * 0.02);
    this->rotation.setY(this->rotation.y() + y * 0.02);
    this->rotation.setZ(this->rotation.z() + z * 0.02);
}

QVector3D Mesh::getRotation() const
{
    return this->rotation;
}

QVector3D Mesh::getPosition() const
{
    return this->position;
}

