// Vec2 (header)
// Author: Elix8775

#ifndef UCXX_MATH_VECTORS_VEC2_H
#define UCXX_MATH_VECTORS_VEC2_H

struct Vec2
{
    float m_x;
    float m_y;

    Vec2(); // (0.0f, 0.0f)
    Vec2(float x, float y);

    Vec2 operator+(const Vec2& a) const;   // add 2 vectors
    Vec2 operator*(const float& a) const;  // multiply 1 vector * float (scalaire)
    Vec2 operator-(const Vec2& a) const;   // 1 vector - 1 vector
    Vec2 operator/(const float& a) const;  // dvise 1 vector / float

    float Magnitude() const;
    float MagnitudeSquared() const;
    void Normalize();
    Vec2 Normalized() const;

    float Dot(const Vec2& value) const;
};


#endif