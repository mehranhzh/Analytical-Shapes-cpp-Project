//Shape2D class is derived class of Shape and will show 2D shapes:Circle, Rectangle, Triangle, Square
#ifndef SHAPE_H_
#define SHAPE_H_

#include "Shape.hh"

class Shape2D : public Shape{
public:
    Shape2D(Point p) : Shape(p) {}//Constructor 2D with z_=0
    double getX(), getY();//get position x,y,z
    void setX(double x1);//set position x
    void setY(double y1);//set position y
    virtual double area() const = 0;//calculate the area of shapes
    virtual double perimeter() const = 0;//calculate the perimeter of shapes





};

#endif // SHAPE_H_
