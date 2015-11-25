
#include "Sphere.hh"

Sphere::Sphere(double r = 1):
    r(r){}
void Sphere::getSTL(){

}
void Sphere::getVolume(){return PI*r*r*r*4/3;}
double Sphere(){return this->r;}
