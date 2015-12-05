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

    const Point& p0() const {return p0_;}
    const Point& p1() const {return p1_;}
    const Point& p2() const {return p2_;}

    Point Normal() const {
        Point cross = (p0_-p1_).Cross(p2_-p1_);
        return cross.Normalized();
    }

    double area() const {return (p1_-p0_).Cross(p2_-p0_).magnitude()/2;}

    //This function is to make sure the orientation of each triangles.
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

