#ifndef SPHERE_HH_
#define SPHERE_HH_

class Sphere{
private:
    double r;
public:
    Sphere(double r = 1);
    void getSTL();
    double getVolume();
    double getr();
};
#endif // SPHERE_HH_
