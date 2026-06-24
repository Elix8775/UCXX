// Main function Mat3.cpp
// Author: Elix8775

#include "../Mat3.h"
#include "../../Mathf/Mathf.h"
#include <cmath>

Mat3::Mat3()
{
    m[0][0] = 0.0f; m[0][1] = 0.0f; m[0][2] = 0.0f;
    m[1][0] = 0.0f; m[1][1] = 0.0f; m[1][2] = 0.0f;
    m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 0.0f;
}

Mat3::Mat3(float m00, float m01, float m02,
           float m10, float m11, float m12,
           float m20, float m21, float m22)
{
    m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
    m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
    m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
}

Mat3::Mat3(const Mat3& value)
{
    m[0][0] = value.m[0][0]; m[0][1] = value.m[0][1]; m[0][2] = value.m[0][2];
    m[1][0] = value.m[1][0]; m[1][1] = value.m[1][1]; m[1][2] = value.m[1][2];
    m[2][0] = value.m[2][0]; m[2][1] = value.m[2][1]; m[2][2] = value.m[2][2];
}

float& Mat3::operator()(int i, int j)
{
    return m[i][j];
}

const float& Mat3::operator()(int i, int j) const
{
    return m[i][j];
}

Mat3& Mat3::operator+=(const Mat3& b)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            m[i][j] += b.m[i][j];
    return *this;
}

Mat3& Mat3::operator-=(const Mat3& b)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            m[i][j] -= b.m[i][j];
    return *this;
}

Mat3& Mat3::operator*=(const float& s)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            m[i][j] *= s;
    return *this;
}

Mat3& Mat3::operator*=(const Mat3& b)
{
    Mat3 t;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                t.m[i][j] += m[i][k] * b.m[k][j];
    *this = t;
    return *this;
}

Mat3& Mat3::operator=(const Mat3& value)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            m[i][j] = value.m[i][j];
    return *this;
}

bool Mat3::operator==(const Mat3& value) const
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (m[i][j] != value.m[i][j])
                return false;
    return true;
}

bool Mat3::operator!=(const Mat3& value) const
{
    return !(*this == value);
}

Mat3 Mat3::Transpose() const
{
    return Mat3(m[0][0], m[1][0], m[2][0],
                m[0][1], m[1][1], m[2][1],
                m[0][2], m[1][2], m[2][2]);
}

float Mat3::Determinant() const
{
    return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
         - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
         + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}

Mat3 Mat3::Inverse() const
{
    float det = Determinant();
    if (fabsf(det) < 1e-5f)
        throw std::invalid_argument("determinant is 0, cannot be inverted.");

    float invDet = 1.0f / det;

    return Mat3(
         (m[1][1] * m[2][2] - m[1][2] * m[2][1]) * invDet,
        -(m[0][1] * m[2][2] - m[0][2] * m[2][1]) * invDet,
         (m[0][1] * m[1][2] - m[0][2] * m[1][1]) * invDet,

        -(m[1][0] * m[2][2] - m[1][2] * m[2][0]) * invDet,
         (m[0][0] * m[2][2] - m[0][2] * m[2][0]) * invDet,
        -(m[0][0] * m[1][2] - m[0][2] * m[1][0]) * invDet,

         (m[1][0] * m[2][1] - m[1][1] * m[2][0]) * invDet,
        -(m[0][0] * m[2][1] - m[0][1] * m[2][0]) * invDet,
         (m[0][0] * m[1][1] - m[0][1] * m[1][0]) * invDet
    );
}

Mat3 Mat3::Identity()
{
    return Mat3(1.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 1.0f);
}

Mat3 Mat3::Translate(const Vec2& translate)
{
    return Mat3(1.0f, 0.0f, translate.m_x,
                0.0f, 1.0f, translate.m_y,
                0.0f, 0.0f, 1.0f);
}

Mat3 Mat3::RotateZ(const float& angle)
{
    float rad = angle * Mathf::DegToRad;
    return Mat3( cosf(rad), -sinf(rad), 0.0f,
                 sinf(rad),  cosf(rad), 0.0f,
                 0.0f,       0.0f,      1.0f);
}

Mat3 Mat3::ScaleXY(const Vec2& scale)
{
    return Mat3(scale.m_x, 0.0f,      0.0f,
                0.0f,      scale.m_y, 0.0f,
                0.0f,      0.0f,      1.0f);
}

Mat3 Mat3::TS(const Vec2& translate, const Vec2& scale)
{
    return Translate(translate) * ScaleXY(scale);
}

Mat3 Mat3::RS(const float& angle, const Vec2& scale)
{
    return RotateZ(angle) * ScaleXY(scale);
}

Mat3 Mat3::TR(const Vec2& translate, const float& angle)
{
    return Translate(translate) * RotateZ(angle);
}

Mat3 Mat3::TRS(const Vec2& translate, const float& angle, const Vec2& scale)
{
    return Translate(translate) * RotateZ(angle) * ScaleXY(scale);
}

std::array<float, 9> Mat3::GetAsArray() const
{
    return { m[0][0], m[0][1], m[0][2],
             m[1][0], m[1][1], m[1][2],
             m[2][0], m[2][1], m[2][2] };
}

Mat3 operator+(const Mat3& a, const Mat3& b)
{
    return Mat3(a.m[0][0] + b.m[0][0], a.m[0][1] + b.m[0][1], a.m[0][2] + b.m[0][2],
                a.m[1][0] + b.m[1][0], a.m[1][1] + b.m[1][1], a.m[1][2] + b.m[1][2],
                a.m[2][0] + b.m[2][0], a.m[2][1] + b.m[2][1], a.m[2][2] + b.m[2][2]);
}

Mat3 operator-(const Mat3& a, const Mat3& b)
{
    return Mat3(a.m[0][0] - b.m[0][0], a.m[0][1] - b.m[0][1], a.m[0][2] - b.m[0][2],
                a.m[1][0] - b.m[1][0], a.m[1][1] - b.m[1][1], a.m[1][2] - b.m[1][2],
                a.m[2][0] - b.m[2][0], a.m[2][1] - b.m[2][1], a.m[2][2] - b.m[2][2]);
}

Mat3 operator*(const Mat3& a, const float& s)
{
    return Mat3(a.m[0][0] * s, a.m[0][1] * s, a.m[0][2] * s,
                a.m[1][0] * s, a.m[1][1] * s, a.m[1][2] * s,
                a.m[2][0] * s, a.m[2][1] * s, a.m[2][2] * s);
}

Mat3 operator*(const float& s, const Mat3& a)
{
    return a * s;
}

Mat3 operator*(const Mat3& a, const Mat3& b)
{
    Mat3 t;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                t.m[i][j] += a.m[i][k] * b.m[k][j];
    return t;
}

std::ostream& operator<<(std::ostream& os, const Mat3& value)
{
    os << "(m00 : " << value.m[0][0] << ", m01 : " << value.m[0][1] << ", m02 : " << value.m[0][2] << ")\n"
       << "(m10 : " << value.m[1][0] << ", m11 : " << value.m[1][1] << ", m12 : " << value.m[1][2] << ")\n"
       << "(m20 : " << value.m[2][0] << ", m21 : " << value.m[2][1] << ", m22 : " << value.m[2][2] << ")\n";
    return os;
}

Vec2 operator*(const Mat3& a, const Vec2& b)
{
    float w = a.m[2][0] * b.m_x + a.m[2][1] * b.m_y + a.m[2][2];
    return Vec2((a.m[0][0] * b.m_x + a.m[0][1] * b.m_y + a.m[0][2]) / w,
                (a.m[1][0] * b.m_x + a.m[1][1] * b.m_y + a.m[1][2]) / w);
}

Vec2 operator*(const Vec2& b, const Mat3& a)
{
    float w = b.m_x * a.m[0][2] + b.m_y * a.m[1][2] + a.m[2][2];
    return Vec2((b.m_x * a.m[0][0] + b.m_y * a.m[1][0] + a.m[2][0]) / w,
                (b.m_x * a.m[0][1] + b.m_y * a.m[1][1] + a.m[2][1]) / w);
}

Vec3 operator*(const Mat3& a, const Vec3& b)
{
    return Vec3(a.m[0][0] * b.m_x + a.m[0][1] * b.m_y + a.m[0][2] * b.m_z,
                a.m[1][0] * b.m_x + a.m[1][1] * b.m_y + a.m[1][2] * b.m_z,
                a.m[2][0] * b.m_x + a.m[2][1] * b.m_y + a.m[2][2] * b.m_z);
}

Vec3 operator*(const Vec3& b, const Mat3& a)
{
    return Vec3(b.m_x * a.m[0][0] + b.m_y * a.m[1][0] + b.m_z * a.m[2][0],
                b.m_x * a.m[0][1] + b.m_y * a.m[1][1] + b.m_z * a.m[2][1],
                b.m_x * a.m[0][2] + b.m_y * a.m[1][2] + b.m_z * a.m[2][2]);
}