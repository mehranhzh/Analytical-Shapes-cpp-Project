//Author: Yu Hongshen
//cylinder class

#ifndef CYLINDER_HH_
#define CYLINDER_HH_

#include <cmath>
#include <fstream>
#include "point.hh"
#include "Triangle.hh"
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
    const Point& center() const {return bottomCenter;}
    double r1() const {return r1_;}
    double r2() const {return r2_;}
    double h() const {return h_;}

    //set some values
    void set_center(const Point& c){ bottomCenter = c;}
    void set_r1(double r) {r1_ = r;}
    void set_r2(double r) {r2_ = r;}
    void set_h(double h) {h_ = h;}
    void set_bottomCenter(const Point& bp) {bottomCenter = bp;}

    //this is the vector that will used to stored the Points
    //store the triangle points into a vector, and then store
    //all the triangles into another vector.
    std::vector<Point> Points;
    std::vector<Triangle> Triangles;

    //This method includes triangulation of cylinder
    void getSTLfile(){
        double a = r1();
        double b = r2();
        double height = h()+center().z();
        int perDegree = 18;
        double theta = PI / 180 * perDegree;
        int triCount = 360 / perDegree;

        for(int i = 0; i < triCount; i++){
            Points.push_back(Point(a*cos(i*theta), a*sin(i*theta), center().z()));
            Points.push_back(Point(b*cos(i*theta), b*sin(i*theta), height));
        }

        for(int i = 0; i < 2*triCount; i+=2){
            if(i == 38){
                Triangles.push_back(Triangle(Points[i], Points[i+1], Points[0]));
                Triangles.push_back(Triangle(Points[0], Points[i+1], Points[1]));
            }
            else{
                Triangles.push_back(Triangle(Points[i], Points[i+1], Points[i+2]));
                Triangles.push_back(Triangle(Points[i+2], Points[i+1], Points[i+3]));
            }
        }

        ofstream file("Cylinder.stl");
        file << "solid" << ' ' << "Cylinder" << '\n';

        for(int i = 0; i < Triangles.size(); i++){
            file << "facet normal" << ' ' << Triangles[i].Normal() << '\n';
            file << "outer loop" << '\n';

            file << "vertex" << ' ' << Triangles[i].p0() << '\n';
            file << "vertex" << ' ' << Triangles[i].p1() << '\n';
            file << "vertex" << ' ' << Triangles[i].p2() << '\n';

            file << "endloop" << '\n';
            file << "endfacet" << '\n';
        }
        for(int i = 0; i < Points.size(); i+=2){
            file << "facet nomal" << ' ' << Point(0, 0, -1) << '\n';
            file << "outer loop" << '\n';

            file << "vertex" << ' ' << Points[i] << '\n';
            file << "vertex" << ' ' << Points[i+2] << '\n';
            file << "vertex" << ' ' << Points[Points.size()-i-2] << '\n';

            file << "endloop" << '\n';
            file << "endfacet" << '\n';

            file << "facet nomal" << ' ' << Point(0, 0, 1) << '\n';
            file << "outer loop" << '\n';

            file << "vertex" << ' ' << Points[i] << '\n';
            file << "vertex" << ' ' << Points[i+2] << '\n';
            file << "vertex" << ' ' << Points[Points.size()-i-2] << '\n';

            file << "endloop" << '\n';
            file << "endfacet" << '\n';
        }

        for(int i = 0; i < Points.size(); i+=2){
            file << "facet nomal" << ' ' << Point(0, 0, -1) << '\n';
            file << "outer loop" << '\n';

            file << "vertex" << ' ' << Point(0, 0, 0) << '\n';
            file << "vertex" << ' ' << Points[i+2] << '\n';
            file << "vertex" << ' ' << Points[i] << '\n';

            file << "endloop" << '\n';
            file << "endfacet" << '\n';

            file << "facet nomal" << ' ' << Point(0, 0, 1) << '\n';
            file << "outer loop" << '\n';

            if(i!=38){
                file << "vertex" << ' ' << Point(0, 0, height) << '\n';
                file << "vertex" << ' ' << Points[i+3] << '\n';
                file << "vertex" << ' ' << Points[i+1] << '\n';
            } else {
                file << "vertex" << ' ' << Point(0, 0, height) << '\n';
                file << "vertex" << ' ' << Points[i+1] << '\n';
                file << "vertex" << ' ' << Points[1] << '\n';
            }
            file << "endloop" << '\n';
            file << "endfacet" << '\n';
        }

        file << "endsolid" << ' ' << "Cylinder" << '\n';
    }

    double getVolume(){
        if(r1() > r2()){
            return h()*PI*((r1()-r2())*(r1()-r2())+r2()*r2());
        }
        return h()*PI*((r2()-r1()*(r2()-r1())+r1()*r1()));
    }
    double getArea(){}

};
#endif // CYLINDER_HH_1
