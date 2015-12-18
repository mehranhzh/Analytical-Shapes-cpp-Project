//Author: Yu Hongshen, Mehran Hosseinzadeh
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

    //get a cylinder rotated based on vector(0,1,0), 75 degrees
    Cylinder c(10, 5, 5, Point(10, 10, 10));
    c.getPoints();
    c.Rotate(Point(0,1,0), 75);
    c.triangulate();
    c.getSTLfile();

    //Sphere s(Point(10, 10 ,5), 10);
    //s.triangulate();
    //s.getSTLfile();

    //get a cube rotates based on vector(1,0,0), 30 degrees
    Cube cube(Point(10, 5, 5), 5, 5, 5);
    cube.getPoints();
    cube.Rotate(Point(1,0,0), 30);
    cube.triangulate();
    cube.getSTLfile();

}
