#ifndef UCXX_MATH_VECTORS_VEC4_H
#define UCXX_MATH_VECTORS_VEC4_H

#include <ostream>

struct Vec4
{
    float m_x;
    float m_y;
    float m_z;
    float m_w;

    Vec4();
    Vec4(float x, float y, float z, float w);
    Vec4(const Vec4& value);

    Vec4 operator+(const Vec4& value) const;   
    Vec4 operator*(const float& value) const; 
    Vec4 operator-(const Vec4& value) const;
    Vec4 operator/(const float& value) const; 

    float Magnitude() const;
    float MagnitudeSquared() const;
    void Normalize();
    Vec4 Normalized() const;

    bool operator==(const Vec4& value) const;
    bool operator!=(const Vec4& value) const;

    Vec4& operator+=(const Vec4& value);   
    Vec4& operator*=(float value);  
    Vec4& operator-=(const Vec4& value);   
    Vec4& operator/=(float value);

    static float Dot(const Vec4& a, const Vec4& b);
};
std::ostream& operator<<(std::ostream& os, const Vec4& value);

#endif