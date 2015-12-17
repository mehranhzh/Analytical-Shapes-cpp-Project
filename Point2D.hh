#ifndef POINT2D_HH_
#define POINT2D_HH_

#include <cmath>

class Point2D{
private:
    double x_, y_;
public:
    Point2D(): x_(0), y_(0){}
    Point2D(double x, double y): x_(x), y_(y){}

    //Operators.
    Point2D operator +(const Point2D& o) const {
        return Point2D(x_ + o.x_, y_ + o.y_);
    }
    Point2D operator -(const Point2D& o) const {
        return Point2D(x_ - o.x_, y_ - o.y_);
    }
    Point2D operator *(const Point2D& o) const {
        return Point2D(x_ * o.x_, y_ * o.y_);
    }
    Point2D operator /(const Point2D& o) const {
        return Point2D(x_ / o.x_, y_ / o.y_);
    }

    //Accessors
    double x() const {return x_;}
    double y() const {return y_;}
    double magnitude() const {return sqrt(magnitude2());}
    double magnitude2() const {return x_ * x_ + y_ * y_;}
    Point2D Normalized() const {
        return *this / magnitude();
    }
    double z_cross(const Point2D& o) const {
        return (o == *this ? 0 : x_ * o.y_ - y_ * 0.x_);
    }

    //Mutators
    void set_x(double x) {x_ = x;}
    void set_y(double y) {y_ = y;}
    void Normalize() {*this = Normalized();}

};
#endif // POINT2D_HH_
