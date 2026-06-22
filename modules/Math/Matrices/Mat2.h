// Mat2 (header)
// Author: Elix8775

#ifndef UCXX_MATH_MATRICES_MAT2_H
#define UCXX_MATH_MATRICES_MAT2_H

#include "../../Vectors/Vec2.h"
#include <ostream>

struct Mat2
{
public:
	float m[2][2];

	Mat2();
	Mat2(float m00, float m01,
		 float m10, float m11);

	Mat2(const Vec2& a, const Vec2& b);
	Mat2(const Mat2& value);

	float& operator ()(int i, int j);
	const float& operator ()(int i, int j)const;

	Mat2& operator +=(const Mat2& b);
	Mat2& operator -=(const Mat2& b);
	Mat2& operator *=(const float& s);
	Mat2& operator *=(const Mat2& b);
	bool operator==(const Mat2& value)const;
	bool operator!=(const Mat2& value)const;
	Mat2 Transpose()const;
	Mat2 Inverse()const;
	float Determinant()const;

	static Mat2 Identity();
	static Mat2 Rotate(const float& angle);
	static Mat2 Scale(const Vec2& scale);
	static Mat2 RS(const float& angle, const Vec2& scale);
};

Mat2 operator +(const Mat2& a, const Mat2& b);
Mat2 operator -(const Mat2& a, const Mat2& b);
Mat2 operator *(const Mat2& a, const float& s);
Mat2 operator *(const float& s, const Mat2& a);
Mat2 operator *(const Mat2& a, const Mat2& b);
std::ostream& operator<<(std::ostream& os, const Mat2& value);

Vec2 operator*(const Mat2& a, const Vec2& b);
Vec2 operator*(const Vec2& b, const Mat2& a);

#endif
