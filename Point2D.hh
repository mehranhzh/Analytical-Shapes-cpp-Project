//This is the Point class for every shapes.

#ifndef POINT_HH_
#define POINT_HH_

#include <cmath>

class Point{
private:
    double x_, y_, z_;

public:
    //constructor
    Point(): x_(0), y_(0){}
    Point(double x, double y): x_(x), y_(y){}
    ~Point(){}

    //accessors
    double Getx() const {return x_;}
    double Gety() const {return y_;}

    //set values
    void set_x(double val){x_ = val;}
    void set_y(double val){y_ = val;}
    void setxyz(double x, double y){x_ = x; y_ = y;}

    //some member functions
    void add(const Point& other){
        x_ += other.x_;
        y_ += other.y_;
    }
    void sub(const Point& other){
        x_ -= other.x_;
        y_ -= other.y_;
    }

    //scale
    void scale_x(double s){x_ *= s;}
    void scale_y(double s){y_ *= s;}
    void scale(double s){scale_x(s); scale_y(s);}

    //rotate function, derived from rotation transform matrix in computer graphics
    void RotateAround(const Point& vec, double angle_radians){
        Point u = vec.Normalized();
        double c = cos(angle_radians);
        double i_c = 1 - c;
        double s = sin(angle_radians);
        double u_xy = u.x() * u.y();
        double u_xx = u.x() * u.x(), u_yy = u.y() * u.y();
        *this = Point((c + u_xx * i_c) * x_ + (u_xy * i_c) * y_ ,
                      (u_xy * i_c ) * x_ + (c + u_yy * i_c) * y_ ,
                      (u_xz * i_c - u.y() * s) * x_ + (u.x() * s) * y_);
    }
    Point RotateAround(const Point& vec, double angle_radians) const{
        Point copyPoint = *this;
        copyPoint.RotateAround(vec, angle_radians);
        return copyPoint;
    }

    //some operator overloading
    Point& operator =(const Point& other){
        x_ = other.x_; y_ = other.y_;
        return *this;
    }
    Point operator +(const Point& other) const {
        return Point(x()+other.x(), y()+other.y();
    }
    Point operator -(const Point& other) const {
        return Point(x()-other.x(), y()-other.y());
    }
    Point operator *(double s) const {
        return Point(x()*s, y()*s);
    }
    Point operator /(double s) const {
        return Point(x()/s, y()/s);
    }

    //dot product
    double operator *(const Point& other) const {
        return x()*other.x() + y()*other.y();
    }

    //cross product
    Point Cross(const Point& other) const {
        return Point(x()*other.y() - other.x()*y());
    }


    bool operator ==(const Point& other) const{
        return x() == other.x() && y() == other.y();
    }
    bool operator !=(const Point& other) const {
        return x() != other.x() || y() != other.y();
    }

    double DistanceFrom(const Point& other) const {
        return sqrt(x()*other.x() + y()*other.y());
    }
    double magnitude() const {
        return sqrt(x()*x() + y()*y());
    }
    void Normalize(){
        double m = magnitude();
        if(m != 0){
            *this = *this / m;
        }
    }
    Point Normalized() const {
        Point copy_ = *this;
        copy_.Normalize();
        return copy_;
    }
};

#endif // POINT_HH_
