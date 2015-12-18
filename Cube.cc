#include "Cube.hh"

void Cube::getPoints() {

    Points.push_back(Point(a()+Position().x(), Position().y(), Position().z()));
    Points.push_back(Point(a()+Position().x(), b()+Position().y(), Position().z()));
    Points.push_back(Point(Position().x(), b()+Position().y(), Position().z()));
    Points.push_back(Point(Position().x(), Position().y(), Position().z()));
    Points.push_back(Point(a()+Position().x(), Position().y(), c()+Position().z()));
    Points.push_back(Point(a()+Position().x(), b()+Position().y(), c()+Position().z()));
    Points.push_back(Point(Position().x(), b()+Position().y(), c()+Position().z()));
    Points.push_back(Point(Position().x(), Position().y(), c()+Position().z()));

}

void Cube::triangulate() {

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

}

void Cube::getSTLfile() {

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

}

void Cube::Rotate(const Point& p, double degree){

    double radian = PI / 180 * degree;
    RotateTransform R(p, radian);
    for(int i = 0; i < Points.size(); i++)
        Points[i] = R.Transform(Points[i]);

}
