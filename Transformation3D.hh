#ifndef TRANSFORMATION3D_HH_
#define TRANSFORMATION3D_HH_

#include "Cube.hh"
#include "Sphere.hh"
#include "Cylinder.hh"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transformation3D{
public:
    Transformation3D();
    virtual ~Transformation3D();
    static void Translation();
    static void Rotation();
    static void Scale();
};

#endif // TRANSFORMATION3D_HH_
