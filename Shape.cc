#include <iostream>
#include "Shape.hh"

Shape::Shape(double x1, double y1, double z1){}

double Shape::getX() { return x; }
double Shape::getY() { return y; }
double Shape::getZ() { return z; }

void Shape::setX(double x1){ x = x1; }
void Shape::setY(double y1){ y = y1; }
void Shape::setZ(double z1){ z = z1; }

//move to
void Shape::moveTo(double x1, double y1, double z1){
    setX(x1); setY(y1); setZ(z1);
}

void Shape::draw(){ }






