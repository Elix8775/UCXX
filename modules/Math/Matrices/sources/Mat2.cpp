// Main function Mat2.cpp
// Author: ELix8775

#include "../Mat2.h"
#include <cmath>
#include <stdexcept>

Mat2::Mat2()
{
    m[0][0] = 0.0f; m[0][1] = 0.0f;
    m[1][0] = 0.0f; m[1][1] = 0.0f;
}

Mat2::Mat2(float m00, float m01, float m10, float m11)
{
    m[0][0] = m00; m[0][1] = m01;
    m[1][0] = m10; m[1][1] = m11;
}

Mat2::Mat2(const Vec2& a, const Vec2& b)
{
    m[0][0] = a.m_x; m[0][1] = b.m_x;
    m[1][0] = a.m_y; m[1][1] = b.m_y;
}

Mat2::Mat2(const Mat2& value)
{
    m[0][0] = value.m[0][0]; m[0][1] = value.m[0][1];
    m[1][0] = value.m[1][0]; m[1][1] = value.m[1][1];
}

float& Mat2::operator()(int i, int j)
{
    return m[i][j];
}

const float& Mat2::operator()(int i, int j) const
{
    return m[i][j];
}

Mat2& Mat2::operator+=(const Mat2& b)
{
    m[0][0] += b.m[0][0]; m[0][1] += b.m[0][1];
    m[1][0] += b.m[1][0]; m[1][1] += b.m[1][1];
    return *this;
}

Mat2& Mat2::operator-=(const Mat2& b)
{
    m[0][0] -= b.m[0][0]; m[0][1] -= b.m[0][1];
    m[1][0] -= b.m[1][0]; m[1][1] -= b.m[1][1];
    return *this;
}

Mat2& Mat2::operator*=(const float& s)
{
    m[0][0] *= s; m[0][1] *= s;
    m[1][0] *= s; m[1][1] *= s;
    return *this;
}

Mat2& Mat2::operator*=(const Mat2& b)
{
    float t00 = m[0][0] * b.m[0][0] + m[0][1] * b.m[1][0];
    float t01 = m[0][0] * b.m[0][1] + m[0][1] * b.m[1][1];
    float t10 = m[1][0] * b.m[0][0] + m[1][1] * b.m[1][0];
    float t11 = m[1][0] * b.m[0][1] + m[1][1] * b.m[1][1];
    m[0][0] = t00; m[0][1] = t01;
    m[1][0] = t10; m[1][1] = t11;
    return *this;
}

bool Mat2::operator==(const Mat2& value) const
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (m[i][j] != value.m[i][j])
                return false;
    return true;
}

bool Mat2::operator!=(const Mat2& value) const
{
    return !(*this == value);
}

Mat2 Mat2::Transpose() const
{
    return Mat2(m[0][0], m[1][0],
                m[0][1], m[1][1]);
}

Mat2 Mat2::Inverse() const
{
    float determinant = Determinant();
    if (fabsf(determinant) < 1e-5f)
        throw std::invalid_argument("determinant is 0, cannot be inverted.");

    return (1.0f / determinant) * Mat2(m[1][1], -m[0][1],
                                      -m[1][0],  m[0][0]);
}

float Mat2::Determinant() const
{
    return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

Mat2 operator+(const Mat2& a, const Mat2& b)
{
    return Mat2(a.m[0][0] + b.m[0][0], a.m[0][1] + b.m[0][1],
                a.m[1][0] + b.m[1][0], a.m[1][1] + b.m[1][1]);
}

Mat2 operator-(const Mat2& a, const Mat2& b)
{
    return Mat2(a.m[0][0] - b.m[0][0], a.m[0][1] - b.m[0][1],
                a.m[1][0] - b.m[1][0], a.m[1][1] - b.m[1][1]);
}

Mat2 operator*(const Mat2& a, const float& s)
{
    return Mat2(a.m[0][0] * s, a.m[0][1] * s,
                a.m[1][0] * s, a.m[1][1] * s);
}

Mat2 operator*(const float& s, const Mat2& a)
{
    return a * s;
}

Mat2 operator*(const Mat2& a, const Mat2& b)
{
    return Mat2(a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0],
                a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1],
                a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0],
                a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1]);
}

std::ostream& operator<<(std::ostream& os, const Mat2& value)
{
    os << "(m00 : " << value.m[0][0] << ", m01 : " << value.m[0][1] << ")\n"
       << "(m10 : " << value.m[1][0] << ", m11 : " << value.m[1][1] << ")\n";
    return os;
}

Mat2 Mat2::Identity()
{
    return Mat2(1.0f, 0.0f,
                0.0f, 1.0f);
}

Mat2 Mat2::Rotate(const float& angle)
{
    float rad = angle * M_PI / 180.0f;
    return Mat2(cosf(rad), -sinf(rad),
                sinf(rad),  cosf(rad));
}

Mat2 Mat2::Scale(const Vec2& scale)
{
    return Mat2(scale.m_x, 0.0f,
                0.0f,      scale.m_y);
}

Mat2 Mat2::RS(const float& angle, const Vec2& scale)
{
    return Rotate(angle) * Scale(scale);
}

Vec2 operator*(const Mat2& a, const Vec2& b)
{
    return Vec2(a.m[0][0] * b.m_x + a.m[0][1] * b.m_y,
                a.m[1][0] * b.m_x + a.m[1][1] * b.m_y);
}

Vec2 operator*(const Vec2& b, const Mat2& a)
{
    return Vec2(b.m_x * a.m[0][0] + b.m_y * a.m[0][1],
                b.m_x * a.m[1][0] + b.m_y * a.m[1][1]);
}