#include "ucxx.h"
#include <iostream>
#include <cmath>

int main()
{   
    Vec3 origin(1.0f, 1.5f, 2.0f);
    Vec3 direction(0.0f, -1.0f, 0.0f);
    Ray ray(origin, direction);

    Vec3 planePoint(0.0f, 0.0f, 0.0f);
    Vec3 planeNormal(0.0f, 1.0f, 0.0f);

    Vec3 diff = origin - planePoint;

    float denom = Vec3::Dot(direction, planeNormal);
    float num = Vec3::Dot(diff, planeNormal);

    if (fabs(denom) < 0.0001f)
    {
        std::cout << "No intersection (parallel)\n";
        return 0;
    }

    float t = -num / denom;

    if (t < 0.0f)
    {
        std::cout << "Intersection behind ray\n";
        return 0;
    }

    Vec3 hit = origin + direction * t;

    std::cout << "Hit: " << hit.m_x << ", " << hit.m_y << ", " << hit.m_z << "\n";

    return 0;
}