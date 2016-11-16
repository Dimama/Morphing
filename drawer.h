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

    void Render(const Mesh& mesh, const Camera& camera, QRgb color, bool shading);


private:
    int width, height;
    QGraphicsScene* scene;
    QImage* img;
    QPainter* painter;
    vector<unsigned char> backBuffer;
    int backBufferLen;
    vector<float> depthBuffer;

    void DrawPixel(int x, int y, float z, QRgb color);
    void DrawPoint(QVector3D v, QRgb color);
    void DrawLine(const Vertex& a, const Vertex&  b, QRgb color);
    Vertex ProjectVertex(const Vertex& vertex, const QMatrix4x4& transMatrix, const QMatrix4x4& worldMatrix);
    void Clear();


};

#endif // DRAWER_H
