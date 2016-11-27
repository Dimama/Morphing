#ifndef CAMERA_H
#define CAMERA_H


#include "structures.h"
#include <QVector3D>
#include <QMatrix4x4>
#include <vector>
using std::vector;

class Camera
{
public:
    Camera();
    Camera(const QVector3D &pos, const QVector3D &tar, const double &pitch, const double &yaw, const double &roll);

    void setPosition(const QVector3D&);
    void setTarget(const QVector3D&);

    void pitch(double angle);
    void yaw(double angle);
    void roll(double angle);

    void RotationUpDownSphere(double angle);
    void RotationRightLeftSphere(double angle);

    QMatrix4x4 GetViewMatrix();

private:
    QVector3D position;
    QVector3D target;
    QVector3D look;
    QVector3D up;
    QVector3D right;
};

#endif // CAMERA_H
