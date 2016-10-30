#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "vector3.h"

/* Структуры данных*/

typedef struct _Vertex
{
    Vector3 Coord;
    Vector3 Normal;
    Vector3 WCoord;
}Vertex;

typedef struct _Face
{
    Vertex A;
    Vertex B;
    Vertex C;
}Face;


#endif // STRUCTURES_H
