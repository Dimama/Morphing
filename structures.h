#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <QVector3D>


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


typedef struct _ScanLine
{
    int currentY;
    float ndotla;
    float ndotlb;
    float ndotlc;
    float ndotld;

}ScanLine;

#endif // STRUCTURES_H
