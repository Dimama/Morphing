#ifndef DRAWER_H
#define DRAWER_H

#include <QGraphicsScene>
#include <vector>
#include <QPainter>

using std::vector;

class Drawer
{
public:
    Drawer();
    Drawer(int,int);

    QGraphicsScene* getScene();

private:
    int width, height;
    QGraphicsScene* scene;
    QImage* img;
    QPainter* painter;
    vector<unsigned char> backBuffer;
    int backBufferLen;
    vector<float> depthBuffer;


};

#endif // DRAWER_H
