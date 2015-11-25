#include "Shape.hh"
#include "Cube.hh"

Cube(double a = 1, double b = 1, double c = 1):
    a(a), b(b), c(c){}
void Cube::getSTL(){

}
double Cube::getVolume(){return a*b*c;}
double Cube::geta(){return this->a;}
double Cube::getb(){return this->b;}
double Cube::getc(){return this->c;}
