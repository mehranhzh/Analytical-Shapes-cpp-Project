#include "Sphere.hh"

void Sphere::triangulate() {
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

        //get the vector of Points
        for(int i = 0; i < triCountLongi; i++){
            for(int j = 0; j <= triCountLati; j++)
                Points.push_back(Point(a+r*sin(j*thetaLati)*cos(i*thetaLongi),
                                       b+r*sin(j*thetaLati)*sin(i*thetaLongi),
                                       c+r*cos(j*thetaLati)));
        }

        //get the vector of Triangles
        for(int i = 0; i < 187; i++){
            if(Points[i] != Point(center().x(), center().y(), center().z()-r)){
                Triangles.push_back(Triangle(Points[i], Points[i+1], Points[i+12]));
                Triangles.push_back(Triangle(Points[i], Points[i+12], Points[i+11]));
            } else
                continue;
        }
        for(int i = 187, j = 0; i < Points.size(), j < 10; i++, j++){
            if(Points[i] != Point(center().x(), center().y(), center().z()-r)){
                Triangles.push_back(Triangle(Points[i], Points[i+1], Points[j+1]));
                Triangles.push_back(Triangle(Points[i], Points[j+1], Points[j]));
            } else
                continue;
        }
}

void Sphere::getSTLfile() {
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
