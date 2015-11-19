#ifndef SHAPE_HH_
#define SHAPE_HH_

class Shape{
protected:
    double x, y, z;
public:
    Shape(double x, double y, double z): x(x), y(y), z(z){}
    int getX(), getY(), getZ();
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    virtual bool isInside(double x, double y, double z) const = 0 //pure virtual
    virtual void draw();

};

#endif // SHAPE_HH_
