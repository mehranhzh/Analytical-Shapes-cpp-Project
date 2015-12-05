//Author: Yu Hongshen
//cylinder class

#ifndef CYLINDER_HH_
#define CYLINDER_HH_

#include <cmath>
#include <fstream>
#include "point.hh"
using namespace std;

extern double PI;

class Cylinder{
private:
    double h_, r1_, r2_;   //the height and two radii.
    Point bottomCenter;    //we use the bottom center to position a cylinder
public:
    Cylinder():
        h_(1), r1_(1), r2_(1), bottomCenter(Point(0,0,0)){}
    Cylinder(double h, double r1, double r2, Point bp):
        h_(h), r1_(r1), r2_(r2), bottomCenter(bp){}

    //accessors
    Point center() const {return bottomCenter;}
    double r1() const {return r1_;}
    double r2() const {return r2_;}
    double h() const {return h_;}

    //set some values
    void set_center(const Point& c){ bottomCenter = c;}
    void set_r1(double r) {r1_ = r;}
    void set_r2(double r) {r2_ = r;}
    void set_h(double h) {h_ = h;}
    void set_bottomCenter(const Point& bp) {bottomCenter = bp;}

    std::vector<Point> Points;
    void Triangulate(){
        double a = r1();
        double b = r2();
        double height = h();
        double theta = PI / 180 * 20;
        for(int i = 0; i < 20; i++){
            Points.push_back(Point(a*cos(i*theta), a*sin(i*theta), 0));
            Points.push_back(Point(b*cos(i*theta), b*sin(i*theta), height));
        }
    }

    double getVolume(){
        if(r1() > r2()){
            return h()*PI*((r1()-r2())*(r1()-r2())+r2()*r2());
        }
        return h()*PI*((r2()-r1()*(r2()-r1())+r1()*r1()));
    }

};
#endif // CYLINDER_HH_1
