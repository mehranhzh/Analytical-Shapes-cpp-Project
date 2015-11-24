#ifndef CUBE_HH_
#define CUBE_HH_

class Cube{
private:
    double a, double b, double c;
public:
    Cube(double a = 1, double b = 1, double c = 1);
    void getSTL();
    double getVolume();
    double geta();
    double getb();
    double getc();
};

#endif // CUBE_HH_
