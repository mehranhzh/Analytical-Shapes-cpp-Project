#ifndef RECTANGLE_HH_
#define RECTANGLE_HH_

#include "Point.hh"

class Rectangle: public Point{
private:
    double width, height;
public:
    Rectangle(double x, double y, double w, double h) : Point(x, y, 0) { width = w; height= h; };
    double getW() const { return width; };
    double getH() const { return height; };
    void setW(double w){ width = w; };
    void setH(double h){ height = h; };
    double area() const { return width*height; }
    void printShapeName() const { cout << "Rectangle: "; }
    friend ostream& operator <<(ostream& os, const Rectangle& r){
        return os << "Center= " << "(" << r.x()<< "," << r.y() << "); Width= " << r.width << " Height= " << r.height; // Center= (x,y); Radius=
    }

};

#endif // RECTANGLE_HH_
