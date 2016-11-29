#ifndef DRAWER_H
#define DRAWER_H

#include <QGraphicsScene>
#include <vector>
#include <QPainter>
#include <structures.h>
#include <float.h>
#include <camera.h>
#include <mesh.h>
#include <QMatrix4x4>

using std::vector;

class Drawer
{
public:
    Drawer();
    Drawer(int,int);

    ~Drawer();

    QGraphicsScene* getScene();
    void Render(const Mesh& mesh, Camera& camera, QRgb color, bool shading);


    // вернуть в private
    static QVector3D TransformCoordinate(const QMatrix4x4& mat, const QVector3D& vec);
    static QMatrix4x4 RotationYawPitchRoll(float yaw, float pitch, float roll);
    static QMatrix4x4 PerspectiveFovRH(float fieldOfViewY,float aspectRatio,float znearPlane, float zfarPlane);

private:
    int width, height;
    QGraphicsScene* scene;
    QPainter* painter;
    uchar* pixels;
    vector<float> depthBuffer;

    void DrawPixel(int x, int y, float z, QRgb color);
    void DrawPoint(QVector3D v, QRgb color);
    void DrawLine(const Vertex& a, const Vertex&  b, QRgb color);
    Vertex ProjectVertex(const Vertex& vertex, const QMatrix4x4& transMatrix, const QMatrix4x4& worldMatrix);


    void Clear();


};

#endif // DRAWER_H
