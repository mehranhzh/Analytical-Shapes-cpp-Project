#ifndef SPHERE_HH_
#define SPHERE_HH_

#include "Point.hh"
#include <cmath>
#include <vector>

class Sphere{
private:
    Point center_;
    double radius_;
public:
    Sphere(): radius(0){}
    Sphere(const Point& center, double r): center_(center), radius_(r){}
    ~Sphere(){}

    const Point& center() const {return center_;}
    double radius() const {return radius;}
    bool Contains(const Point& point) const {
        return point.DistanceFrom(center_) <= radius_;
    }

    void set_center(const Point& c){ center_ = c;}
    void set_radius(double r) {radius_ = r;}

    std::vector<Point> Points;

    void Triangulate(center(), radius()) const {
        double a = center().x();
        double b = center().y();
        double c = center().z();
        double angle = PI / 180 * 10;
        int p2 = 360 / 20;
        int r2 = 180 / 20;
        for(int y = -r2; y < r2; y++){
            double cy = cos(y * angle);
            double cy1 = cos((y + 1) * angle);
            double sy = sin(y * angle);
            double sy1 = sin((y + 1) * angle);
            for(int i = -p2; i < p2; i++){
                double ci = cos(i * angle);
                double si = sin(i * angle);
                Points.push_back(Point(a+r * ci*cy, b+r*sy, c+r * si*cy));
                Points.push_back(Point(a+r * ci*cy1, b+r*sy1, c+r * si*cy1));
            }
        }
    }

};

#endif // SPHERE_HH_
