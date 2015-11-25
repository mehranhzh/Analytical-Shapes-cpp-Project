#ifndef CIRCLE_HH_
#define CIRCLE_HH_

class Circle : public Shape{
private:
    double r;
public:
    Circle(double x1, double y1, double r1);
    double getR();
    void setR(){double r1};
    void draw();


};

#endif // CIRCLE_H
