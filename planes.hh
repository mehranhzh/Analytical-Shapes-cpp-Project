#ifndef PLANES_HH_
#define PLANES_HH_

#include <cmath>
#include "vertices3.hh"

class plane{
private:
    vertex vNormal; //normalized vector of a plane
    double vDistance; //distance from a plane to (0,0,0)
public:
    plane():vDistance(0){}
    double distance() const {
        return vDistance;
    }
    double distanceToVertex(const vertex& v) const {
        return vertex.dotproduct(Vnormal) - vDistance;
    }
    void setNormal(vertex normal){
        vNormal = normal;
    }
    void setDistance(double d){
        vDistance = d;
    }

};
#endif // PLANES_HH_
