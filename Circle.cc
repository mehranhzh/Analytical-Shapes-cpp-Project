#include "Shape.hh"


Circle::Circle(double x1, double y1, double r1) : Shape(x1, y1){
    setR(r1);
}

double Circle::getR(){ return r; }
void Circle::setR(double r1){ r = r1; }

void Circle::draw(){

}
