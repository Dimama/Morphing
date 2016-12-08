#include "drawer.h"


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

    QImage img(width-2, height-2, QImage::Format_RGBA8888);
    img.fill(Qt::white);
    pixels = (uchar*)malloc(this->width*this->height*4 * sizeof(uchar));
    scene->addPixmap(QPixmap::fromImage(img));
}

QGraphicsScene* Drawer::getScene()
{
    return this->scene;
}

void Drawer::Render(const Mesh& mesh, Camera& camera, QRgba64 color, bool shading)
{

    QTime t;
    t.start();
    Clear();

    QMatrix4x4 viewmMatrix = camera.GetViewMatrix();

    QMatrix4x4 projectionMatrix = Drawer::PerspectiveFovRH(0.7, (float)width/height, 0.01, 1);

    QVector3D rot = mesh.getRotation();

    QMatrix4x4 rotationMatrix = (Drawer::RotationYawPitchRoll(rot.y(),rot.x(),rot.z())).transposed();

    QMatrix4x4 trans;
    trans.translate(mesh.getPosition());

    QMatrix4x4 worldMatrix  = rotationMatrix * trans;
    QMatrix4x4 transformMatrix = worldMatrix * viewmMatrix * projectionMatrix;


    vector<Face> faces = mesh.getFaces();

#pragma omp parallel for
    for(unsigned int i = 0; i < faces.size(); i++)
    {
        Face face = faces[i];

        Vertex  a  = ProjectVertex(face.A, transformMatrix, worldMatrix);
        Vertex  b  = ProjectVertex(face.B, transformMatrix, worldMatrix);
        Vertex  c  = ProjectVertex(face.C, transformMatrix, worldMatrix);

        if(shading)
        {
            DrawTriangle(a,b,c,color);
        }
        else
        {
            DrawLine(a,b,color);
            DrawLine(c,b,color);
            DrawLine(a,c,color);
        }
    }


    QImage img(pixels, this->width, this->height, this->width*4, QImage::Format_RGBA8888);

    scene->addPixmap(QPixmap::fromImage(img));
    qDebug() << "draw time: " << t.elapsed();
}

void Drawer::DrawPixel(int x, int y, float z, QRgba64 color)
{

    int i = x + y*this->width;
    if(depthBuffer[i] < z)
    {
        return;
    }
    depthBuffer[i] = z;

    pixels[i*4] = color.red();
    pixels[i*4+1] = color.green();
    pixels[i*4+2] = color.blue();
    pixels[i*4+3] = color.alpha();
}

void Drawer::DrawPoint(QVector3D v, QRgba64 color)
{
    if(v.x() > 0 && v.y() > 0 && v.x() < this->width && v.y() < this->height)
        DrawPixel((int)v.x(), (int)v.y(), v.z(), color);
}

void Drawer::DrawLine(const Vertex& a, const Vertex&  b, QRgba64 color)
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
       QVector3D point2d = Drawer::TransformCoordinate(transMatrix,vertex.Coord);

       QVector3D point3d = Drawer::TransformCoordinate(worldMatrix, vertex.Coord);
       QVector3D norm3d = Drawer::TransformCoordinate(worldMatrix, vertex.Normal);

       float x = point2d.x()*width + width/2.0;
       float y = -point2d.y()*height + height/2.0;

       return {QVector3D(x,y,point2d.z()), norm3d, point3d};
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

float Drawer::Clamp(float value)
{
    return std::max((float)0, std::min(value,(float)1));
}

float Drawer::Interpolate(float min, float max, float grad)
{
    return min + (max - min) * Clamp(grad);
}

/* Cкалярное произведение вектора нормали и вектора освещения*/
float Drawer::CalculateNDotL(const QVector3D &v, const QVector3D l_pos, QVector3D &n)
{
    QVector3D l_dir = l_pos - v;

    n.normalize();
    l_dir.normalize();

    return std::max((float)0, QVector3D::dotProduct(n, l_dir));
}

void Drawer::DrawScanLine(const ScanLine &data, const Vertex &va, const Vertex &vb, const Vertex &vc, const Vertex &vd, QRgba64 color)
{
    QVector3D pa = va.Coord;
    QVector3D pb = vb.Coord;
    QVector3D pc = vc.Coord;
    QVector3D pd = vd.Coord;

    float grad1, grad2;

    if(pa.y() == pb.y())
        grad1 = 1;
    else
        grad1 = (data.currentY -pa.y()) / (pb.y() - pa.y());

    if(pc.y() == pd.y())
        grad2 = 1;
    else
        grad2 = (data.currentY - pc.y()) / (pd.y() - pc.y());


    int sx = (int)Interpolate(pa.x(), pb.x(), grad1);
    int ex = (int)Interpolate(pc.x(), pd.x(), grad2);

    float sz = Interpolate(pa.z(), pb.z(), grad1);
    float ez = Interpolate(pc.z(), pd.z(), grad2);

    float snl = Interpolate(data.ndotla, data.ndotlb, grad1);
    float enl = Interpolate(data.ndotlc, data.ndotld, grad2);

    for(int x = sx; x < ex; x++)
    {
        float grad = (float)(x-sx)/(ex-sx);

        float z = Interpolate(sz,ez,grad);
        float ndotl = Interpolate(snl,enl,grad);

        float alpha = 255 - (int)(color.alpha()*ndotl/3);
        float blue = (color.blue()*ndotl);
        float green = (color.green()*ndotl);
        float red = (color.red()*ndotl);
        DrawPoint(QVector3D(x,data.currentY,z), qRgba64(red,green,blue,alpha));
    }
}

void Drawer::DrawTriangle(Vertex &v1, Vertex &v2, Vertex &v3, QRgba64 color)
{
    /*Сортировка точек в порядке v1.y v2.y v3.y*/
    if(v1.Coord.y() > v2.Coord.y())
        std::swap(v1,v2);

    if(v2.Coord.y() > v3.Coord.y())
        std::swap(v2,v3);

    if(v1.Coord.y() > v2.Coord.y())
        std::swap(v1,v2);

    QVector3D p1 = v1.Coord;
    QVector3D p2 = v2.Coord;
    QVector3D p3 = v3.Coord;

    QVector3D light_source = QVector3D(0,0,-10);

    float nl1 = CalculateNDotL(v1.WCoord,light_source,v1.Normal);
    float nl2 = CalculateNDotL(v2.WCoord,light_source,v2.Normal);
    float nl3 = CalculateNDotL(v3.WCoord,light_source,v3.Normal);

    ScanLine data;

    float k12, k13;

    // Вычисление угловых коэффциентов прямых
    if(p2.y() - p1.y() > 0)
        k12 = (p2.x() - p1.x()) / (p2.y()-p1.y());
    else
        k12 = 0;

    if(p3.y() - p1.y() > 0)
        k13 = (p3.x() - p1.x()) / (p3.y()-p1.y());
    else
        k13 = 0;


    if (k12 == 0)
    {
        if (k13 < 0)
        {
            for (int y = (int)p1.y(); y <= (int)p3.y(); y++)
            {
                data.currentY = y;

                if (y < p2.y())
                {
                    data.ndotla = nl1;
                    data.ndotlb = nl2;
                    data.ndotlc = nl1;
                    data.ndotld = nl3;
                    DrawScanLine(data, v1, v2, v1, v3, color);
                }
                else
                {
                    data.ndotla = nl2;
                    data.ndotlb = nl3;
                    data.ndotlc = nl1;
                    data.ndotld = nl3;
                    DrawScanLine(data, v2, v3, v1, v3, color);
                }
            }
         }
         else
         {
            for (int y = (int)p1.y(); y <= (int)p3.y(); y++)
            {
                data.currentY = y;

                if (y < p2.y())
                {
                    data.ndotla = nl1;
                    data.ndotlb = nl3;
                    data.ndotlc = nl1;
                    data.ndotld = nl2;
                    DrawScanLine(data, v1, v3, v1, v2, color);
                }
                else
                {
                    data.ndotla = nl1;
                    data.ndotlb = nl3;
                    data.ndotlc = nl2;
                    data.ndotld = nl3;
                    DrawScanLine(data, v1, v3, v2, v3, color);
                }

            }
        }
    }

    if (k12 > k13)
    {
        for (int y = (int)p1.y(); y <= (int)p3.y(); y++)
        {
            data.currentY = y;

            if (y < p2.y())
            {
                data.ndotla = nl1;
                data.ndotlb = nl3;
                data.ndotlc = nl1;
                data.ndotld = nl2;
                DrawScanLine(data, v1, v3, v1, v2, color);
            }
            else
            {
                data.ndotla = nl1;
                data.ndotlb = nl3;
                data.ndotlc = nl2;
                data.ndotld = nl3;
                DrawScanLine(data, v1, v3, v2, v3, color);
            }
        }
    }

    if (k12 < k13)
    {
        for (int y = (int)p1.y(); y <= (int)p3.y(); y++)
        {
            data.currentY = y;

            if (y < p2.y())
            {
                data.ndotla = nl1;
                data.ndotlb = nl2;
                data.ndotlc = nl1;
                data.ndotld = nl3;
                DrawScanLine(data, v1, v2, v1, v3, color);
            }
            else
            {
                data.ndotla = nl2;
                data.ndotlb = nl3;
                data.ndotlc = nl1;
                data.ndotld = nl3;
                DrawScanLine(data, v2, v3, v1, v3, color);
            }
        }
    }
}



void Drawer::Clear()
{
    memset(pixels,255,width*height*4*sizeof(uchar));
    depthBuffer.assign(this->height*this->width, FLT_MAX);
    scene->clear();
}

