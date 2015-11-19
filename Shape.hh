#ifndef SHAPE_HH_
#define SHAPE_HH_

class Shape{
protected:
    double x, y, z;
public:
    Shape(double x, double y, double z): x(x), y(y), z(z){}
    int getX(), getY(), getZ();
    void setX(double x);
    void setY(double y);
    void setZ(double z);

};

#endif // SHAPE_HH_
