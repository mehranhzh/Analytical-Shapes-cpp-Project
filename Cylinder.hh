#ifndef CYLINDER_HH_
#define CYLINDER_HH_

#include <cmath>
#include <fstream>
#include <iostream>
#include "point.hh"
using namespace std;

class Cylinder{
private:
    double h, r1, r2;
public:
    Cylinder(double h = 1, double r1 = 1, double r2 = 1);

};
#endif // CYLINDER_HH_1
