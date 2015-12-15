//Author:Mehran
//Shape class will based class of other shapes
#ifndef SHAPE_HH_
#define SHAPE_HH_

#include <iostream>
#include "Point.hh"


class Shape {//abstract class shape
public:
    Shape(double x1, double y1, double z1);//Constructor Shape
    virtual void moveTo(double x1, double y1, double z1)=0;//pure virtual function that move position to new position
    virtual bool isInside(double x1, double y1, double z1) = 0; //check if point is inside of Shape or not
    virtual double area() const = 0;//calculate the area of shapes
    virtual double perimeter() const = 0;//calculate the perimeter of shapes
    virtual void draw()=0;//draw graphs or shapes
    virtual void volume()=0;//draw graphs or shapes
    virtual void printShapeName() const = 0;
    virtual void print() const = 0;
    virtual ~Shape(){};//Destructor

};

#endif // SHAPE_HH_
