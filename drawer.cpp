#include "drawer.h"
#include <omp.h>
#include <QColor>
#include <QTime>
#include <math.h>

Drawer::~Drawer()
{
    free(pixels);
    delete scene;
}

Drawer::Drawer(int width, int height)
{
    this->width = width-2;
    this->height = height-2;
    scene = new QGraphicsScene();

    QImage img(width-2, height-2, QImage::Format_RGB888);
    img.fill(Qt::white);
    pixels = (uchar*)malloc (this->width*this->height*3 * sizeof(uchar));
    scene->addPixmap(QPixmap::fromImage(img));
}

QGraphicsScene* Drawer::getScene()
{
    return this->scene;
}

void Drawer::Render(const Mesh& mesh, Camera& camera, QRgb color, bool shading)
{

    //    float pitch = rot.x(), yaw = rot.y(), roll = rot.z();

    //    QMatrix4x4 xrot(1,0,0,0,
    //                    0,cos(pitch),-sin(pitch),0,
    //                    0,sin(pitch),cos(pitch),0,
    //                    0,0,0,1);

    //    QMatrix4x4 yrot(cos(yaw),0,sin(yaw),0,
    //                    0,1,0,0,
    //                    -sin(yaw),0,cos(yaw),0,
    //                    0,0,0,1);

    //    QMatrix4x4 zrot(cos(roll),-sin(roll),0,0,
    //                    sin(roll),cos(roll),0,0,
    //                    0,0,1,0,
    //                    0,0,0,1);


    QTime t;
    t.start();
    Clear();

    /*вычисление матриц */


    QMatrix4x4 viewmMatrix = camera.GetViewMatrix();

    QMatrix4x4 projectionMatrix = Drawer::PerspectiveFovRH(0.7, (float)width/height, 0.01, 1);

    QVector3D rot = mesh.getRotation();

    QMatrix4x4 rotationMatrix = Drawer::RotationYawPitchRoll(rot.y(),rot.x(),rot.z());

    QMatrix4x4 trans;
    trans.translate(mesh.getPosition());

    QMatrix4x4 transformMatrix = rotationMatrix * trans * viewmMatrix * projectionMatrix;
    QMatrix4x4 worldMatrix;

    vector<Face> faces = mesh.getFaces();

#pragma omp parallel for schedule(dynamic, 1)
    for(unsigned int i = 0; i < faces.size(); i++)
    {
        Face face = faces[i];

        Vertex  a  = ProjectVertex(face.A, transformMatrix, worldMatrix);
        Vertex  b  = ProjectVertex(face.B, transformMatrix, worldMatrix);
        Vertex  c  = ProjectVertex(face.C, transformMatrix, worldMatrix);

        if(shading)
        {
            //
        }
        else
        {

            DrawLine(a,b,color);
            DrawLine(c,b,color);
            DrawLine(a,c,color);
        }
    }


    QImage img(pixels, this->width, this->height, this->width*3, QImage::Format_RGB888);

    scene->addPixmap(QPixmap::fromImage(img));
    qDebug() << "draw time: " << t.elapsed();
}

void Drawer::DrawPixel(int x, int y, float z, QRgb color)
{
    int i = x + y*this->width;
    if(depthBuffer[i] < z)
    {
        return;
    }
    depthBuffer[i] = z;

    int i3 = i*3;
    pixels[i3] = QColor(color).red();
    pixels[i3+1] = QColor(color).green();
    pixels[i3+2] = QColor(color).blue();

}

void Drawer::DrawPoint(QVector3D v, QRgb color)
{
    if(v.x() > 0 && v.y() > 0 && v.x() < this->width && v.y() < this->height)
        DrawPixel((int)v.x(), (int)v.y(), v.z(), color);
}

void Drawer::DrawLine(const Vertex& a, const Vertex&  b, QRgb color)
{

   int xa = (int)a.Coord.x();
   int ya = (int)a.Coord.y();
   int xb = (int)b.Coord.x();
   int yb = (int)b.Coord.y();

   int dx = abs(xb-xa);
   int dy = abs(yb-ya);

   int sx = (xa < xb) ? 1 : -1;
   int sy = (ya < yb) ? 1 : -1;
   int err = dx - dy;
   int err2;
   do
   {
        DrawPoint(QVector3D(xa,ya,0),color);
        err2 = 2*err;
        if(err2 > -dy)
        {
            err -= dy;
            xa += sx;
        }
        if(err2 < dx)
        {
            err += dx;
            ya += sy;
        }
   }
   while((xa != xb) || (yb != ya));

}

/* преобразовываем вершину для ее отображения */
Vertex Drawer::ProjectVertex(const Vertex &vertex, const QMatrix4x4 &transMatrix, const QMatrix4x4 &worldMatrix)
{
       QVector3D point2d = Drawer::TransformCoordinate(transMatrix,vertex.Coord); // ???

       float x = point2d.x()*width + width/2.0;
       float y = -point2d.y()*height + height/2.0;

       return {QVector3D(x,y,point2d.z()), vertex.Normal, vertex.WCoord};
}

QVector3D Drawer::TransformCoordinate(const QMatrix4x4 &mat, const QVector3D &vec)
{
    QVector4D v4d;

    v4d.setX(vec.x()*mat(0,0) + vec.y()*mat(1,0) + vec.z()*mat(2,0) + mat(3,0));
    v4d.setY(vec.x()*mat(0,1) + vec.y()*mat(1,1) + vec.z()*mat(2,1) + mat(3,1));
    v4d.setZ(vec.x()*mat(0,2) + vec.y()*mat(1,2) + vec.z()*mat(2,2) + mat(3,2));
    v4d.setW(1/(vec.x()*mat(0,3) + vec.y()*mat(1,3) + vec.z()*mat(2,3) + mat(3,3)));

    return QVector3D(v4d.x()*v4d.w(),v4d.y()*v4d.w(),v4d.z()*v4d.w());
}

QMatrix4x4 Drawer::RotationYawPitchRoll(float yaw, float pitch, float roll)
{
    QMatrix4x4 xrot(1,0,0,0,
                    0,cos(pitch),-sin(pitch),0,
                    0,sin(pitch),cos(pitch),0,
                    0,0,0,1);

    QMatrix4x4 yrot(cos(yaw),0,sin(yaw),0,
                    0,1,0,0,
                    -sin(yaw),0,cos(yaw),0,
                    0,0,0,1);

    QMatrix4x4 zrot(cos(roll),-sin(roll),0,0,
                    sin(roll),cos(roll),0,0,
                    0,0,1,0,
                    0,0,0,1);

    return yrot*xrot*zrot;
}

//Строит правостороннюю матрицу перспективной проекции на основе поля обзора.
/*Параметры
fieldOfViewY
Поле обзора в направлении оси Y в радианах.

aspectRatio
Пропорции, определенные как отношение ширины пространства обзора к высоте.

znearPlane

Z-значение ближней плоскости обзора.

zfarPlane

Z-значение дальней плоскости обзора.*/
QMatrix4x4 Drawer::PerspectiveFovRH(float fieldOfViewY, float aspectRatio, float znearPlane, float zfarPlane)
{
    float h = 1/tan(fieldOfViewY/2);
    float w = h/aspectRatio;

    return QMatrix4x4(w,0,0,0,
                      0,h,0,0,
                      0,0, zfarPlane/(znearPlane-zfarPlane), -1,
                      0,0,znearPlane*zfarPlane/(znearPlane-zfarPlane), 0);
}

void Drawer::Clear()
{
    memset(pixels,255,width*height*3*sizeof(uchar));
    depthBuffer.assign(this->height*this->width, FLT_MAX);
    scene->clear();
}

