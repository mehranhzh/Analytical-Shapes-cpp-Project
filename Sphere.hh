#ifndef SPHERE_HH_
#define SPHERE_HH_

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

};

#endif // SPHERE_HH_
