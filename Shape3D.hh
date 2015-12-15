//Shape3D class is derived class of Shape and will show 3D shapes: Sphere, Cube, Cylinder, Pyramid
#ifndef SHAPE_H_
#define SHAPE_H_

#include "Shape.hh"

class Shape3D : public Shape{
public:
    //Shape3D(double x2, double y2, double z2) : Shape(Point(x2, y2, z2)) {};//Constructor 3D
    double getX(), getY(), getZ();//get position x,y,z
    void setX(double x1);//set position x
    void setY(double y1);//set position y
    void setZ(double z1);//set position z
    virtual double area() const = 0;//calculate the area of shapes
    virtual void volume()=0;//draw graphs or shapes



};

#endif // SHAPE_H_

