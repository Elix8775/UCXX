#ifndef UCXX_AABB_H
#define UCXX_AABB_H

#include "../../Math/Vectors/Vec3.h"

struct AABB
{
    Vec3 min;
    Vec3 max;

    AABB();

    AABB(const Vec3& min, const Vec3& max);
    bool contains(const Vec3& point) const;
};


#endif