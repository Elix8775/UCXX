#include "../Ray.h"

Ray::Ray()
    : origin(Vec3(0,0,0)), direction(Vec3(0,0,1))
{
}

Ray::Ray(const Vec3& ori, const Vec3& dir)
    : origin(ori), direction(dir.Normalized())
{
    invDir.m_x = (direction.m_x != 0.0f) ? (1.0f / direction.m_x) : 1e30f;
    invDir.m_y = (direction.m_y != 0.0f) ? (1.0f / direction.m_y) : 1e30f;
    invDir.m_z = (direction.m_z != 0.0f) ? (1.0f / direction.m_z) : 1e30f;
}

Vec3 Ray::pointAt(float t) const
{
    return origin + direction * t;
}