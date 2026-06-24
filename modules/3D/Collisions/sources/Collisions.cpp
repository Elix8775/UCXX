#include "../Collisions.h"

#include <algorithm>

namespace ucxx
{
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

bool IntersectRayAABB(const Ray& ray, const AABB& box, float& t)
{
    float tmin = (box.min.m_x - ray.origin.m_x) * ray.invDir.m_x;
    float tmax = (box.max.m_x - ray.origin.m_x) * ray.invDir.m_x;

    if (tmin > tmax) std::swap(tmin, tmax);

    float tymin = (box.min.m_y - ray.origin.m_y) * ray.invDir.m_y;
    float tymax = (box.max.m_y - ray.origin.m_y) * ray.invDir.m_y;

    if (tymin > tymax) std::swap(tymin, tymax);

    if ((tmin > tymax) || (tymin > tmax))
        return false;

    if (tymin > tmin)
        tmin = tymin;

    if (tymax < tmax)
        tmax = tymax;

    float tzmin = (box.min.m_z - ray.origin.m_z) * ray.invDir.m_z;
    float tzmax = (box.max.m_z - ray.origin.m_z) * ray.invDir.m_z;

    if (tzmin > tzmax) std::swap(tzmin, tzmax);

    if ((tmin > tzmax) || (tzmin > tmax))
        return false;

    if (tzmin > tmin)
        tmin = tzmin;

    if (tzmax < tmax)
        tmax = tzmax;

    if (tmin < 0.0f)
    {
        if (tmax < 0.0f) return false;
        t = tmax;
    }
    else
    {
        t = tmin;
    }
    return true;
}
}