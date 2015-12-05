//Author: Yu Hongshen
//this class is to create triangles, the vertices of triangles
//come from the triangulation of every shapes.

#ifndef TRIANGLE_HH_
#define TRIANGLE_HH_

class Triangle{
private:
    Point p0_, p1_, p2_;
public:
    Triangle(const Point& p1, const Point& p2, const Point& p3):
        p0_(p1), p1_(p1), p2_(p2){}
    ~Triangle();

    //Accessors
    const Point& p0() const {return p0_;}
    const Point& p1() const {return p1_;}
    const Point& p2() const {return p2_;}

    //Mutators
    void set_p0(const Point& p) { p0_ = p; }
    void set_p1(const Point& p) { p1_ = p; }
    void set_p2(const Point& p) { p2_ = p; }

    //Operations
    void operator=(const Triangle& other){
        p0_ = other.p0_;
        p1_ = other.p1_;
        p2_ = other.p2_;
    }
    bool operator<(const Triangle& other) const {
    return (p0_ != other.p0_ ? p0_ < other.p0_ :
           (p1_ != other.p1_ ? p1_ < other.p1_ :
           (p2_ < other.p2_)));
    }
    bool operator==(const Triangle& other) const {
        return (p0_ == other.p0_ && p1_ == other.p1_ && p2_ == other.p2_);
    }
    bool operator!=(const Triangle& other) const {
        return (p0_ != other.p0_ || p1_ != other.p1_ || p2_ != other.p2_);
    }
    Triangle operator-(const Point& offset) const {
        return Triangle(p0() - offset, p1() - offset, p2() - offset);
    }
    Triangle operator+(const Point& offset) const {
        return Triangle(p0() + offset, p1() + offset, p2() + offset);
    }

    Point Normal() const {
        Point cross = (p0_-p1_).Cross(p2_-p1_);
        return cross.Normalized();
    }

    double area() const {return (p1_-p0_).Cross(p2_-p0_).magnitude()/2;}

    Triangle Normalized() const {
    //p2->p1->p2 or p1->p2->p0 or p2->p0->p1
        if(p0() < p1()){
            return(p0() < p2() ? Triangle(p0(), p1(), p2()):
                   Triangle(p2(), p0(), p1()));
        }
        return(p1() < p2() ? Triangle(p1(), p2(), p0()):
                   Triangle(p2(), p0(), p1()));
    }

};

#endif // TRIANGLE_HH_
