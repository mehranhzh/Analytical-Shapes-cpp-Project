//Author:Mehran Hosseinzadeh
//Shape class will based class of other shapes
#ifndef SHAPE_HH_
#define SHAPE_HH_

#include <iostream>
#include "Point.hh"
using namespace std;


class Shape {//abstract class shape
public:
    Shape(){}//Constructor Shape
    //virtual void moveTo(double x1, double y1, double z1);//pure virtual function that move position to new position
    //virtual bool isInside(double x1, double y1, double z1); //check if point is inside of Shape or not
    //virtual double area() const;//calculate the area of shapes
    //virtual double perimeter() const;//calculate the perimeter of shapes
    //virtual void draw();//draw graphs or shapes
    //virtual void volume();//draw graphs or shapes
    //virtual void printShapeName() const;
    //virtual void print() const;
    virtual ~Shape(){};//Destructor

};

#endif // SHAPE_HH_
