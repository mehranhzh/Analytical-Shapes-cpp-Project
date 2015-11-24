#ifndef CYLINDER_HH_
#define CYLINDER_HH_

#include <cmath>
#include <fstream>

static const double PI = 3.1415926;

class Cylinder{
private:
    double h, r1, r2;
public:
    Cylinder(double h = 1, double r1 = 1, double r2 = 1);
    void getSTL();
    double getVolume();
    double getr1();
    double geth();
    double getr2();
};
#endif // CYLINDER_HH_1
