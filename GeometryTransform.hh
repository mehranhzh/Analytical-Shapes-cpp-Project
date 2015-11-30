#ifndef GEOMETRYTRANSFORM_HH_
#define GEOMETRYTRANSFORM_HH_

class GeometryTransform{
public:
    GeometryTransform(){}
    virtual ~GeometryTransform(){}
    virtual Point Transform(const Point& input) = 0;
};

class ScaleTransform: public GeometryTransform{
private:
    Point scale_;
public:
    ScaleTransform(const Point& scale): scale_(scale){}
    ScaleTransform(const double& s): scale_(Point(s, s, s)){}
    virtual ~ScaleTransform(){}
    virtual Point Transform(const Point& input){
        Point copy_ = input;
        copy_.scale_x(scale_.x());
        copy_.scale_x(scale_.y());
        copy_.scale_x(scale_.z());
        return copy_;
    }
};

class TranslateTransform: public GeometryTransform{
private:
    Point translate_;
public:
    TranslateTransform(const Point& translate): translate_(translate){}
    virtual ~TranslateTransform(){}
    virtual Point Transform(const Point& input){
        Point copy_ = input;
        copy_.add(translate_);
        return copy_;
    }
};

class RotateTransform: public GeometryTransform{
private:
    Point origin_, vector_;
    double radians_;
public:
    RotateTransform(const Point& vec, double radians):
        origin_(Point(0,0,0)), vector_(vec), radians_(radians){}
    RotateTransform(const Point& center, const Point& vec, double radians):
        origin_(center), vector_(vec), radians_(radians){}
    virtual ~RotateTransform(){}
    virtual Point Transform(const Point& input){
        Point copy_ = input;
        copy_.sub(origin_); //make input into a vector
        copy_.RotateAround(vector_, radians_); //rotate
        copy_.add(origin_); //get the rotated point
        return copy_;
    }
};

#endif // GEOMETRYTRANSFORM_HH_
