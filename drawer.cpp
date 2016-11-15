#include "drawer.h"

Drawer::Drawer()
{

}

Drawer::Drawer(int width, int height)
{
    this->width = width;
    this->height = height;
    scene = new QGraphicsScene();

    img = new QImage(width-2, height-2, QImage::Format_RGBA8888);
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
