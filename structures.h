#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <QVector3D>

/* Структуры данных*/

typedef struct _Vertex
{
    QVector3D Coord;
    QVector3D Normal;
    QVector3D WCoord;
}Vertex;

typedef struct _Face
{
    Vertex A;
    Vertex B;
    Vertex C;
}Face;


#endif // STRUCTURES_H
