// Main function Quat.cpp
// Author: Elix8775

#include "Quat.h"
#include "../Mathf/Mathf.h"
#include "../Matrices/Mat4.h"
#include <cmath>

Quat::Quat()
{
    m_w = 1.0f;
    m_x = 0.0f;
    m_y = 0.0f;
    m_z = 0.0f;
}

Quat::Quat(float w, float x, float y, float z)
{
    m_w = w;
    m_x = x;
    m_y = y;
    m_z = z;
}

Quat::Quat(const Vec3& axis, float angle)
{
    float halfAngle = angle * Mathf::DegToRad / 2.0f;
    m_w = cosf(halfAngle);
    m_x = sinf(halfAngle) * axis.m_x;
    m_y = sinf(halfAngle) * axis.m_y;
    m_z = sinf(halfAngle) * axis.m_z;
}

Quat::Quat(const Vec3& eulerAngles, EulerAngleMode eulerAngleMode, bool intrinsectRotation)
{
    float angleX = eulerAngles.m_x;
    float angleY = eulerAngles.m_y;
    float angleZ = eulerAngles.m_z;
    Vec3 axeX = Vec3::Right;
    Vec3 axeY = Vec3::Up;
    Vec3 axeZ = Vec3::Forward;
    EulerAxesAngles eulerAxesAngles = EulerAxesAngles();

    switch (eulerAngleMode)
    {
    case EulerAngleMode::XYZ:
        eulerAxesAngles = EulerAxesAngles(angleX, angleY, angleZ, axeX, axeY, axeZ);
        break;
    case EulerAngleMode::XZY:
        eulerAxesAngles = EulerAxesAngles(angleX, angleZ, angleY, axeX, axeZ, axeY);
        break;
    case EulerAngleMode::YXZ:
        eulerAxesAngles = EulerAxesAngles(angleY, angleX, angleZ, axeY, axeX, axeZ);
        break;
    case EulerAngleMode::YZX:
        eulerAxesAngles = EulerAxesAngles(angleY, angleZ, angleX, axeY, axeZ, axeX);
        break;
    case EulerAngleMode::ZYX:
        eulerAxesAngles = EulerAxesAngles(angleZ, angleY, angleX, axeZ, axeY, axeX);
        break;
    case EulerAngleMode::ZXY:
        eulerAxesAngles = EulerAxesAngles(angleZ, angleX, angleY, axeZ, axeX, axeY);
        break;
    case EulerAngleMode::XYX:
        eulerAxesAngles = EulerAxesAngles(angleX, angleY, angleZ, axeX, axeY, axeX);
        break;
    case EulerAngleMode::YXY:
        eulerAxesAngles = EulerAxesAngles(angleX, angleY, angleZ, axeY, axeX, axeY);
        break;
    case EulerAngleMode::ZYZ:
        eulerAxesAngles = EulerAxesAngles(angleX, angleY, angleZ, axeZ, axeY, axeZ);
        break;
    case EulerAngleMode::YZY:
        eulerAxesAngles = EulerAxesAngles(angleX, angleY, angleZ, axeY, axeZ, axeY);
        break;
    case EulerAngleMode::XZX:
        eulerAxesAngles = EulerAxesAngles(angleX, angleY, angleZ, axeX, axeZ, axeX);
        break;
    case EulerAngleMode::ZXZ:
        eulerAxesAngles = EulerAxesAngles(angleX, angleY, angleZ, axeZ, axeX, axeZ);
        break;
    default:
        break;
    }

    Quat angleAxis1 = Quat::AxisAngle(eulerAxesAngles.m_firstAxis, eulerAxesAngles.m_angle1);
    Quat angleAxis2 = Quat::AxisAngle(eulerAxesAngles.m_secondAxis, eulerAxesAngles.m_angle2);
    Quat angleAxis3 = Quat::AxisAngle(eulerAxesAngles.m_thirdAxis, eulerAxesAngles.m_angle3);

    Quat angleAxisResult;
    
    if(!intrinsectRotation)
        angleAxisResult = angleAxis3 * angleAxis2 * angleAxis1;
    else 
        angleAxisResult = angleAxis1 * angleAxis2 * angleAxis3;

    *this = angleAxisResult;

}

void Quat::Normalize()
{
    float lenSq = LengthSquared();
    if (fabsf(lenSq) < Mathf::Epsilon7)
    {
        *this = Identity();
        return;
    }
    float invLen = 1.0f / sqrtf(lenSq);
    m_w *= invLen;
    m_x *= invLen;
    m_y *= invLen;
    m_z *= invLen;
}

Quat Quat::Normalized() const
{
    float lenSq = LengthSquared();
    if (fabsf(lenSq) < Mathf::Epsilon7)
        return Identity();

    float invLen = 1.0f / sqrtf(lenSq);
    return Quat(m_w * invLen, m_x * invLen, m_y * invLen, m_z * invLen);
}

Quat Quat::Inverse() const
{
    float lenSq = LengthSquared();
    if (fabsf(lenSq) < Mathf::Epsilon7)
        return Identity();

    float invLenSq = 1.0f / lenSq;
    return Quat(m_w * invLenSq, -m_x * invLenSq, -m_y * invLenSq, -m_z * invLenSq);
}

float Quat::Length() const
{
    float lenSq = LengthSquared();
    if (fabsf(lenSq) < Mathf::Epsilon7)
        return 0.0f;
    return sqrtf(lenSq);
}

float Quat::LengthSquared() const
{
    return m_w * m_w + m_x * m_x + m_y * m_y + m_z * m_z;
}

bool Quat::IsIdentity(float tolerance) const
{
    return fabsf(m_x) <= tolerance &&
           fabsf(m_y) <= tolerance &&
           fabsf(m_z) <= tolerance &&
           fabsf(m_w - 1.0f) <= tolerance;
}

bool Quat::IsNormalized(float tolerance) const
{
    return fabsf(LengthSquared() - 1.0f) <= tolerance;
}

Vec3 Quat::GetForwardDirection() const
{
    return RotateVec3(Vec3::Forward);
}

Vec3 Quat::GetRightDirection() const
{
    return RotateVec3(Vec3::Right);
}

Vec3 Quat::GetUpDirection() const
{
    return RotateVec3(Vec3::Up);
}

Vec3 Quat::RotateVec3(const Vec3& v) const
{
    Vec3 q(m_x, m_y, m_z);
    Vec3 qv = Vec3::CrossProduct(q, v);
    return v + qv * 2.0f * m_w + Vec3::CrossProduct(q, qv) * 2.0f;
}

void Quat::Rotate(const Vec3& axis, float angle, bool inWorld)
{
    Quat q = Quat::AxisAngle(axis, angle);
    *this = inWorld ? q * *this : *this * q;
}

void Quat::Rotate(const Quat& q, bool inWorld)
{
    *this = inWorld ? q * *this : *this * q;
}

void Quat::GoToRotation(const Vec3& fromDirection, const Vec3& toDirection)
{
    float cosAngle = Vec3::Dot(fromDirection, toDirection);
    if (cosAngle >= 1.0f - Mathf::Epsilon7)
        return;

    Vec3 axis;
    float angle;
    if (cosAngle <= -1.0f + Mathf::Epsilon7)
    {
        axis = Vec3::Orthogonal(fromDirection);
        angle = 180.0f;
    }
    else
    {
        axis = Vec3::CrossProduct(fromDirection, toDirection).Normalized();
        angle = acosf(std::max(-1.0f, std::min(1.0f, cosAngle))) * Mathf::RadToDeg;
    }
    Rotate(axis, angle, true);
}

void Quat::GoToRotation(const Vec3& fromDirection, const Vec3& toDirection, const Vec3& orthogonalDirection)
{
    float cosAngle = Vec3::Dot(fromDirection, toDirection);
    if (cosAngle >= 1.0f - Mathf::Epsilon7)
        return;

    Vec3 axis;
    float angle;
    if (cosAngle <= -1.0f + Mathf::Epsilon7)
    {
        axis = orthogonalDirection;
        angle = 180.0f;
    }
    else
    {
        axis = Vec3::CrossProduct(fromDirection, toDirection).Normalized();
        angle = acosf(std::max(-1.0f, std::min(1.0f, cosAngle))) * Mathf::RadToDeg;
    }
    Rotate(axis, angle, true);
}

Vec3 Quat::ToEulerAngle() const
{
    Vec3 angles;

    float sinr_cosp = 2.0f * (m_w * m_x + m_y * m_z);
    float cosr_cosp = 1.0f - 2.0f * (m_x * m_x + m_y * m_y);
    angles.m_x = atan2f(sinr_cosp, cosr_cosp);

    float sinp = 2.0f * (m_w * m_y - m_z * m_x);
    angles.m_y = fabsf(sinp) >= 1.0f
        ? std::copysign(Mathf::PI / 2.0f, sinp)
        : asinf(sinp);

    float siny_cosp = 2.0f * (m_w * m_z + m_x * m_y);
    float cosy_cosp = 1.0f - 2.0f * (m_y * m_y + m_z * m_z);
    angles.m_z = atan2f(siny_cosp, cosy_cosp);

    return angles * Mathf::RadToDeg;
}

float Quat::GetAngle() const
{
    return acosf(std::max(-1.0f, std::min(1.0f, m_w))) * 2.0f * Mathf::RadToDeg;
}

Vec3 Quat::GetAxis() const
{
    if (fabsf(m_w) >= 1.0f - Mathf::Epsilon7)
        return Vec3(0.0f, 0.0f, 0.0f);

    float halfAngle = acosf(std::max(-1.0f, std::min(1.0f, m_w)));
    float sinHalfAngle = sinf(halfAngle);
    return Vec3(m_x / sinHalfAngle, m_y / sinHalfAngle, m_z / sinHalfAngle);
}

void Quat::ToAxisAngle(Vec3& axis, float& angle) const
{
    axis  = GetAxis();
    angle = GetAngle();
}

Mat4 Quat::ToMat4() const
{
    return Mat4::Rotate(*this);
}

Quat Quat::Identity()
{
    return Quat(1.0f, 0.0f, 0.0f, 0.0f);
}

float Quat::DotProduct(const Quat& a, const Quat& b)
{
    return a.m_w * b.m_w + a.m_x * b.m_x + a.m_y * b.m_y + a.m_z * b.m_z;
}

Quat Quat::FromEulerAngle(const Vec3& eulerAngle, EulerAngleMode eulerAngleMode)
{
    return Quat(eulerAngle, eulerAngleMode);
}

Quat Quat::AxisAngle(const Vec3& axis, float angle)
{
    return Quat(axis, angle);
}

Quat Quat::SetGoToRotation(const Vec3& fromDirection, const Vec3& toDirection)
{
    Quat q = Quat::Identity();
    q.GoToRotation(fromDirection, toDirection);
    return q;
}

Quat Quat::LookRotation(const Vec3& forward, const Vec3& up)
{
    float cosAngle = Vec3::Dot(forward, up);
    if (cosAngle >= 1.0f - Mathf::Epsilon7)
        return SetGoToRotation(Vec3::Forward, forward);

    Vec3 tmpUp = up;
    if (cosAngle <= -1.0f + Mathf::Epsilon7)
    {
        tmpUp = Vec3::Orthogonal(forward);
    }
    else
    {
        Vec3 right = Vec3::CrossProduct(up, forward).Normalized();
        tmpUp = Vec3::CrossProduct(forward, right).Normalized();
    }

    Quat q = SetGoToRotation(Vec3::Forward, forward);
    Quat q2 = SetGoToRotation(q.GetUpDirection(), tmpUp);
    q.Rotate(q2, true);
    return q;
}

Quat Quat::Lerp(const Quat& a, const Quat& b, float t, bool longPath)
{
    float dot  = Quat::DotProduct(a, b);
    float bias = (!longPath) == (dot >= 0.0f) ? 1.0f : -1.0f;
    return a + (b * bias - a) * t;
}

Quat Quat::LerpNormalized(const Quat& a, const Quat& b, float t, bool longPath)
{
    return Lerp(a, b, t, longPath).Normalized();
}

Quat Quat::Slerp(const Quat& a, const Quat& b, float t, bool longPath)
{
    float dot  = Mathf::Clamp(Quat::DotProduct(a, b), -1.0f, 1.0f);
    float bias = (!longPath) == (dot >= 0.0f) ? 1.0f : -1.0f;
    float dotBias = dot * bias;

    if (dotBias > 1.0f - Mathf::Epsilon7)
        return Lerp(a, b, t, longPath);

    float angle    = acosf(dotBias);
    float sinAngle = sinf(angle);
    float s0 = sinf((1.0f - t) * angle) / sinAngle;
    float s1 = sinf(t * angle)           / sinAngle;

    return (a * s0) + (b * bias * s1);
}

Quat Quat::SlerpNormalized(const Quat& a, const Quat& b, float t, bool longPath)
{
    return Slerp(a, b, t, longPath).Normalized();
}

Quat Quat::operator+(const Quat& q) const
{
    return Quat(m_w + q.m_w, m_x + q.m_x, m_y + q.m_y, m_z + q.m_z);
}

Quat Quat::operator-(const Quat& q) const
{
    return Quat(m_w - q.m_w, m_x - q.m_x, m_y - q.m_y, m_z - q.m_z);
}

Quat Quat::operator*(const Quat& q) const
{
    return Quat(
        m_w * q.m_w - m_x * q.m_x - m_y * q.m_y - m_z * q.m_z,
        m_w * q.m_x + m_x * q.m_w + m_y * q.m_z - m_z * q.m_y,
        m_w * q.m_y - m_x * q.m_z + m_y * q.m_w + m_z * q.m_x,
        m_w * q.m_z + m_x * q.m_y - m_y * q.m_x + m_z * q.m_w
    );
}

Quat Quat::operator*(float scale) const
{
    return Quat(m_w * scale, m_x * scale, m_y * scale, m_z * scale);
}

Quat Quat::operator/(float scale) const
{
    return Quat(m_w / scale, m_x / scale, m_y / scale, m_z / scale);
}

Quat Quat::operator/(const Quat& q) const
{
    return *this * q.Inverse();
}

Quat& Quat::operator+=(const Quat& q)
{
    m_w += q.m_w; m_x += q.m_x; m_y += q.m_y; m_z += q.m_z;
    return *this;
}

Quat& Quat::operator-=(const Quat& q)
{
    m_w -= q.m_w; m_x -= q.m_x; m_y -= q.m_y; m_z -= q.m_z;
    return *this;
}

Quat& Quat::operator*=(const Quat& q)
{
    *this = *this * q;
    return *this;
}

Quat& Quat::operator*=(float scale)
{
    m_w *= scale; m_x *= scale; m_y *= scale; m_z *= scale;
    return *this;
}

Quat& Quat::operator/=(float scale)
{
    *this = *this / scale;
    return *this;
}

Quat& Quat::operator/=(const Quat& q)
{
    *this = *this * q.Inverse();
    return *this;
}

Vec3 Quat::operator*(const Vec3& v) const
{
    return RotateVec3(v);
}

bool Quat::operator==(const Quat& q) const
{
    return fabsf(m_w - q.m_w) < Mathf::Epsilon7 &&
           fabsf(m_x - q.m_x) < Mathf::Epsilon7 &&
           fabsf(m_y - q.m_y) < Mathf::Epsilon7 &&
           fabsf(m_z - q.m_z) < Mathf::Epsilon7;
}

bool Quat::operator!=(const Quat& q) const
{
    return !(*this == q);
}

std::ostream& operator<<(std::ostream& os, const Quat& value)
{
    os << "(W : " << value.m_w << ", X : " << value.m_x
       << ", Y : " << value.m_y << ", Z : " << value.m_z << ")\n";
    return os;
}