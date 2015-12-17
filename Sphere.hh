//Author: Yu Hongshen
//this is the definition of a sphere class


#ifndef SPHERE_HH_
#define SPHERE_HH_

#include <cmath>
#include <vector>
#include "Point.hh"
#include "Triangle.hh"

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
    void getSTLfile() {
        double a = center().x();
        double b = center().y();
        double c = center().z();
        double r = radius();
        int longitudeDegree = 20;
        int latitudeDegree = 18;
        double thetaLongi = PI / 180 * longitudeDegree;
        double thetaLati = PI / 180 * latitudeDegree;
        int triCountLongi = 360 / longitudeDegree;
        int triCountLati = 180 / latitudeDegree;

        for(int i = 0; i < triCountLongi; i++){
            for(int j = 0; j <= triCountLati; j++)
                Points.push_back(Point(a+r*sin(j*thetaLati)*cos(i*thetaLongi),
                                       b+r*sin(j*thetaLati)*sin(i*thetaLongi),
                                       c+r*cos(j*thetaLati)));
        }
        for(int i = 0; i < Points.size(); i++){
            if(i < 188){
                Triangles.push_back(Triangle(Points[i], Points[i+1], Points[i+12]));
                Triangles.push_back(Triangle(Points[i], Points[i+12], Points[i+11]));
            }
            else{
                for(int j = 0; j <= 10; j++){
                    Triangles.push_back(Triangle(Points[i], Points[i+1], Points[j+1]));
                    Triangles.push_back(Triangle(Points[i], Points[j+1], Points[j]));
                }
            }
        }

        ofstream file("Sphere.stl");
        file << "solid" << ' ' << "Sphere" << '\n';

        for(int i = 0; i < Triangles.size(); i++){
            file << "facet normal" << ' ' << Triangles[i].Normal() << '\n';
            file << "outer loop" << '\n';

            file << "vertex" << ' ' << Triangles[i].p0() << '\n';
            file << "vertex" << ' ' << Triangles[i].p1() << '\n';
            file << "vertex" << ' ' << Triangles[i].p2() << '\n';

            file << "endloop" << '\n';
            file << "endfacet" << '\n';
        }

        file << "endsolid" << ' ' << "Sphere" << '\n';
    }
    //set a variable to store the size of vector Points
    int triCount = Points.size();

    double getVolume(){return PI*radius()*radius()*radius()*4/3;}
    double getArea(){}
    double getRadius(){return this->radius_;}
};

#endif // SPHERE_HH_
