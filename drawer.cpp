#include "drawer.h"


Drawer::~Drawer()
{
    delete painter;
    delete img;
    delete scene;
}

Drawer::Drawer(int width, int height)
{
    this->width = width;
    this->height = height;
    scene = new QGraphicsScene();

    img = new QImage(width, height, QImage::Format_RGBA8888);
    img->fill(Qt::white);

    painter = new QPainter(img);
    painter->setPen(Qt::black);
    img->setPixel(10,10,qRgba(0,0,0,255));
    scene->addPixmap(QPixmap::fromImage(*img));
}

QGraphicsScene* Drawer::getScene()
{
    return this->scene;
}

void Drawer::Render(const Mesh& mesh, const Camera& camera, QRgb color, bool shading)
{
    Clear();

    /*тут должен быть код */
    QMatrix4x4* transformMatrix = new QMatrix4x4();
    QMatrix4x4* worldMatrix = new QMatrix4x4();

    vector<Face> faces = mesh.getFaces();

    Face face;

    for(unsigned int i = 0; i < faces.size(); i++)
    {
        face = faces[i];

        Vertex  a  = ProjectVertex(face.A, *transformMatrix, *worldMatrix);
        Vertex  b  = ProjectVertex(face.B, *transformMatrix, *worldMatrix);
        Vertex  c  = ProjectVertex(face.C, *transformMatrix, *worldMatrix);

        if(shading)
        {
            ///
        }
        else
        {
            DrawLine(a,b,color);
            DrawLine(c,b,color);
            DrawLine(a,c,color);
        }
    }

    scene->addPixmap(QPixmap::fromImage(*img));
}

void Drawer::DrawPixel(int x, int y, float z, QRgb color)
{
    int i = x + y*this->width;
    if(depthBuffer[i] < z)
    {
        return;
    }

    depthBuffer[i] = z;

    img->setPixel(x,y,color);
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
       QVector3D point2d;

       point2d.setX(vertex.Coord.x() *width + width/2.0);
       point2d.setY(-vertex.Coord.y() *height + height/2.0);
       point2d.setZ(vertex.Coord.z());

       return {point2d, vertex.Normal, vertex.WCoord};
}

void Drawer::Clear()
{
    for(int i = 0; i < this->height*this->width; i ++)
        depthBuffer.push_back(FLT_MAX);  // Поменять
   // this->scene->clear();  //  img->fill(белый)
    img->fill(Qt::white);
}

