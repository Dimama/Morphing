#ifndef VECTOR3_H
#define VECTOR3_H


/* Математический вектор разменрности 3 */
class Vector3
{

public:
    Vector3();
    Vector3(const Vector3& vect);
    Vector3(double _X, double _Y, double _Z);
    Vector3(double Value);

    ~Vector3();

    Vector3& operator = (const Vector3&);

    const double& get_X() const;
    const double& get_Y() const;
    const double& get_Z() const;

    void set_X(double);
    void set_Y(double);
    void set_Z(double);

private:
    double X;
    double Y;
    double Z;
};

#endif // VECTOR3_H
