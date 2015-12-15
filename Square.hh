#ifndef Square_HH_
#define Square_HH_

#include "Point.hh"

class Square: public Point{
private:
    double width;
public:
    Square(double x, double y, double w) : Point(x, y, 0) { width = w; };
    double getW() const { return width; };
    void setW(double w){ width = w; };
    double area() const { return width*width; }
    void printShapeName() const { cout << "Square: "; }
    friend ostream& operator <<(ostream& os, const Square& s){
        return os << "Center= " << "(" << s.x()<< "," << s.y() << "); Width= " << s.width ; // Center= (x,y); Radius=
    }

};

#endif // Square_HH_
