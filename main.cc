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

    //Cylinder c(10, 5, 5, Point(10, 10, 10));
    //c.triangulate();
    //c.getSTLfile();
    //Sphere s(Point(10, 10 ,5), 10);
    //s.triangulate();
    //s.getSTLfile();
    Cube cube(Point(10, 5, 5), 5, 5, 5);
    cube.triangulate();
    cube.Rotate(Point(1,1,1), 30);
    cube.getSTLfile();


}
