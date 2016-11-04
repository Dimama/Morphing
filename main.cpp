#include "mainwindow.h"
#include <QApplication>

#include <qDebug>
#include <QFile>

#include <mesh.h>

int main(int argc, char* argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();

    Mesh mesh1 = Mesh::LoadFromJSON("torus.babylon");
    Mesh mesh2 = Mesh::LoadFromJSON("monkey.babylon");
    Mesh mesh3 = Mesh::LoadFromJSON("Cylinder.babylon");
    Mesh mesh4 = Mesh::LoadFromJSON("conus.babylon");
    Mesh mesh5 = Mesh::LoadFromJSON("UVSphere.babylon");
    Mesh mesh7 = Mesh::LoadFromJSON("ICOSphere.babylon");
    Mesh mesh6 = Mesh::LoadFromJSON("cube.babylon");
    Mesh mesh8 = Mesh::LoadFromJSON("other.babylon");


    Mesh newMesh(mesh6);
    newMesh.LoadNormalsFromMesh(mesh7.getFaces());
    vector<Face> faces = mesh8.CalculateMorphingFaces(mesh6);
    qDebug()<< mesh8.isEqual(newMesh);
    return 0;
}
