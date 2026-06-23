// Main function Vec3.cpp
// Author: Elix8775

#include "../Vec3.h"
#include "../../Quaternion/Quat.h"
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

const Vec3 Vec3::Right   = Vec3(1.f, 0.f, 0.f);
const Vec3 Vec3::Up      = Vec3(0.f, 1.f, 0.f);
const Vec3 Vec3::Forward = Vec3(0.f, 0.f, 1.f);

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

float Vec3::MagnitudeSquared() const
{
	return m_x * m_x + m_y * m_y + m_z * m_z;
}

void Vec3::Normalize()
{
    float m = Magnitude();
    if (m == 0.0f) return;

    float inv = 1.0f / m;
    m_x *= inv;
    m_y *= inv;
    m_z *= inv;
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
    float m = Magnitude();
    if (m == 0.0f) return Vec3(0,0,0);

    return (*this) / m;
}

float Vec3::Dot(const Vec3& a, const Vec3& b)
{
	return a.m_x * b.m_x + a.m_y * b.m_y + a.m_z * b.m_z;
}

Vec3 Vec3::CrossProduct(const Vec3& a, const Vec3& b)
{
	return Vec3(a.m_y * b.m_z - b.m_y * a.m_z, a.m_z * b.m_x - b.m_z * a.m_x, a.m_x * b.m_y - b.m_x * a.m_y);
}

Vec3 Vec3::Lerp(const Vec3& v, const Vec3& v2, float t)
{
	return v + (v2 - v) * t;
}

Vec3 Vec3::Slerp(const Vec3& v, const Vec3& v2, float t, bool longPath)
{
	float vMagnitudeSquared = v.MagnitudeSquared();
	float v2MagnitudeSquared = v2.MagnitudeSquared();
	float magnitudeSquared = vMagnitudeSquared + (v2MagnitudeSquared - vMagnitudeSquared) * t;

	Vec3 vNorm = v.Normalized();
	Quat q = Quat::SetGoToRotation(vNorm, v2.Normalized());
	Vec3 Axis = q.GetAxis();
	float angle = q.GetAngle();
	angle = longPath ? -360 + angle : angle;

	Vec3 slerpDirection = vNorm * sqrt(magnitudeSquared);
	Quat rotateQuat = Quat::AxisAngle(Axis, angle * t);
	
	return rotateQuat * slerpDirection;
}

Vec3 Vec3::Orthogonal(const Vec3& v)
{
	Vec3 orthogonal;

	if (abs(v.m_x) < abs(v.m_y) && abs(v.m_x) < abs(v.m_z))
	{
		orthogonal = Vec3(0, -v.m_z, v.m_y);
	}
	else if (abs(v.m_y) < abs(v.m_z))
	{
		orthogonal = Vec3(-v.m_z, 0, v.m_x);
	}
	else
	{
		orthogonal = Vec3(-v.m_y, v.m_x, 0);
	}

	orthogonal = orthogonal.Normalized();
	return orthogonal;
}

std::ostream& operator<<(std::ostream& os, const Vec3& value)
{
	os << "(X : " << value.m_x << ", Y : " << value.m_y << ", Z : " << value.m_z << ")" << std::endl;
	return os;
}
