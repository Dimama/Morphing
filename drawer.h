#ifndef DRAWER_H
#define DRAWER_H

#include <QGraphicsScene>
#include <QPainter>
#include <float.h>
#include <camera.h>
#include <mesh.h>
#include <QMatrix4x4>
#include <omp.h>
#include <QColor>
#include <QTime>
#include <math.h>

using std::vector;

class Drawer
{
public:
    Drawer();
    Drawer(int,int);

    ~Drawer();

    QGraphicsScene* getScene();
    void Render(const Mesh& mesh, Camera& camera, QRgba64 color, bool shading);


private:
    int width, height;
    QGraphicsScene* scene;
    QPainter* painter;
    uchar* pixels;
    vector<float> depthBuffer;

    void DrawPixel(int x, int y, float z, QRgba64 color);
    void DrawPoint(QVector3D v, QRgba64 color);
    void DrawLine(const Vertex& a, const Vertex& b, QRgba64 color);

    Vertex ProjectVertex(const Vertex& vertex, const QMatrix4x4& transMatrix, const QMatrix4x4& worldMatrix);
    static QVector3D TransformCoordinate(const QMatrix4x4& mat, const QVector3D& vec);
    static QMatrix4x4 RotationYawPitchRoll(float yaw, float pitch, float roll);
    static QMatrix4x4 PerspectiveFovRH(float fieldOfViewY,float aspectRatio,float znearPlane, float zfarPlane);

    /* Методы для освещения*/
    static float Clamp(float value);
    static float Interpolate(float min, float max, float grad);
    static float CalculateNDotL(const QVector3D& v, const QVector3D l_pos, QVector3D& n);
    void DrawScanLine(const ScanLine& data, const Vertex& va, const Vertex& vb, const Vertex& vc, const Vertex& vd, QRgba64  color);
    void DrawTriangle(Vertex& v1, Vertex& v2, Vertex& v3, QRgba64 color);

    void Clear();

};

#endif // DRAWER_H
