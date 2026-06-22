// Vec3 (header)
// Author: Elix8775

#ifndef UCXX_MATH_VECTORS_VEC3_H
#define UCXX_MATH_VECTORS_VEC3_H

#include <ostream>

struct Vec3
{
    float m_x;
    float m_y;
    float m_z;

    Vec3();
    Vec3(float x, float y, float z);
    Vec3(const Vec3& value);

    Vec3 operator+(const Vec3& value) const;   
    Vec3 operator*(const float& value) const; 
    Vec3 operator-(const Vec3& value) const;
    Vec3 operator/(const float& value) const; 

    float Magnitude() const;
    void Normalize();
    Vec3 Normalized() const;

    bool operator==(const Vec3& value) const;
    bool operator!=(const Vec3& value) const;

    Vec3& operator+=(const Vec3& value);   
    Vec3& operator*=(float value);  
    Vec3& operator-=(const Vec3& value);   
    Vec3& operator/=(float value);

    static Vec3 CrossProduct(const Vec3& a, const Vec3& b);
    static float Dot(const Vec3& a, const Vec3& b);
};
std::ostream& operator<<(std::ostream& os, const Vec3& value);

#endif