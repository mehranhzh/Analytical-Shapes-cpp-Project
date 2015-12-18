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
    Circle(const Point& p, double r) : p(p) { radius = r; }//Constructor

    double getR() const { return radius; }//Getting Radius

    void setR(double r){ radius = r; }//Setting Radius

    const Point& center() const {return p;}//Returning center point

    double area() const { return PI*radius*radius; }//Returning Circle area

    void printShapeName() const { cout << "Circle: "; }//Printing Shape Name

    friend ostream& operator <<(ostream& os, const Circle& c){// Operator overloading
        return os << "Center= " << "(" << c.center().x()<< "," << c.center().y() << "); Radius= " << c.radius; // Center= (x,y); Radius=
    }

std::vector<Point> Points;//Defining points as vector

void getPoints(){

    double r = getR();
    int perDegree = 18;//Deviding a circle to 20 pieces
    double theta = PI / 180 * perDegree;//converting theta to radian
    int triCount = 360 / perDegree;//calculate degree for each part

    for(int i = 0; i < triCount; i++)
        Points.push_back(Point(r*cos(i*theta)+center().x(), r*sin(i*theta)+center().y(), 0));//push points regarding formula to get x,y

    Points.push_back(center());

}

void getSTLfile() {

    ofstream file("Circle.stl");//write STL file
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
