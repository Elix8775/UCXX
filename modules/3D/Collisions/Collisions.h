#ifndef UCXX_COLLISIONS_H
#define UCXX_COLLISIONS_H

#include "../Ray/Ray.h"
#include "../Sphere/Sphere.h"
#include "../AABB/AABB.h"
namespace ucxx
{
    bool IntersectRaySphere(const Ray& ray, const Sphere& sphere, float& t);
    bool IntersectRayAABB(const Ray& ray, const AABB& box, float& t);
}

#endif