#ifndef POINT_HH_
#define POINT_HH_

#include <cmath>

class Point{
private:
    double x_, y_, z_;

public:
    Point(): x_(0), y_(0), z_(0){}
    Point(double x, double y, double z): x_(x), y_(y), z_(z){}
    ~Point(){}

    double x() const {return x_;}
    double y() const {return y_;}
    double z() const {return x_;}

    void set_x(double val){x_ = val;}
    void set_y(double val){y_ = val;}
    void set_z(double val){z_ = val;}
    void setxyz(double x, double y, double z){x_ = x; y_ = y; z_ = z}

    void add(const Point& other){
        x_ += other.x_; y_ += other.y_; z += other.z_;
    }
    void sub(const Point& other){
        x_ -= other.x_; y_ -= other.y_; z -= other.z_;
    }

    void scale_x(double s){x_ *= s;}
    void scale_y(double s){y_ *= s;}
    void scale_z(double s){z_ *= s;}
    void scale(double s){scale_x(s); scale_y(s); scale_z(s);}

    void RotateAround(const Point& vec, double angle_radians){
        Point u = vec.Normalize();
        double c = cos(angle_radians);
        double i_c = 1 - c;
        double s = sin(angle_radians);
        double u_xy = u.x() * u.y(), u_xz = u.x() * u.z(), u_yz = u.y() * u.z();
        double u_xx = u.x() * u.x(), u_yy = u.y() * u.y(), u_zz = u.z() * u.z();
        *this = Point((c + u_xx * i_c) * x_ + (u_xy * i_c - u.z() * s) * y_ + (u_xz * i_c + u.y() * s) * z_,
                      (u_xy * i_c + u.z() * s) * x_ + (c + u_yy * i_c) * y_ + (u_yz * i_c - u.x() * s) * z_,
                      (u_xz * i_c - u.y() * s) * x_ + (u_yz * i_c + u.x() * s) * y_ + (c + u_zz * i_c) * z_);
    }
    Point RotateAround(const Point& vec, double angle_radians) const{
        Point copyPoint = *this;
        copyPoint.RotateAround(vec, angle_radians);
        return copyPoint;
    }

    Point& operator =(const Point& other){
        x_ = other.x_; y_ = other.y_; z_ = other.z_;
        return *this;
    }
    Point operator +(const Point& other) const {
        return Point(x()+other.x(), y()+other.y(), z()+other.z());
    }
    Point operator -(const Point& other) const {
        return Point(x()-other.x(), y()-other.y(), z()-other.z());
    }
    Point operator *(double s) const {
        return Point(x()*s, y()*s, z()*s);
    }
    Point operator /(double s) const {
        return Point(x()/s, y()/s, z()/s);
    }

    //dot product
    double operator *(const Point& other) const {
        return x()*other.x() + y()*other.y() + z()*other.z();
    }

    //cross product
    Point Cross(const Point& other) const {
        return Point(y()*other.z() - other.y()*z(),
                     z()*other.x() - other.z()*x(),
                     x()*other.y() - other.x()*y());
    }

    //comparison
    bool operator <(const Point& other) const;
    bool operator <=(const Point& other) const;
    bool operator >(const Point& other) const;
    bool operator >=(const Point& other) const;
    bool operator ==(const Point& other) const;
    bool operator !=(const Point& other) const;

    double DistanceFrom(const Point& other) const {
        return sqrt(x()*other.x() + y()*otehr.y(), z()*other.z());
    }
    double magnitude() const {
        return sqrt(x()*x() + y()*y(), z()*z());
    }
    void Normalize(){
        double m = magnitude();
        if(m != 0){
            *this = *this / m;
        }
    }
};

#endif // POINT_HH_