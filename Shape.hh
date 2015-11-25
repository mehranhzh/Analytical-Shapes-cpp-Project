#ifndef SHAPE_HH_
#define SHAPE_HH_

class Shape{
private:
    double x, y, z;
public:
    Shape(double x1, double y1, double z1);
    double getX(), getY(), getZ();
    void setX(double x1);
    void setY(double y1);
    void setZ(double z1);
    void moveTo(double x1, double y1, double z1);
    //virtual bool isInside(double x, double y, double z) const = 0 //pure virtual
    virtual void draw();

};

#endif // SHAPE_HH_
