#include "../AABB.h"

AABB::AABB()
    : min(Vec3(0,0,0)), max(Vec3(0,0,0))
{
}

AABB::AABB(const Vec3& min, const Vec3& max)
    : min(min), max(max)
{
}

bool AABB::contains(const Vec3& point) const
{
    return (point.m_x >= min.m_x && point.m_x <= max.m_x) &&
           (point.m_y >= min.m_y && point.m_y <= max.m_y) &&
           (point.m_z >= min.m_z && point.m_z <= max.m_z);
}