//Author: Yu Hongshen
//cubic class

#ifndef CUBE_HH_
#define CUBE_HH_

#include <vector>
#include <fstream>
#include "Point.hh"
#include "Triangle.hh"
#include "GeometryTransform.hh"
using namespace std;

extern double PI;

class Cube{
private:
    Point Position_;
    double a_, b_, c_; //the length of every side
public:
    Cube(Point p = Point(0,0,0), double a = 1, double b = 1, double c = 1):
        Position_(p), a_(a), b_(b), c_(c){}

    //accessors
    double a() const {return a_;}
    double b() const {return b_;}
    double c() const {return c_;}
    const Point& Position() const {return Position_;}

    //set some values
    void set_a(double a){a_ = a;}
    void set_b(double b){b_ = b;}
    void set_c(double c){c_ = c;}
    void set_Position(const Point& point) {Position_ = point;}

    std::vector<Point> Points;
    std::vector<Triangle> Triangles;

    void triangulate();

    void getSTLfile();

    void Rotate(const Point&, double);

    double getVolume(){
        return a()*b()*c();
    }
    double getArea(){
        return 2*a()*b() + 2*a()*c() + 2*b()*c();
    }
};

#endif // CUBE_HH_
