#ifndef TRIANGLE_HH_
#define TRIANGLE_HH_

#include "Edge.hh"

class Triangle{
private:
    Point p0_, p1_, p2_;
public:
    Triangle(const Point& p1, const Point& p2, const Point& p3):
        p0_(p1), p1_(p1), p2_(p2){}
    ~Triangle();

    const Point& p0() const {return p0_;}
    const Point& p1() const {return p1_;}
    const Point& p2() const {return p2_;}

    Point Normal() const {
        Point cross = (p0_-p1_).Cross(p2_-p1_);
        return cross.abs();
    }

};

#endif // TRIANGLE_HH_
