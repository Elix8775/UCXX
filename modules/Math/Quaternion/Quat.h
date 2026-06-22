#ifndef UCXX_MATH_QUATERNION_H
#define UCXX_MATH_QUATERNION_H

#include <ostream>
#include "../Vectors/Vec3.h"
#include "../Vectors/Vec2.h"
#include "../Mathf/Mathf.h"

struct Mat4;

struct Quat
{
    struct EulerAxesAngles
    {
        float m_angle1;
        float m_angle2;
        float m_angle3;
        Vec3 m_firstAxis;
        Vec3 m_secondAxis;
        Vec3 m_thirdAxis;

        EulerAxesAngles()
        {
            m_angle1 = 0.0f;
            m_angle2 = 0.0f;
            m_angle3 = 0.0f;
        }

        EulerAxesAngles(float angle1, float angle2, float angle3,
                        Vec3 firstAxis, Vec3 secondAxis, Vec3 thirdAxis)
        {
            m_angle1 = angle1;
            m_angle2 = angle2;
            m_angle3 = angle3;
            m_firstAxis  = firstAxis;
            m_secondAxis = secondAxis;
            m_thirdAxis  = thirdAxis;
        }
    };

    enum class EulerAngleMode
    {
        XYZ = 0,
        XZY = 1,
        YXZ = 2,
        YZX = 3,
        ZYX = 4,
        ZXY = 5,
        XYX = 6,
        YXY = 7,
        ZYZ = 8,
        YZY = 9,
        XZX = 10,
        ZXZ = 11,
    };

    float m_w;
    float m_x;
    float m_y;
    float m_z;

    Quat();
    Quat(const Quat& value) = default;
    Quat& operator=(const Quat& value) = default;
    Quat(float w, float x, float y, float z);
    Quat(const Vec3& axis, float angle);
    Quat(const Vec3& eulerAngles, EulerAngleMode eulerAngleMode = EulerAngleMode::XYZ, bool intrinsicRotation = false);

    void Normalize();
    Quat Normalized() const;
    Quat Inverse() const;
    float Length() const;
    float LengthSquared() const;
    bool IsIdentity(float tolerance = Mathf::Epsilon7) const;
    bool IsNormalized(float tolerance = Mathf::Epsilon7) const;
    Vec3 GetForwardDirection() const;
    Vec3 GetRightDirection() const;
    Vec3 GetUpDirection() const;
    Vec3 RotateVec3(const Vec3& v) const;
    void Rotate(const Vec3& axis, float angle, bool inWorld = true);
    void Rotate(const Quat& q, bool inWorld = true);
    void GoToRotation(const Vec3& fromDirection, const Vec3& toDirection);
    void GoToRotation(const Vec3& fromDirection, const Vec3& toDirection, const Vec3& orthogonalDirection);
    Vec3 ToEulerAngle() const;
    float GetAngle() const;
    Vec3 GetAxis() const;
    void ToAxisAngle(Vec3& axis, float& angle) const;
    Mat4 ToMat4() const;

    static Quat Identity();
    static float DotProduct(const Quat& a, const Quat& b);
    static Quat FromEulerAngle(const Vec3& eulerAngle, EulerAngleMode eulerAngleMode = EulerAngleMode::XYZ);
    static Quat AxisAngle(const Vec3& axis, float angle);
    static Quat SetGoToRotation(const Vec3& fromDirection, const Vec3& toDirection);
    static Quat LookRotation(const Vec3& forward, const Vec3& up);
    static Quat Lerp(const Quat& a, const Quat& b, float t, bool longPath = false);
    static Quat LerpNormalized(const Quat& a, const Quat& b, float t, bool longPath = false);
    static Quat Slerp(const Quat& a, const Quat& b, float t, bool longPath = false);
    static Quat SlerpNormalized(const Quat& a, const Quat& b, float t, bool longPath = false);

    Quat operator+(const Quat& q) const;
    Quat operator-(const Quat& q) const;
    Quat operator*(const Quat& q) const;
    Quat operator*(float scale) const;
    Quat operator/(float scale) const;
    Quat operator/(const Quat& q) const;
    Quat& operator+=(const Quat& q);
    Quat& operator-=(const Quat& q);
    Quat& operator*=(const Quat& q);
    Quat& operator*=(float scale);
    Quat& operator/=(float scale);
    Quat& operator/=(const Quat& q);
    Vec3 operator*(const Vec3& v) const;
    bool operator==(const Quat& q) const;
    bool operator!=(const Quat& q) const;
};

std::ostream& operator<<(std::ostream& os, const Quat& value);

#endif