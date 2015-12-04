//Author: Yu Hongshen
//cubic class

#ifndef CUBE_HH_
#define CUBE_HH_

using namespace std;

class Cube{
private:
    double a_, b_, c_;   //the length of every side
public:
    Cube(double a_ = 1, double b_ = 1, double c_ = 1);

    //accessors
    double a() const {return a_;}
    double b() const {return b_;}
    double c() const {return c_;}

    //set some values
    void set_a(double a){a_ = a;}
    void set_b(double b){b_ = b;}
    void set_c(double c){c_ = c;}

    double getVolume(){
        return a()*b()*c();
    }
};

#endif // CUBE_HH_
