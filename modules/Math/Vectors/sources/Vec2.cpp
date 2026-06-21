// Main function Vec2.cpp
// Author: Elix8775

#include "../Vec2.h"
#include <cmath>
#include <ostream>

Vec2::Vec2()
    : m_x(0.0f), m_y(0.0f)
{
}

Vec2::Vec2(float x, float y)
    : m_x(x), m_y(y)
{
}

Vec2 Vec2::operator+(const Vec2& value) const 
{
    return Vec2(m_x + value.m_x, m_y + value.m_y);
}

Vec2 Vec2::operator*(const float& value) const 
{
    return Vec2(m_x * value, m_y * value);
}

Vec2 Vec2::operator-(const Vec2& value) const 
{
    return Vec2(m_x - value.m_x, m_y - value.m_y);
}

Vec2 Vec2::operator/(const float& value) const 
{   
    float v = 1.0f / value;
    return Vec2(m_x * v, m_y * v);
}

float Vec2::Magnitude() const
{
    return sqrtf(m_x * m_x + m_y * m_y);
}

float Vec2::MagnitudeSquared() const
{
    return m_x * m_x + m_y * m_y;
}

void Vec2::Normalize()
{
    float magnitude = Magnitude();

    if (magnitude == 0.0f)
        return;

    m_x /= magnitude;
    m_y /= magnitude;
}

Vec2 Vec2::Normalized() const
{
    float magnitude = Magnitude();
    if (magnitude == 0.0f)
        return Vec2();

    return (*this) / magnitude;
}

Vec2& Vec2::operator+=(const Vec2& value)
{
    m_x += value.m_x;
    m_y += value.m_y;

    return (*this);
}

Vec2& Vec2::operator*=(float value)
{
    m_x *= value;
    m_y *= value;

    return (*this);
}

Vec2& Vec2::operator-=(const Vec2& value)
{
    m_x -= value.m_x;
    m_y -= value.m_y;

    return (*this);
}

Vec2& Vec2::operator/=(float value)
{
    m_x /= value;
    m_y /= value;

    return (*this);
}

float Vec2::Dot(const Vec2& value) const
{
    return m_x * value.m_x +
           m_y * value.m_y;
}

bool Vec2::operator==(const Vec2& value) const
{
    return (m_x == value.m_x && m_y == value.m_y);
}

bool Vec2::operator!=(const Vec2& value) const
{
    return (m_x != value.m_x || m_y != value.m_y);
}

Vec2::Vec2(const Vec2& value)
{
    m_x = value.m_x;
    m_y = value.m_y;
}

std::ostream& operator<<(std::ostream& os, const Vec2& value)
{
    os << "(x : " << value.m_x << ", Y : " << value.m_y << ")" << std::endl;
    return os;
}