// Vec3 (header)
// Author: Elix8775

#ifndef UCXX_MATH_VECTORS_VEC3_H
#define UCXX_MATH_VECTORS_VEC3_H

#include <ostream>

struct Vec3
{
public:
    float m_x;
    float m_y;
    float m_z;

    static const Vec3 Right;
	static const Vec3 Up;
	static const Vec3 Forward;
	static const Vec3 Zero;

    Vec3();
    Vec3(float x, float y, float z);
    Vec3(const Vec3& value);

    Vec3 operator+(const Vec3& value) const;   
    Vec3 operator*(const float& value) const; 
    Vec3 operator-(const Vec3& value) const;
    Vec3 operator/(const float& value) const; 

    float Magnitude() const;
    float MagnitudeSquared() const;
    void Normalize();
    Vec3 Normalized() const;

    bool operator==(const Vec3& value) const;
    bool operator!=(const Vec3& value) const;

    Vec3& operator+=(const Vec3& value);   
    Vec3& operator*=(float value);  
    Vec3& operator-=(const Vec3& value);   
    Vec3& operator/=(float value);
    Vec3& operator=(const Vec3&) = default;

    static Vec3 CrossProduct(const Vec3& a, const Vec3& b);
    static float Dot(const Vec3& a, const Vec3& b);
    static Vec3 Orthogonal(const Vec3& v);
	static Vec3 Lerp(const Vec3& v, const Vec3& v2, float t);
	static Vec3 Slerp(const Vec3& v, const Vec3& v2, float t, bool longPath);
};
std::ostream& operator<<(std::ostream& os, const Vec3& value);

#endif