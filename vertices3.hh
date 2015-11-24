#ifndef VERTICES3_HH_
#define VERTICES3_HH_

#include <cmath>
#include <glm/gtc/matrix_transform.hpp>

class vertex{
public:
    double x, y, z;
    vertex(double x=0, double y=0, double z=0): x(x), y(y), z(z);
    double dotproduct(const vertex& v) const {
        return x * v.x + y * v.y + z * v.z;
    }
    void trans(const glm::mat4& mat){
        glm::vec4 v(x,y,z,1);
        glm::vec4 vt = mat * v;
        x = vt.x; y = vt.y; z = vt.z;
    }
    vertex& operator =(const vertex& v){
        x = v.x; y = v.y; z = v.z;
        return *this;
    }
    vertex operator -(const vertex& v){
        return vertex(x - v.x, y - v.y, z - v.z);
    }
    vertex operator +(const vertex& v){
        return vertex(x + v.x, y + v.y, z + v.z);
    }
    vertex operator /(double a){
        return vertex(x / a, y / a, z / a);
    }
    vertex operator *(double a){
        return vertex(x * a, y * a, z * a);
    }
    double normalize() const {
        return sqrt(x * x + y * y + z * z);
    }
    friend vertex operator -(const vetex& v1, const vertex& v2){
        return vertex(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
    }
    friend vertex operator +(const vetex& v1, const vertex& v2){
        return vertex(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    }
};

#endif // VERTICES3_HH_
