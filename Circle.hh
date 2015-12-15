#ifndef CIRCLE_HH_
#define CIRCLE_HH_

#include "Point.hh"

class Circle : public Point{
private:
    double radius;
public:
    Circle(double x, double y, double r) : Point(x, y, 0) { radius = r; };
    double getR() const { return radius; };
    void setR(double r){ radius = r; };
    double area() const { return PI*radius*radius; }
    void printShapeName() const { cout << "Circle: "; }
    friend ostream& operator <<(ostream& os, const Circle& c){
        return os << "Center= " << "(" << c.x()<< "," << c.y() << "); Radius= " << c.radius; // Center= (x,y); Radius=
    }



};

#endif // CIRCLE_H
