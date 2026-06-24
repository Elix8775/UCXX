#ifndef UCXX_3D_SPHERE_H
#define UCXX_3D_SPHERE_H

#include "../Ray/Ray.h"
#include "../../Math/math.h"

struct Sphere
{
    Vec3 center;
    float radius;

    Sphere() : center(Vec3(0,0,0)), radius(0.0f) {}
    Sphere(const Vec3& center, float radius)
        : center(center), radius(radius) {}
};


#endif