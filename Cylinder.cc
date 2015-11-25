#include "Shape.hh"
#include "Cylinder.hh"

Cylinder::Cylinder(double h = 1, double r1 = 0, double r2 = 1):
    r1(r1), h(h), r2(r2){}

void Cylinder::getSTL(){
    ofstream file("Cylinder.stl");
    file << "solid Cylinder" << '\n';

    for(int i = 1; i <= 32; i++){
        file << "facet normal" << ' ' << '\n';
        file << "outer loop" << '\n';
        file << "endloop" << '\n';
        file << "endfacet" << '\n';
    }
    for(int i = 1; i <= 28; i++){
        file << "facet normal" << ' ' << '\n';
        file << "outer loop" << '\n';
        file << "endloop" << '\n';
        file << "endfacet" << '\n';
    }
    file << "endsolid Cylinder" << '\n';
}
double Cylinder::getVolume(){
    if(r1 > r2){
        return h*PI*((r1-r2)*(r1-r2)+r2*r2);
    }
    return h*PI*((r2-r1*(r2-r1)+r1*r1);
}
double Cylinder::getr1(){return this->r1;}
double Cylinder::geth(){return this->h;}
double Cylinder::getr2(){return this->r2;}
