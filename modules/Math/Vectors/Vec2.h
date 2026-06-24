#ifndef UCXX_MATH_VECTORS_VEC2_H
#define UCXX_MATH_VECTORS_VEC2_H

#include <ostream>

struct Vec2
{
    float m_x;
    float m_y;

    Vec2(); // (0.0f, 0.0f)
    Vec2(float x, float y);
    Vec2(const Vec2& value);

    Vec2 operator+(const Vec2& value) const;   
    Vec2 operator*(const float& value) const; 
    Vec2 operator-(const Vec2& value) const;
    Vec2 operator/(const float& value) const; 
    
    bool operator==(const Vec2& value) const;
    bool operator!=(const Vec2& value) const;

    Vec2& operator+=(const Vec2& value);   
    Vec2& operator*=(float value);  
    Vec2& operator-=(const Vec2& value);   
    Vec2& operator/=(float value);

    float Magnitude() const;
    float MagnitudeSquared() const;
    void Normalize();
    Vec2 Normalized() const;

    float Dot(const Vec2& value) const;
};

std::ostream& operator<<(std::ostream& os, const Vec2& value);

#endif