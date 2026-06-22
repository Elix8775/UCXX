// Main function Vec4.cpp
// Author: Elix8775

#include "../Vec4.h"
#include <cmath>

Vec4::Vec4()
    : m_x(0.0f), m_y(0.0f), m_z(0.0f), m_w(0.0f)
{
}

Vec4::Vec4(float x, float y, float z, float w)
    : m_x(x), m_y(y), m_z(z), m_w(w)
{
}

Vec4::Vec4(const Vec4& value)
    : m_x(value.m_x), m_y(value.m_y), m_z(value.m_z), m_w(value.m_w)
{
}

Vec4 Vec4::operator+(const Vec4& value) const
{
	return Vec4(m_x + value.m_x, m_y + value.m_y, m_z + value.m_z, m_w + value.m_w);
}

Vec4 Vec4::operator*(const float& value) const
{
	return Vec4(m_x * value, m_y * value, m_z * value, m_w * value);
}

Vec4 Vec4::operator-(const Vec4& value) const
{
	return Vec4(m_x - value.m_x, m_y - value.m_y, m_z - value.m_z, m_w - value.m_w);
}

Vec4 Vec4::operator/(const float& value) const
{
	float v = 1.0f / value;
	return Vec4(m_x * v, m_y * v, m_z * v, m_w * v);
}

Vec4& Vec4::operator+=(const Vec4& value)
{
	m_x += value.m_x;
	m_y += value.m_y;
	m_z += value.m_z;
    m_w += value.m_w;

	return (*this);
}

Vec4& Vec4::operator*=(float value)
{
	m_x *= value;
	m_y *= value;
	m_z *= value;
    m_w *= value;

	return (*this);
}

Vec4& Vec4::operator-=(const Vec4& value)
{
	m_x -= value.m_x;
	m_y -= value.m_y;
	m_z -= value.m_z;
    m_w -= value.m_w;

	return (*this);
}

Vec4& Vec4::operator/=(float value)
{
	m_x /= value;
	m_y /= value;
	m_z /= value;
    m_w /= value;

	return (*this);
}

bool Vec4::operator==(const Vec4& value) const
{
	const float epsilon = 1e-5;

	return (abs(m_x - value.m_x) < epsilon && abs(m_y - value.m_y) < epsilon && abs(m_z - value.m_z) < epsilon && abs(m_w - value.m_w) < epsilon);
}

bool Vec4::operator!=(const Vec4& value) const
{
	const float epsilon = 1e-5;
	return (abs(m_x - value.m_x) > epsilon || abs(m_y - value.m_y) > epsilon || abs(m_z - value.m_z) > epsilon || abs(m_w - value.m_w) > epsilon);
}

float Vec4::Magnitude() const
{
	return sqrtf(m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w);
}

float Vec4::MagnitudeSquared() const
{
    return m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w;
}

void Vec4::Normalize()
{
	float magnitude = Magnitude();
	m_x /= magnitude;
	m_y /= magnitude;
	m_z /= magnitude;
    m_w /= magnitude;
}

Vec4 Vec4::Normalized() const
{
	return (*this) / Magnitude();
}

float Vec4::Dot(const Vec4& a, const Vec4& b)
{
	return a.m_x * b.m_x + a.m_y * b.m_y + a.m_z * b.m_z + a.m_w * b.m_w;
}

std::ostream& operator<<(std::ostream& os, const Vec4& value)
{
	os << "(X : " << value.m_x << ", Y : " << value.m_y << ", Z : " << value.m_z << ", W : " << value.m_w << ")" << std::endl;
	return os;
}
