//Author: Yu Hongshen
//This is the class of transformation

#ifndef GEOMETRYTRANSFORM_HH_
#define GEOMETRYTRANSFORM_HH_

//base class of all kinds of transform
class GeometryTransform{
public:
    GeometryTransform(){}
    virtual ~GeometryTransform(){}
    virtual Point Transform(const Point& input) = 0;
};

//scale transformation
class ScaleTransform: public GeometryTransform{
private:
    Point scale_;
public:
    //constructor
    ScaleTransform(const Point& scale): scale_(scale){}
    ScaleTransform(const double& s): scale_(Point(s, s, s)){}
    virtual ~ScaleTransform(){}

    //calculate the coordinate of a scaled point
    virtual Point Transform(const Point& input){
        Point copy_ = input;
        copy_.scale_x(scale_.x());
        copy_.scale_x(scale_.y());
        copy_.scale_x(scale_.z());
        return copy_;
    }
};

//translate transformation
class TranslateTransform: public GeometryTransform{
private:
    Point translate_;
public:
    TranslateTransform(const Point& translate): translate_(translate){}
    virtual ~TranslateTransform(){}

    //calculate the coordinate of a translated point
    virtual Point Transform(const Point& input){
        Point copy_ = input;
        copy_.add(translate_);
        return copy_;
    }
};

//rotate transformation
class RotateTransform: public GeometryTransform{
private:
    Point origin_, vector_;
    double radians_;
public:
    RotateTransform(const Point& vec, double radians):
        origin_(Point(0,0,0)), vector_(vec), radians_(radians){}
    RotateTransform(const Point& center, const Point& vec, double radians):
        origin_(center), vector_(vec), radians_(radians){}
    ~RotateTransform(){}

    //calculate the coordinate of a point after its rotation
    Point Transform(const Point& input){
        Point copy_ = input;
        copy_.sub(origin_); //make input into a vector
        copy_.RotateAround(vector_, radians_); //rotate
        copy_.add(origin_); //get the rotated point
        return copy_;
    }
};

#endif // GEOMETRYTRANSFORM_HH_
