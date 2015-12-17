#ifndef CIRCLE_HH_
#define CIRCLE_HH_

#include "Shape2D.hh"
#include "Point.hh"

class Circle : public Shape2D{
private:
    double radius;
    Point p;
public:
    Circle(Point p, double r) : Shape2D(p) { radius = r; }
    double getR() const { return radius; }
    void setR(double r){ radius = r; }
    const Point& getCenter() const {return p;}
    double area() const { return PI*radius*radius; }
    void printShapeName() const { cout << "Circle: "; }
    friend ostream& operator <<(ostream& os, const Circle& c){
        return os << "Center= " << "(" << c.getCenter().x()<< "," << c.getCenter().y() << "); Radius= " << c.radius; // Center= (x,y); Radius=
    }
};

#endif // CIRCLE_H
