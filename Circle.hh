//Author: Mehran Hosseinzadeh
//Help received from partner Yu Hongshen

#ifndef CIRCLE_HH_
#define CIRCLE_HH_

#include "Shape2D.hh"
#include "Point.hh"
#include "Triangle.hh"
#include <vector>
#include <fstream>

extern double PI;

class Circle: public Shape2D {

private:
    double radius;
    Point p;

public:
    Circle(const Point& p, double r) : p(p) { radius = r; }

    double getR() const { return radius; }

    void setR(double r){ radius = r; }

    const Point& center() const {return p;}

    double area() const { return PI*radius*radius; }

    void printShapeName() const { cout << "Circle: "; }

    friend ostream& operator <<(ostream& os, const Circle& c){
        return os << "Center= " << "(" << c.center().x()<< "," << c.center().y() << "); Radius= " << c.radius; // Center= (x,y); Radius=
    }

std::vector<Point> Points;
//std::vector<Triangle> Triangles;

void getPoints(){

    double r = getR();
    int perDegree = 18;
    double theta = PI / 180 * perDegree;
    int triCount = 360 / perDegree;

    for(int i = 0; i < triCount; i++)
        Points.push_back(Point(r*cos(i*theta)+center().x(), r*sin(i*theta)+center().y(), 0));

    Points.push_back(center());

}

void getSTLfile() {

    ofstream file("Circle.stl");
    file << "solid" << ' ' << "Circle" << '\n';

    //calculate upper and lower facets
    for(int i = 0; i < Points.size(); i++){

        if(i != 19){
            file << "facet nomal" << ' ' << Triangle(Points[20], Points[i+1], Points[i]).Normal() << '\n';
            file << "outer loop" << '\n';

            file << "vertex" << ' ' << Points[20] << '\n';
            file << "vertex" << ' ' << Points[i+1] << '\n';
            file << "vertex" << ' ' << Points[i] << '\n';
        } else {
            file << "facet nomal" << ' ' << Triangle(Points[20], Points[0], Points[i]).Normal() << '\n';
            file << "outer loop" << '\n';

            file << "vertex" << ' ' << Points[20] << '\n';
            file << "vertex" << ' ' << Points[0] << '\n';
            file << "vertex" << ' ' << Points[i] << '\n';
        }

        file << "endloop" << '\n';
        file << "endfacet" << '\n';

    file << "endsolid" << ' ' << "Circle" << '\n';
    }
}

};

#endif // CIRCLE_H
