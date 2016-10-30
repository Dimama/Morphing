#include "vector3.h"

Vector3::Vector3()
{}

Vector3::Vector3(const Vector3 &v): X(v.X), Y(v.Y), Z(v.Z)
{}

Vector3::Vector3(double _X, double _Y, double _Z): X(_X), Y(_Y), Z(_Z)
{}

Vector3::Vector3(double Value): X(Value), Y(Value), Z(Value)
{}

Vector3::~Vector3()
{
    this->X = 0;
    this->Y = 0;
    this->Z = 0;
}

Vector3 &Vector3::operator =(const Vector3 &v)
{
    this->X = v.X;
    this->Y = v.Y;
    this->Z = v.Z;

    return *this;
}

const double &Vector3::get_X() const
{
    return this->X;
}

const double &Vector3::get_Y() const
{
    return this->Y;
}

const double &Vector3::get_Z() const
{
    return this->Z;
}

void Vector3::set_X(double x)
{
    this->X = x;
}

void Vector3::set_Y(double y)
{
    this->Y = y;
}

void Vector3::set_Z(double z)
{
    this->Z = z;
}

