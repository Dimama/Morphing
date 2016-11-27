#include "camera.h"

Camera::Camera()
{
    this->right = QVector3D(1,0,0);
    this->up = QVector3D(0,1,0);
    this->look = QVector3D(0,0,1);
}

Camera::Camera(const QVector3D &pos, const QVector3D &tar, const double &pitch, const double &yaw, const double &roll)
{
    this->position = pos;
    this->target = tar;
    this->right = QVector3D(1,0,0);
    this->up = QVector3D(0,1,0);
    this->look = QVector3D(0,0,1);
    this->pitch(pitch);
    this->yaw(yaw);
    this->roll(roll);
}

void Camera::setPosition(const QVector3D& pos)
{
    this->position = pos;
}

void Camera::setTarget(const QVector3D& targ)
{
    this->target = targ;
}

void Camera::pitch(double angle)
{
    QMatrix4x4 tr;
    tr.rotate(angle,this->right);

    this->up = this->up * tr;
    this->look = this->look * tr;
}

void Camera::yaw(double angle)
{
    QMatrix4x4 tr;
    tr.rotate(angle,this->up);

    this->right = this->right * tr;
    this->look = this->look * tr;
}

void Camera::roll(double angle)
{
    QMatrix4x4 tr;
    tr.rotate(angle,this->look);

    this->right = this->right * tr;
    this->up = this->up * tr;
}

void Camera::RotationUpDownSphere(double angle)
{
    QMatrix4x4 tr;
    tr.rotate(angle,this->up);
    this->right = this->right * tr;
    this->look = this->look * tr;
    QMatrix4x4 move;
    move.translate(-(this->target));
    move.rotate(angle,this->up);
    move.translate(this->target);

    this->position = this->position * move;
}

void Camera::RotationRightLeftSphere(double angle)
{
    QMatrix4x4 tr;
    tr.rotate(angle,this->right);
    this->up = this->up * tr;
    this->look = this->look * tr;
    QMatrix4x4 move;
    move.translate(-(this->target));
    move.rotate(angle,this->right);
    move.translate(this->target);

    this->position = this->position * move;
}

QMatrix4x4 Camera::GetViewMatrix()
{
//     this->look.normalize();
//     this->up = QVector3D::crossProduct(this->look,this->right);
//     this->up.normalize();

//     this->right = QVector3D::crossProduct(this->up,this->look);
//     this->right.normalize();

    this->look = this->target - this->position;
    this->look.normalize();
    this->right = QVector3D::crossProduct(this->up,this->look);
    this->right.normalize();
    this->up = QVector3D::crossProduct(this->look,this->right);

    float x = -QVector3D::dotProduct(this->right,this->position);
    float y = -QVector3D::dotProduct(this->up,this->position);
    float z = -QVector3D::dotProduct(this->look,this->position);

     qDebug() << "x cam: " << x;
     qDebug() << "y cam:" << y;
     qDebug() << "z cam:" << z;

     QMatrix4x4 tmp;

     tmp.setRow(0,QVector4D(right.x(), up.x(), look.x(), 0));
     tmp.setRow(1,QVector4D(right.y(), up.y(), look.y(), 0));
     tmp.setRow(2,QVector4D(right.z(), up.z(), look.z(), 0));
     tmp.setRow(3,QVector4D(x, y, z, 1));
     return tmp;
}
