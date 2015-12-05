//Author: Yu Hongshen
//a class that writes .stl files,
//STL files need information of coordinates of triangle vertices and its normal.

#ifndef STLWRITER_HH_
#define STLWRITER_HH_

//#include "TriangleMesh.hh"

#include <iostream>
#include <fstream>
#include <vector>
#include "Cylinder.hh"
#include "Cube.hh"
#include "Sphere.hh"
using namespace std;

class stlWriter{
private:
    vector<Point> Point_;
public:
    stlWriter(vector<Point> p): Point_(p){}

};
#endif // STLWRITER_HH_
