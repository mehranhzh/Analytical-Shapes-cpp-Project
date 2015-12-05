#ifndef RECTANGLE_HH_
#define RECTANGLE_HH_


class Rectangle: public Shape{
private:
    double w, double h;
public:
    Rectangle(double x1, double y1, double z1, double w1, double h1);
    double getW();
    double getH();
    void setW(){ double w1; }
    void setH(){ double h1; }
    void draw();

};

#endif // RECTANGLE_HH_
