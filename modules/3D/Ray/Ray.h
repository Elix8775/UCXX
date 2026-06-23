#ifndef UCXX_3D_RAY_H
#define UCXX_3D_RAY_H

#include "../../Math/math.h"

struct Ray
{
    Vec3 origin;
    Vec3 direction;

    Vec3 invDir;

    Ray();
    Ray(const Vec3& ori, const Vec3& dir);

    Vec3 pointAt(float t) const;
};


#endif