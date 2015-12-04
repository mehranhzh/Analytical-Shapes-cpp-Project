//Shape class will based class of other shapes
#ifndef SHAPE_HH_
#define SHAPE_HH_

class Shape{//abstract class shape
private:
    double x, y, z;
public:
    Shape(double x1, double y1, double z1);//Constructor 3D
    Shape(double x1, double y1);//Constructor 2D
    double getX(), getY(), getZ();//get position x,y,z
    void setX(double x1);//set position x
    void setY(double y1);//set position y
    void setZ(double z1);//set position z
    virtual void moveTo(double x1, double y1, double z1)=0;//pure virtual function that move position to new position
    //virtual bool isInside(double x, double y, double z) = 0; //check if shape is inside of another one
    virtual double area() const = 0;//calculate the area of shapes
    virtual void draw()=0;//draw graphs or shapes
    virtual void volume()=0;//draw graphs or shapes
    virtual ~Shape(){};//Destructor

};

#endif // SHAPE_HH_
