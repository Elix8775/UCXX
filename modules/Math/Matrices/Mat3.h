// Mat3 (header)
// Author: Elix8775

#ifndef UCXX_MATH_MATRICES_MAT3_H
#define UCXX_MATH_MATRICES_MAT3_H

#include <ostream>
#include <math.h>
#include "../Vectors/Vec2.h"
#include "../Vectors/Vec3.h"
#include <array>
struct Mat3
{
public:
	float m[3][3];

	Mat3();
	Mat3(float m00, float m01, float m02,
			  float m10, float m11, float m12,
			  float m20, float m21, float m22);
	
	Mat3(const Mat3& value);

	float& operator ()(int i, int j);
	const float& operator ()(int i, int j)const;

	Mat3& operator +=(const Mat3& b);
	Mat3& operator -=(const Mat3& b);
	Mat3& operator *=(const float& s);
	Mat3& operator *=(const Mat3& b);
	Mat3& operator=(const Mat3& value);
	bool operator==(const Mat3& value)const;
	bool operator!=(const Mat3& value)const;

	Mat3 Transpose()const;
	Mat3 Inverse()const;
	float Determinant()const;

	static Mat3 Identity();
	static Mat3 Translate(const Vec2& translate);
	static Mat3 RotateZ(const float& angle);
	static Mat3 ScaleXY(const Vec2& scale);

	static Mat3 TS(const Vec2& translate, const Vec2& scale);
	static Mat3 RS(const float& angle, const Vec2& scale);
	static Mat3 TR(const Vec2& translate, const float& angle);
	static Mat3 TRS(const Vec2& translate, const float& angle, const Vec2& scale);
	std::array<float, 9> GetAsArray() const;
};
Mat3 operator +(const Mat3& a, const Mat3& b);
Mat3 operator -(const Mat3& a, const Mat3& b);
Mat3 operator *(const Mat3& a, const float& s);
Mat3 operator *(const float& s, const Mat3& a);
Mat3 operator *(const Mat3& a, const Mat3& b);
std::ostream& operator<<(std::ostream& os, const Mat3& value);

Vec2 operator*(const Mat3& a, const Vec2& b);
Vec2 operator*(const Vec2& b, const Mat3& a);
Vec3 operator*(const Mat3& a, const Vec3& b);
Vec3 operator*(const Vec3& b, const Mat3& a);


#endif