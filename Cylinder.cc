#include "Cylinder.hh"


void Cylinder::getPoints(){

    double a = r1();
    double b = r2();
    double height = h()+center().z();
    int perDegree = 18;
    double theta = PI / 180 * perDegree;
    int triCount = 360 / perDegree;

    for(int i = 0; i < triCount; i++){
        Points.push_back(Point(a*cos(i*theta)+center().x(), a*sin(i*theta)+center().y(), center().z()));
        Points.push_back(Point(b*cos(i*theta)+center().x(), b*sin(i*theta)+center().y(), height));
    }
    Points.push_back(center()); //Points[40]
    Points.push_back(Point(center().x(), center().y(), height)); //Points[41]

}

void Cylinder::triangulate() {

    int perDegree = 18;
    int triCount = 360 / perDegree;
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

}

void Cylinder::getSTLfile() {

    double height = h()+center().z();
    ofstream file("Cylinder.stl");
    file << "solid" << ' ' << "Cylinder" << '\n';

    //calculate surrounding facts
    for(int i = 0; i < Triangles.size(); i++){
        file << "facet normal" << ' ' << Triangles[i].Normal() << '\n';
        file << "outer loop" << '\n';

        file << "vertex" << ' ' << Triangles[i].p0() << '\n';
        file << "vertex" << ' ' << Triangles[i].p1() << '\n';
        file << "vertex" << ' ' << Triangles[i].p2() << '\n';

        file << "endloop" << '\n';
        file << "endfacet" << '\n';
    }

    //calculate upper and lower facets
    for(int i = 0; i < Points.size(); i+=2){

        if(i != 38){
            file << "facet nomal" << ' ' << Triangle(Points[40], Points[i+2], Points[i]).Normal() << '\n';
            file << "outer loop" << '\n';

            file << "vertex" << ' ' << Points[40] << '\n';
            file << "vertex" << ' ' << Points[i+2] << '\n';
            file << "vertex" << ' ' << Points[i] << '\n';
        } else {
            file << "facet nomal" << ' ' << Triangle(Points[40], Points[i+2], Points[0]).Normal() << '\n';
            file << "outer loop" << '\n';

            file << "vertex" << ' ' << Points[40] << '\n';
            file << "vertex" << ' ' << Points[38] << '\n';
            file << "vertex" << ' ' << Points[0] << '\n';
        }

        file << "endloop" << '\n';
        file << "endfacet" << '\n';

        if(i != 38){
            file << "facet nomal" << ' ' << Triangle(Points[41],
                                                     Points[i+3],
                                                     Points[i+1]).Normal() << '\n';
            file << "outer loop" << '\n';

            file << "vertex" << ' ' << Points[41] << '\n';
            file << "vertex" << ' ' << Points[i+3] << '\n';
            file << "vertex" << ' ' << Points[i+1] << '\n';
        } else {
            file << "facet nomal" << ' ' << Triangle(Points[41],
                                                     Points[i+1],
                                                     Points[1]).Normal() << '\n';
            file << "outer loop" << '\n';

            file << "vertex" << ' ' << Points[41] << '\n';
            file << "vertex" << ' ' << Points[i+1] << '\n';
            file << "vertex" << ' ' << Points[1] << '\n';
        }

        file << "endloop" << '\n';
        file << "endfacet" << '\n';
    }

    file << "endsolid" << ' ' << "Cylinder" << '\n';
}

void Cylinder::Rotate(const Point& p, double degree) {

    double radian = PI / 180 * degree;
    RotateTransform R(p, radian);
    for(int i = 0; i < Points.size(); i++)
        Points[i] = R.Transform(Points[i]);

}
