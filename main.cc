//Author:Mehran, Hongshen
#include "Point.hh"
#include "Cube.cc"
#include "Cylinder.cc"
#include "Point.hh"
#include "Cube.hh"
#include "Sphere.cc"
#include "GeometryTransform.hh"
#include "Triangle.hh"
#include <iostream>

double PI = 3.14159265358979323846;

int main(){

    Cylinder c(10, 5, 5, Point(10, 10, 10));
    Sphere s(Point(10, 10 ,5), 10);
    Cube cube(Point(1, 2, 3), 5, 5, 5);
    c.getSTLfile();
    s.getSTLfile();
    cube.getSTLfile();

}
