#include "Shape.hh"

using namespace std;

Shape::Shape(double nx, double ny, double nz){
    moveTo(nx, ny, nz);
}

//move
void Shape::moveTo(double nx, double ny, double nz){
    setX(nx);
    setY(ny);
    setZ(nz);
}






