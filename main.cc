#include "Point.hh"
//#include "Point2D.hh"
#include "Cube.hh"
#include "Cylinder.hh"
#include "Sphere.hh"
#include "stlWriter.hh"
#include "GeometryTransform.hh"
#include "Triangle.hh"
#include <iostream>

double PI = 3.14159265358979323846;

int main(int argc, char** argv){

    Cylinder c(10, 5, 5, Point(0,0,0));

    c.getSTLfile();
    //Triangle test(Point(1, 0, 0), Point(0, 0, 0), Point(0, 1, 0));
    //std::cout << test.Normal();

    return 0;
}
