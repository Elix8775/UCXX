#include "../Sphere.h"

#include <cmath>

bool IntersectRaySphere(const Ray& ray, const Sphere& sphere, float& t)
{
    Vec3 L = ray.origin - sphere.center;

    float b = Vec3::Dot(L, ray.direction);
    float c = Vec3::Dot(L, L) - sphere.radius * sphere.radius;

    float discriminant = b * b - c;

    if (discriminant < 0.0f)
        return false;

    float sqrtD = sqrtf(discriminant);

    float t0 = -b - sqrtD;
    float t1 = -b + sqrtD;

    if (t0 > 0.0f)
        t = t0;
    else if (t1 > 0.0f)
        t = t1;
    else
        return false;

    return true;
}