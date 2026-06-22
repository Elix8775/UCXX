// Main function Vec3.cpp
// Author: Elix8775

#include "../Vec3.h"
#include <math.h>

Vec3::Vec3()
	: m_x(0.0f), m_y(0.0f), m_z(0.0f)
{
}

Vec3::Vec3(float x, float y, float z)
	: m_x(x), m_y(y), m_z(z)
{
}

Vec3::Vec3(const Vec3& value)
	: m_x(value.m_x), m_y(value.m_y), m_z(value.m_z)
{
}

Vec3 Vec3::operator+(const Vec3& value) const
{
	return Vec3(m_x + value.m_x, m_y + value.m_y, m_z + value.m_z);
}

Vec3 Vec3::operator*(const float& value) const
{
	return Vec3(m_x * value, m_y * value, m_z * value);
}

Vec3 Vec3::operator-(const Vec3& value) const
{
	return Vec3(m_x - value.m_x, m_y - value.m_y, m_z - value.m_z);
}

Vec3 Vec3::operator/(const float& value) const
{
	float v = 1.0f / value;
	return Vec3(m_x * v, m_y * v, m_z * v);
}

float Vec3::Magnitude() const
{
	return sqrtf(m_x * m_x + m_y * m_y + m_z * m_z);
}

void Vec3::Normalize()
{
	float magnitude = Magnitude();
	m_x /= magnitude;
	m_y /= magnitude;
	m_z /= magnitude;
}

Vec3& Vec3::operator+=(const Vec3& value)
{
	m_x += value.m_x;
	m_y += value.m_y;
	m_z += value.m_z;

	return (*this);
}

Vec3& Vec3::operator*=(float value)
{
	m_x *= value;
	m_y *= value;
	m_z *= value;

	return (*this);
}

Vec3& Vec3::operator-=(const Vec3& value)
{
	m_x -= value.m_x;
	m_y -= value.m_y;
	m_z -= value.m_z;

	return (*this);
}

Vec3& Vec3::operator/=(float value)
{
	m_x /= value;
	m_y /= value;
	m_z /= value;

	return (*this);
}

bool Vec3::operator==(const Vec3& value) const
{
	const float epsilon = 1e-5;

	return (abs(m_x - value.m_x) < epsilon && abs(m_y - value.m_y) < epsilon && abs(m_z - value.m_z) < epsilon);
}

bool Vec3::operator!=(const Vec3& value) const
{
	const float epsilon = 1e-5;
	return (abs(m_x - value.m_x) > epsilon || abs(m_y - value.m_y) > epsilon || abs(m_z - value.m_z) > epsilon);
}


Vec3 Vec3::Normalized() const
{
	return (*this) / Magnitude();
}

float Vec3::Dot(const Vec3& a, const Vec3& b)
{
	return a.m_x * b.m_x + a.m_y * b.m_y + a.m_z * b.m_z;
}

Vec3 Vec3::CrossProduct(const Vec3& a, const Vec3& b)
{
	return Vec3(a.m_y * b.m_z - b.m_y * a.m_z, a.m_z * b.m_x - b.m_z * a.m_x, a.m_x * b.m_y - b.m_x * a.m_y);
}

std::ostream& operator<<(std::ostream& os, const Vec3& value)
{
	os << "(X : " << value.m_x << ", Y : " << value.m_y << ", Z : " << value.m_z << ")" << std::endl;
	return os;
}
