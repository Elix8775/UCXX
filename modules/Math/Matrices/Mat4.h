#ifndef UCXX_MATH_MATRICES_MAT4_H
#define UCXX_MATH_MATRICES_MAT4_H

#include <ostream>
#include <array>
#include <cfloat>
#include "../Vectors/Vec2.h"
#include "../Vectors/Vec3.h"
#include "../Vectors/Vec4.h"
#include "../Quaternion/Quat.h"
#include "Mat3.h"

struct Quat;

struct Mat4
{
public:
    float m[4][4];

    Mat4();
    Mat4(float m00, float m01, float m02, float m03,
         float m10, float m11, float m12, float m13,
         float m20, float m21, float m22, float m23,
         float m30, float m31, float m32, float m33);
    Mat4(const Vec3& a, const Vec3& b, const Vec3& c);
    Mat4(const Vec4& a, const Vec4& b, const Vec4& c, const Vec4& d);
    Mat4(const Mat4& value);
    Mat4& operator=(const Mat4& value) = default;

    float& operator()(int i, int j);
    const float& operator()(int i, int j) const;

    Mat4& operator+=(const Mat4& b);
    Mat4& operator-=(const Mat4& b);
    Mat4& operator*=(const float& s);
    Mat4& operator*=(const Mat4& b);
    bool operator==(const Mat4& value) const;
    bool operator!=(const Mat4& value) const;

    operator Mat3() const;

    Mat4 Transpose() const;
    Mat4 Inverse() const;
    float Determinant() const;

    static Mat4 Identity();
    static Mat4 Translate(const Vec3& translate);
    static Mat4 RotateX(const float& angle);
    static Mat4 RotateY(const float& angle);
    static Mat4 RotateZ(const float& angle);
    static Mat4 Rotate(const Vec3& angles);
    static Mat4 Rotate(const Quat& q);
    static Mat4 ScaleXYZ(const Vec3& scale);
    static Mat4 TS(const Vec3& translate, const Vec3& scale);
    static Mat4 RS(const Quat& rotation, const Vec3& scale);
    static Mat4 TR(const Vec3& translate, const Quat& rotation);
    static Mat4 TRS(const Vec3& translate, const Quat& rotation, const Vec3& scale);

    static Mat4 Orthographic(float left, float right, float bottom, float top, float near, float far);
    static Mat4 Perspective(float left, float right, float bottom, float top, float near, float far);
    static Mat4 Perspective(float fov, float aspect, float near, float far);
    static Mat4 InfinitePerspective(float left, float right, float bottom, float top, float near, float epsilon);
    static Mat4 PerspectiveReverseZ(float left, float right, float bottom, float top, float near, float far);
    static Mat4 InfinitePerspectiveReverseZ(float left, float right, float bottom, float top, float near, float epsilon);
    static Mat4 PerspectiveDepthZeroToOne(float left, float right, float bottom, float top, float near, float far);
    static Mat4 InfinitePerspectiveDepthZeroToOne(float left, float right, float bottom, float top, float near, float epsilon);
    static Mat4 PerspectiveReverseZDepthZeroToOne(float left, float right, float bottom, float top, float near, float far);
    static Mat4 InfinitePerspectiveReverseZDepthZeroToOne(float left, float right, float bottom, float top, float near, float epsilon);

    std::array<float, 16> GetAsArray() const;
};

Mat4 operator+(const Mat4& a, const Mat4& b);
Mat4 operator-(const Mat4& a, const Mat4& b);
Mat4 operator*(const Mat4& a, const float& s);
Mat4 operator*(const float& s, const Mat4& a);
Mat4 operator*(const Mat4& a, const Mat4& b);
std::ostream& operator<<(std::ostream& os, const Mat4& value);

Vec3 operator*(const Mat4& a, const Vec3& b);
Vec3 operator*(const Vec3& b, const Mat4& a);
Vec4 operator*(const Mat4& a, const Vec4& b);
Vec4 operator*(const Vec4& b, const Mat4& a);

#endif