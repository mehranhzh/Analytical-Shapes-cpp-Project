//Author: Yu Hongshen
//this is the definition of a sphere class


#ifndef SPHERE_HH_
#define SPHERE_HH_

#include <cmath>
#include <vector>
#include <fstream>
#include "Point.hh"
#include "Triangle.hh"
using namespace std;

extern double PI;

class Sphere{
private:
    Point center_;
    double radius_;
public:
    //constructors
    Sphere(): radius_(0){}
    Sphere(const Point& center, double r): center_(center), radius_(r){}
    ~Sphere(){}

    //accessors
    const Point& center() const {return center_;}
    double radius() const {return radius_;}
    bool Contains(const Point& point) const {
        return point.DistanceFrom(center_) <= radius_;
    }

    //set some values
    void set_center(const Point& c){ center_ = c;}
    void set_radius(double r) {radius_ = r;}

    //this is the vector that will used to stored the Points
    //store the triangle points into a vector, and then store
    //all the triangles into another vector.
    std::vector<Point> Points;
    std::vector<Triangle> Triangles;

    //this is the triangulation of a sphere, but without test
    //a more universal way to triangulate is now developing
    void getSTLfile();

    double getVolume(){return PI*radius()*radius()*radius()*4/3;}
    double getArea(){}
    double getRadius(){return this->radius_;}
};

#endif // SPHERE_HH_
