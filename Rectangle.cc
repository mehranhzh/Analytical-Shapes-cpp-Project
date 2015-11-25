#include "Shape.hh"
#include "Rectangle.hh"

 Rectangle::Rectangle(double x1, double y1, double z1, double w1, double h1) : Shape(x1, y1, z1){
    setW(w1);
    setH(h1);
 }

double Rectangle::getW(){ return w; }
double Rectangle::getH()){ return h; }
void Rectangle::setW(double w1){ w = w1; }
void Rectangle::setH(double h1){ h = h1; }

void Rectangle::draw(){

}




