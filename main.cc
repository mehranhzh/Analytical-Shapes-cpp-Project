#include "Point.hh"
#include "Shape.hh"
#include "Circle.hh"
#include "Rectangle.hh"
#include "Square.hh"
#include "Cylinder2.hh"
#include "Cube.hh"
//#include "Cylinder.hh"
#include "Sphere.hh"
//#include "stlWriter.hh"
#include "GeometryTransform.hh"
#include "Triangle.hh"
#include <iostream>

//double PI = 3.14159265358979323846;

int main(int argc, char** argv){
#if 0
    Cylinder c(10, 5, 5, Point(0,0,0));

    c.getSTLfile();
    //Triangle test(Point(1, 0, 0), Point(0, 0, 0), Point(0, 1, 0));
    //std::cout << test.Normal();
#endif
  Point point(7, 11, 2);		    // create a point
  Circle circle(22, 8, 3.5);    	// create a circle
  Rectangle rectangle(2, 8, 4, 3);  // create a rectangle
  Square square(5, 6, 10);          // create a square
  Cylinder cylinder(3, 9, 4, 2);    // create a cylinder

  point.printShapeName();
  cout << point << endl;

  circle.printShapeName();
  cout << circle;
  cout << "; Area= " << circle.area() << endl;

  rectangle.printShapeName();
  cout << rectangle;
  cout << "; Area= " << rectangle.area() << endl;

  square.printShapeName();
  cout << square;
  cout << "; Area= " << square.area() << endl;

  cylinder.printShapeName();
  cout << cylinder;
  cout << "; Area= " << cylinder.area() << endl;
  
    return 0;
}
