#ifndef Cylinder_HH_
#define Cylinder_HH_

#include "Circle.hh"

class Cylinder : public Circle{

private:
    double height, radius;

public:
    Cylinder(double x, double y, double r, double h) : Circle(x, y, r) { height = h > 0 ? h : 0; };
    //double getR() const { return radius; };
    void setH(double h){ height = h > 0 ? h : 0; }
    double area() const { return 2*Circle::area()+2*3.14*Circle::getR()*height; }
    double volume() const { return Circle::area()*height; }
    void printShapeName() const { cout << "Cylinder: "; }
    friend ostream& operator <<(ostream& os, const Cylinder& c){
        return os << "Center= " << "(" << c.x()<< "," << c.y() << "); Height= "
        << c.height << "; Radius= " << c.Circle::getR(); ; // Center= (x,y); Height= ;Radius=
    }



};

#endif // Cylinder_H
