//Author: Yu Hongshen
//cubic class

#ifndef CUBE_HH_
#define CUBE_HH_

#include <vector>
#include <fstream>
#include "Point.hh"
#include "Triangle.hh"

using namespace std;

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

    void getSTLfile(){
        Points.push_back(Point(a()+Position().x(), Position().y(), Position().z()));
        Points.push_back(Point(a()+Position().x(), b()+Position().y(), Position().z()));
        Points.push_back(Point(Position().x(), b()+Position().y(), Position().z()));
        Points.push_back(Point(Position().x(), Position().y(), Position().z()));
        Points.push_back(Point(a()+Position().x(), Position().y(), c()+Position().z()));
        Points.push_back(Point(a()+Position().x(), b()+Position().y(), c()+Position().z()));
        Points.push_back(Point(Position().x(), b()+Position().y(), c()+Position().z()));
        Points.push_back(Point(Position().x(), Position().y(), c()+Position().z()));

        Triangles.push_back(Triangle(Points[0], Points[1], Points[2]));
        Triangles.push_back(Triangle(Points[0], Points[2], Points[3]));
        Triangles.push_back(Triangle(Points[1], Points[4], Points[0]));
        Triangles.push_back(Triangle(Points[1], Points[5], Points[4]));
        Triangles.push_back(Triangle(Points[2], Points[5], Points[1]));
        Triangles.push_back(Triangle(Points[2], Points[6], Points[5]));
        Triangles.push_back(Triangle(Points[3], Points[6], Points[7]));
        Triangles.push_back(Triangle(Points[3], Points[2], Points[6]));
        Triangles.push_back(Triangle(Points[4], Points[3], Points[0]));
        Triangles.push_back(Triangle(Points[4], Points[7], Points[3]));
        Triangles.push_back(Triangle(Points[5], Points[7], Points[4]));
        Triangles.push_back(Triangle(Points[5], Points[6], Points[7]));

        ofstream file("Cube.stl");
        file << "solid" << ' ' << "Cube" << '\n';

        for(int i = 0; i < 12; i++){
            file << "facet normal" << ' ' << Triangles[i].Normal() << '\n';
            file << "outer loop" << '\n';

            file << "vertex" << ' ' << Triangles[i].p0() << '\n';
            file << "vertex" << ' ' << Triangles[i].p1() << '\n';
            file << "vertex" << ' ' << Triangles[i].p2() << '\n';

            file << "endloop" << '\n';
            file << "endfacet" << '\n';
        }

        file << "endsolid" << ' ' << "Cube" << '\n';
    }

    double getVolume(){
        return a()*b()*c();
    }
    double getArea(){
        return 2*a()*b() + 2*a()*c() + 2*b()*c();
    }
};

#endif // CUBE_HH_
