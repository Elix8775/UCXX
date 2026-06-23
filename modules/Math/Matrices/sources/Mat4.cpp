// Main function Mat4.cpp
// Author: Elix8775

#include "../Mat4.h"
#include "../Mat3.h"
# define M_PI           3.14159265358979323846

Mat4::Mat4()
{
	m[0][0] = 0.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; ; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = 0.0f; m[1][2] = 0.0f; ; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 0.0f; ; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; ; m[3][3] = 0.0f;
}

Mat4::Mat4(float m00, float m01, float m02, float m03,
	float m10, float m11, float m12, float m13,
	float m20, float m21, float m22, float m23,
	float m30, float m31, float m32, float m33)
{
	m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
	m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
	m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
	m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
}

Mat4::Mat4(const Vec3& a, const Vec3& b, const Vec3& c)
{
	m[0][0] = a.m_x; m[0][1] = b.m_x; m[0][2] = c.m_x; m[0][3] = 0.0f;
	m[1][0] = a.m_y; m[1][1] = b.m_y; m[1][2] = c.m_y; m[1][3] = 0.0f;
	m[2][0] = a.m_z; m[2][1] = b.m_z; m[2][2] = c.m_z; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
}

Mat4::Mat4(const Vec4& a, const Vec4& b, const Vec4& c, const Vec4& d)
{
	m[0][0] = a.m_x; m[0][1] = b.m_x; m[0][2] = c.m_x; m[0][3] = d.m_x;
	m[1][0] = a.m_y; m[1][1] = b.m_y; m[1][2] = c.m_y; m[1][3] = d.m_y;
	m[2][0] = a.m_z; m[2][1] = b.m_z; m[2][2] = c.m_z; m[2][3] = d.m_z;
	m[3][0] = a.m_w; m[3][1] = b.m_w; m[3][2] = c.m_w; m[3][3] = d.m_w;
}

Mat4::Mat4(const Mat4& value)
{
	m[0][0] = value.m[0][0];
	m[0][1] = value.m[0][1];
	m[0][2] = value.m[0][2];
	m[0][3] = value.m[0][3];

	m[1][0] = value.m[1][0];
	m[1][1] = value.m[1][1];
	m[1][2] = value.m[1][2];
	m[1][3] = value.m[1][3];

	m[2][0] = value.m[2][0];
	m[2][1] = value.m[2][1];
	m[2][2] = value.m[2][2];
	m[2][3] = value.m[2][3];

	m[3][0] = value.m[3][0];
	m[3][1] = value.m[3][1];
	m[3][2] = value.m[3][2];
	m[3][3] = value.m[3][3];
}


float& Mat4::operator ()(int i, int j)
{
	return m[i][j];
}

const float& Mat4::operator ()(int i, int j)const
{
	return m[i][j];
}

Mat4& Mat4::operator +=(const Mat4& b)
{
	m[0][0] += b.m[0][0];
	m[0][1] += b.m[0][1];
	m[0][2] += b.m[0][2];
	m[0][3] += b.m[0][3];

	m[1][0] += b.m[1][0];
	m[1][1] += b.m[1][1];
	m[1][2] += b.m[1][2];
	m[1][3] += b.m[1][3];

	m[2][0] += b.m[2][0];
	m[2][1] += b.m[2][1];
	m[2][2] += b.m[2][2];
	m[2][3] += b.m[2][3];

	m[3][0] += b.m[3][0];
	m[3][1] += b.m[3][1];
	m[3][2] += b.m[3][2];
	m[3][3] += b.m[3][3];

	return (*this);
}

Mat4& Mat4::operator -=(const Mat4& b)
{
	m[0][0] -= b.m[0][0];
	m[0][1] -= b.m[0][1];
	m[0][2] -= b.m[0][2];
	m[0][3] -= b.m[0][3];

	m[1][0] -= b.m[1][0];
	m[1][1] -= b.m[1][1];
	m[1][2] -= b.m[1][2];
	m[1][3] -= b.m[1][3];

	m[2][0] -= b.m[2][0];
	m[2][1] -= b.m[2][1];
	m[2][2] -= b.m[2][2];
	m[2][3] -= b.m[2][3];

	m[3][0] -= b.m[3][0];
	m[3][1] -= b.m[3][1];
	m[3][2] -= b.m[3][2];
	m[3][3] -= b.m[3][3];

	return (*this);
}

Mat4& Mat4::operator *=(const float& s)
{
	m[0][0] *= s;
	m[0][1] *= s;
	m[0][2] *= s;
	m[0][3] *= s;

	m[1][0] *= s;
	m[1][1] *= s;
	m[1][2] *= s;
	m[1][3] *= s;

	m[2][0] *= s;
	m[2][1] *= s;
	m[2][2] *= s;
	m[2][3] *= s;

	m[3][0] *= s;
	m[3][1] *= s;
	m[3][2] *= s;
	m[3][3] *= s;

	return (*this);
}

Mat4& Mat4::operator *=(const Mat4& b)
{
	Mat4 result;

	result.m[0][0] = m[0][0] * b.m[0][0] + m[0][1] * b.m[1][0] + m[0][2] * b.m[2][0] + m[0][3] * b.m[3][0];
	result.m[0][1] = m[0][0] * b.m[0][1] + m[0][1] * b.m[1][1] + m[0][2] * b.m[2][1] + m[0][3] * b.m[3][1];
	result.m[0][2] = m[0][0] * b.m[0][2] + m[0][1] * b.m[1][2] + m[0][2] * b.m[2][2] + m[0][3] * b.m[3][2];
	result.m[0][3] = m[0][0] * b.m[0][3] + m[0][1] * b.m[1][3] + m[0][2] * b.m[2][3] + m[0][3] * b.m[3][3];

	result.m[1][0] = m[1][0] * b.m[0][0] + m[1][1] * b.m[1][0] + m[1][2] * b.m[2][0] + m[1][3] * b.m[3][0];
	result.m[1][1] = m[1][0] * b.m[0][1] + m[1][1] * b.m[1][1] + m[1][2] * b.m[2][1] + m[1][3] * b.m[3][1];
	result.m[1][2] = m[1][0] * b.m[0][2] + m[1][1] * b.m[1][2] + m[1][2] * b.m[2][2] + m[1][3] * b.m[3][2];
	result.m[1][3] = m[1][0] * b.m[0][3] + m[1][1] * b.m[1][3] + m[1][2] * b.m[2][3] + m[1][3] * b.m[3][3];

	result.m[2][0] = m[2][0] * b.m[0][0] + m[2][1] * b.m[1][0] + m[2][2] * b.m[2][0] + m[2][3] * b.m[3][0];
	result.m[2][1] = m[2][0] * b.m[0][1] + m[2][1] * b.m[1][1] + m[2][2] * b.m[2][1] + m[2][3] * b.m[3][1];
	result.m[2][2] = m[2][0] * b.m[0][2] + m[2][1] * b.m[1][2] + m[2][2] * b.m[2][2] + m[2][3] * b.m[3][2];
	result.m[2][3] = m[2][0] * b.m[0][3] + m[2][1] * b.m[1][3] + m[2][2] * b.m[2][3] + m[2][3] * b.m[3][3];

	result.m[3][0] = m[3][0] * b.m[0][0] + m[3][1] * b.m[1][0] + m[3][2] * b.m[2][0] + m[3][3] * b.m[3][0];
	result.m[3][1] = m[3][0] * b.m[0][1] + m[3][1] * b.m[1][1] + m[3][2] * b.m[2][1] + m[3][3] * b.m[3][1];
	result.m[3][2] = m[3][0] * b.m[0][2] + m[3][1] * b.m[1][2] + m[3][2] * b.m[2][2] + m[3][3] * b.m[3][2];
	result.m[3][3] = m[3][0] * b.m[0][3] + m[3][1] * b.m[1][3] + m[3][2] * b.m[2][3] + m[3][3] * b.m[3][3];

	*this = result;
	return (*this);
}

Mat4 Mat4::Transpose() const
{
	return Mat4(m[0][0], m[1][0], m[2][0], m[3][0],
					 m[0][1], m[1][1], m[2][1], m[3][1],
					 m[0][2], m[1][2], m[2][2], m[3][2],
					 m[0][3], m[1][3], m[2][3], m[3][3]);
}

Mat4 Mat4::Inverse()const
{
	float determinant = Determinant();
	float epsilon = 1e-9;

	if (fabs(determinant) < epsilon)
	{
		throw std::invalid_argument("Matrix is singular (determinant is 0) and cannot be inverted.");
	}
	Mat3 subMatrix00 = Mat3(m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]);
	Mat3 subMatrix01 = Mat3(m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]);
	Mat3 subMatrix02 = Mat3(m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);
	Mat3 subMatrix03 = Mat3(m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);

	Mat3 subMatrix10 = Mat3(m[0][1], m[0][2], m[0][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]);
	Mat3 subMatrix11 = Mat3(m[0][0], m[0][2], m[0][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]);
	Mat3 subMatrix12 = Mat3(m[0][0], m[0][1], m[0][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);
	Mat3 subMatrix13 = Mat3(m[0][0], m[0][1], m[0][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);

	Mat3 subMatrix20 = Mat3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[3][1], m[3][2], m[3][3]);
	Mat3 subMatrix21 = Mat3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[3][0], m[3][2], m[3][3]);
	Mat3 subMatrix22 = Mat3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[3][0], m[3][1], m[3][3]);
	Mat3 subMatrix23 = Mat3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[3][0], m[3][1], m[3][2]);

	Mat3 subMatrix30 = Mat3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3]);
	Mat3 subMatrix31 = Mat3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3]);
	Mat3 subMatrix32 = Mat3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3]);
	Mat3 subMatrix33 = Mat3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2]);

	float C00 = powf(-1, 0 + 0) * subMatrix00.Determinant();
	float C01 = powf(-1, 0 + 1) * subMatrix01.Determinant();
	float C02 = powf(-1, 0 + 2) * subMatrix02.Determinant();
	float C03 = powf(-1, 0 + 3) * subMatrix03.Determinant();

	float C10 = powf(-1, 1 + 0) * subMatrix10.Determinant();
	float C11 = powf(-1, 1 + 1) * subMatrix11.Determinant();
	float C12 = powf(-1, 1 + 2) * subMatrix12.Determinant();
	float C13 = powf(-1, 1 + 3) * subMatrix13.Determinant();

	float C20 = powf(-1, 2 + 0) * subMatrix20.Determinant();
	float C21 = powf(-1, 2 + 1) * subMatrix21.Determinant();
	float C22 = powf(-1, 2 + 2) * subMatrix22.Determinant();
	float C23 = powf(-1, 2 + 3) * subMatrix23.Determinant();

	float C30 = powf(-1, 3 + 0) * subMatrix30.Determinant();
	float C31 = powf(-1, 3 + 1) * subMatrix31.Determinant();
	float C32 = powf(-1, 3 + 2) * subMatrix32.Determinant();
	float C33 = powf(-1, 3 + 3) * subMatrix33.Determinant();

	const Mat4 CofactorMatrix = Mat4(C00, C01, C02, C03,
		C10, C11, C12, C13,
		C20, C21, C22, C23,
		C30, C31, C32, C33);

	Mat4 adjugateMatrix = CofactorMatrix.Transpose();

	return (1.0f / determinant) * adjugateMatrix;
}

float Mat4::Determinant()const
{
	Mat3 subMatrix00 = Mat3(m[1][1], m[1][2], m[1][3],
									  m[2][1], m[2][2], m[2][3],
									  m[3][1], m[3][2], m[3][3]);

	Mat3 subMatrix01 = Mat3(m[1][0], m[1][2], m[1][3],
									  m[2][0], m[2][2], m[2][3],
									  m[3][0], m[3][2], m[3][3]);

	Mat3 subMatrix02 = Mat3(m[1][0], m[1][1], m[1][3],
									  m[2][0], m[2][1], m[2][3],
									  m[3][0], m[3][1], m[3][3]);

	Mat3 subMatrix03 = Mat3(m[1][0], m[1][1], m[1][2],
									  m[2][0], m[2][1], m[2][2],
									  m[3][0], m[3][1], m[3][2]);

	float determinant = m[0][0] * subMatrix00.Determinant() - m[0][1] * subMatrix01.Determinant()
		+ m[0][2] * subMatrix02.Determinant() - m[0][3] * subMatrix03.Determinant();

	return determinant;
}

Mat4 operator +(const Mat4& a, const Mat4& b)
{
	return Mat4(a.m[0][0] + b.m[0][0], a.m[0][1] + b.m[0][1], a.m[0][2] + b.m[0][2], a.m[0][3] + b.m[0][3],
					 a.m[1][0] + b.m[1][0], a.m[1][1] + b.m[1][1], a.m[1][2] + b.m[1][2], a.m[1][3] + b.m[1][3],
					 a.m[2][0] + b.m[2][0], a.m[2][1] + b.m[2][1], a.m[2][2] + b.m[2][2], a.m[2][3] + b.m[2][3],
					 a.m[3][0] + b.m[3][0], a.m[3][1] + b.m[3][1], a.m[3][2] + b.m[3][2], a.m[3][3] + b.m[3][3]);
}

Mat4 operator -(const Mat4& a, const Mat4& b)
{
	return Mat4(a.m[0][0] - b.m[0][0], a.m[0][1] - b.m[0][1], a.m[0][2] - b.m[0][2], a.m[0][3] - b.m[0][3],
		a.m[1][0] - b.m[1][0], a.m[1][1] - b.m[1][1], a.m[1][2] - b.m[1][2], a.m[1][3] - b.m[1][3],
		a.m[2][0] - b.m[2][0], a.m[2][1] - b.m[2][1], a.m[2][2] - b.m[2][2], a.m[2][3] - b.m[2][3],
		a.m[3][0] - b.m[3][0], a.m[3][1] - b.m[3][1], a.m[3][2] - b.m[3][2], a.m[3][3] - b.m[3][3]);
}

Mat4 operator *(const Mat4& a, const float& s)
{
	return Mat4(a.m[0][0] * s, a.m[0][1] * s, a.m[0][2] * s, a.m[0][3] * s,
					 a.m[1][0] * s, a.m[1][1] * s, a.m[1][2] * s, a.m[1][3] * s,
					 a.m[2][0] * s, a.m[2][1] * s, a.m[2][2] * s, a.m[2][3] * s,
					 a.m[3][0] * s, a.m[3][1] * s, a.m[3][2] * s, a.m[3][3] * s);
}

Mat4 operator *(const float& s, const Mat4& a)
{
	return Mat4(s * a.m[0][0], s * a.m[0][1], s * a.m[0][2], s * a.m[0][3],
					 s * a.m[1][0], s * a.m[1][1], s * a.m[1][2], s * a.m[1][3],
					 s * a.m[2][0], s * a.m[2][1], s * a.m[2][2], s * a.m[2][3],
					 s * a.m[3][0], s * a.m[3][1], s * a.m[3][2], s * a.m[3][3]);
}

Mat4 operator *(const Mat4& a, const Mat4& b)
{
	return Mat4(a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0] + a.m[0][2] * b.m[2][0] + a.m[0][3] * b.m[3][0],
					 a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1] + a.m[0][2] * b.m[2][1] + a.m[0][3] * b.m[3][1],
					 a.m[0][0] * b.m[0][2] + a.m[0][1] * b.m[1][2] + a.m[0][2] * b.m[2][2] + a.m[0][3] * b.m[3][2],
					 a.m[0][0] * b.m[0][3] + a.m[0][1] * b.m[1][3] + a.m[0][2] * b.m[2][3] + a.m[0][3] * b.m[3][3],

					 a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0] + a.m[1][2] * b.m[2][0] + a.m[1][3] * b.m[3][0],
					 a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1] + a.m[1][2] * b.m[2][1] + a.m[1][3] * b.m[3][1],
					 a.m[1][0] * b.m[0][2] + a.m[1][1] * b.m[1][2] + a.m[1][2] * b.m[2][2] + a.m[1][3] * b.m[3][2],
					 a.m[1][0] * b.m[0][3] + a.m[1][1] * b.m[1][3] + a.m[1][2] * b.m[2][3] + a.m[1][3] * b.m[3][3],

					 a.m[2][0] * b.m[0][0] + a.m[2][1] * b.m[1][0] + a.m[2][2] * b.m[2][0] + a.m[2][3] * b.m[3][0],
					 a.m[2][0] * b.m[0][1] + a.m[2][1] * b.m[1][1] + a.m[2][2] * b.m[2][1] + a.m[2][3] * b.m[3][1],
					 a.m[2][0] * b.m[0][2] + a.m[2][1] * b.m[1][2] + a.m[2][2] * b.m[2][2] + a.m[2][3] * b.m[3][2],
					 a.m[2][0] * b.m[0][3] + a.m[2][1] * b.m[1][3] + a.m[2][2] * b.m[2][3] + a.m[2][3] * b.m[3][3],

					 a.m[3][0] * b.m[0][0] + a.m[3][1] * b.m[1][0] + a.m[3][2] * b.m[2][0] + a.m[3][3] * b.m[3][0],
					 a.m[3][0] * b.m[0][1] + a.m[3][1] * b.m[1][1] + a.m[3][2] * b.m[2][1] + a.m[3][3] * b.m[3][1],
					 a.m[3][0] * b.m[0][2] + a.m[3][1] * b.m[1][2] + a.m[3][2] * b.m[2][2] + a.m[3][3] * b.m[3][2],
					 a.m[3][0] * b.m[0][3] + a.m[3][1] * b.m[1][3] + a.m[3][2] * b.m[2][3] + a.m[3][3] * b.m[3][3]);
}

bool Mat4::operator==(const Mat4& value) const
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (abs(m[i][j] - value.m[i][j]) > FLT_EPSILON)
				return false;
		}
	}
	return true;
}

bool Mat4::operator!=(const Mat4& value) const
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (abs(m[i][j] - value.m[i][j]) > FLT_EPSILON)
				return true;
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const Mat4& value)
{
	os << "(m00 : " << value.m[0][0] << ", m01 : " << value.m[0][1] << ", m02 : " << value.m[0][2] << ", m03 : " << value.m[0][3] << ")" << std::endl
		<< "(m10 : " << value.m[1][0] << ", m11 : " << value.m[1][1] << ", m12 : " << value.m[1][2] << ", m13 : " << value.m[1][3] << ")" << std::endl
		<< "(m20 : " << value.m[2][0] << ", m21 : " << value.m[2][1] << ", m22 : " << value.m[2][2] << ", m23 : " << value.m[2][3] << ")" << std::endl
		<< "(m30 : " << value.m[3][0] << ", m31 : " << value.m[3][1] << ", m32 : " << value.m[3][2] << ", m33 : " << value.m[3][3] << ")" << std::endl;
	return os;
}

Mat4 Mat4::Identity()
{
	return Mat4(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Mat4 Mat4::Translate(const Vec3& translate)
{
	return Mat4(1.0f, 0.0f,0.0f, translate.m_x,
		0.0f, 1.0f, 0.0f, translate.m_y,
		0.0f, 0.0f, 1.0f, translate.m_z,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Mat4 Mat4::RotateX(const float& angle)
{
	float angleInRadian = angle * M_PI / 180.0f;
	return Mat4(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, cosf(angleInRadian), -sinf(angleInRadian), 0.0f,
		0.0f, sinf(angleInRadian), cosf(angleInRadian), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Mat4 Mat4::RotateY(const float& angle)
{
	float angleInRadian = angle * M_PI / 180.0f;
	return Mat4(cosf(angleInRadian), 0.0f, sinf(angleInRadian), 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		-sinf(angleInRadian), 0.0f, cosf(angleInRadian), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}
Mat4 Mat4::RotateZ(const float& angle)
{
	float angleInRadian = angle * M_PI / 180.0f;
	return Mat4(cosf(angleInRadian), -sinf(angleInRadian), 0.0f,0.0f,
					 sinf(angleInRadian), cosf(angleInRadian), 0.0f,0.0f,
					 0.0f, 0.0f,1.0f, 0.0f,
					 0.0f, 0.0f, 0.0f, 1.0f);
}

Mat4 Mat4::Rotate(const Vec3& angles)
{
	return RotateZ(angles.m_z) * RotateY(angles.m_y) * RotateX(angles.m_x);
}

Mat4 Mat4::Rotate(const Quat& q)
{
	float m00 = 1.0f - 2.0f * q.m_y * q.m_y - 2.0f * q.m_z * q.m_z;
	float m01 = 2.0f * (q.m_x * q.m_y - q.m_w * q.m_z);
	float m02 = 2.0f * (q.m_x * q.m_z + q.m_w * q.m_y);

	float m10 = 2.0f * (q.m_x * q.m_y + q.m_w * q.m_z);
	float m11 = 1.0f - 2.0f * q.m_x * q.m_x - 2.0f * q.m_z * q.m_z;
	float m12 = 2.0f * (q.m_y * q.m_z - q.m_w * q.m_x);

	float m20 = 2.0f * (q.m_x * q.m_z - q.m_w * q.m_y);
	float m21 = 2.0f * (q.m_y * q.m_z + q.m_w * q.m_x);
	float m22 = 1.0f - 2.0f * q.m_x * q.m_x - 2.0f * q.m_y * q.m_y;

	return Mat4(m00, m01, m02, 0,
		m10, m11, m12, 0,
		m20, m21, m22, 0,
		0, 0, 0, 1);
}

Mat4 Mat4::ScaleXYZ(const Vec3& scale)
{
	return Mat4(scale.m_x, 0.0f, 0.0f,0.0f,
		0.0f, scale.m_y, 0.0f, 0.0f,
		0.0f, 0.0f, scale.m_z,0.0f,
		0.0f, 0.0f, 0.0f,1.0f);
}

Mat4 Mat4::TS(const Vec3& translate, const Vec3& scale)
{
	return Translate(translate) * ScaleXYZ(scale);
}

Mat4 Mat4::RS(const Quat& rotation, const Vec3& scale)
{
	return Rotate(rotation) * ScaleXYZ(scale);
}

Mat4 Mat4::TR(const Vec3& translate, const Quat& rotation)
{
	return Translate(translate) * Rotate(rotation);
}

Mat4 Mat4::TRS(const Vec3& translate, const Quat& rotation, const Vec3& scale)
{
	return Translate(translate) * Rotate(rotation) * ScaleXYZ(scale);
}

Vec3 operator*(const Mat4& a, const Vec3& b)
{
	return Vec3(a.m[0][0] * b.m_x + a.m[0][1] * b.m_y + a.m[0][2] * b.m_z + a.m[0][3] * 1.0f, 
					a.m[1][0] * b.m_x + a.m[1][1] * b.m_y + a.m[1][2] * b.m_z + a.m[1][3] * 1.0f,
					a.m[2][0] * b.m_x + a.m[2][1] * b.m_y + a.m[2][2] * b.m_z + a.m[2][3] * 1.0f);
}

Vec3 operator*(const Vec3& b, const Mat4& a)
{
	return Vec3(a.m[0][0] * b.m_x + a.m[0][1] * b.m_y + a.m[0][2] * b.m_z + a.m[0][3] * 1.0f,
		a.m[1][0] * b.m_x + a.m[1][1] * b.m_y + a.m[1][2] * b.m_z + a.m[1][3] * 1.0f,
		a.m[2][0] * b.m_x + a.m[2][1] * b.m_y + a.m[2][2] * b.m_z + a.m[2][3] * 1.0f);
}

Vec4 operator*(const Vec4& b, const Mat4& a)
{
	return Vec4(a.m[0][0] * b.m_x + a.m[0][1] * b.m_y + a.m[0][2] * b.m_z + a.m[0][3] * b.m_w,
					a.m[1][0] * b.m_x + a.m[1][1] * b.m_y + a.m[1][2] * b.m_z + a.m[1][3] * b.m_w,
					a.m[2][0] * b.m_x + a.m[2][1] * b.m_y + a.m[2][2] * b.m_z + a.m[2][3] * b.m_w,
					a.m[3][0] * b.m_x + a.m[3][1] * b.m_y + a.m[3][2] * b.m_z + a.m[3][3] * b.m_w);
}

Vec4 operator*(const Mat4& a, const Vec4& b)
{
	return Vec4(a.m[0][0] * b.m_x + a.m[0][1] * b.m_y + a.m[0][2] * b.m_z + a.m[0][3] * b.m_w,
		a.m[1][0] * b.m_x + a.m[1][1] * b.m_y + a.m[1][2] * b.m_z + a.m[1][3] * b.m_w,
		a.m[2][0] * b.m_x + a.m[2][1] * b.m_y + a.m[2][2] * b.m_z + a.m[2][3] * b.m_w,
		a.m[3][0] * b.m_x + a.m[3][1] * b.m_y + a.m[3][2] * b.m_z + a.m[3][3] * b.m_w);
}


std::array<float, 16> Mat4::GetAsArray() const
{
	return { m[0][0], m[0][1], m[0][2], m[0][3],
			 m[1][0], m[1][1], m[1][2], m[1][3],
			 m[2][0], m[2][1], m[2][2], m[2][3],
			 m[3][0], m[3][1], m[3][2], m[3][3],
	};
}

Mat4 Mat4::Orthographic(float left, float right, float bottom, float top, float near, float far)
{
	Mat4 ortho = Mat4(2.0f / (right - left), 0, 0, -(right + left) / (right - left),
								0, 2.0f / (top - bottom), 0, -(top + bottom) / (top - bottom),
								0, 0, -2.0f / (far - near), -(far + near) / (far - near),
								0,0,0,1);

	return ortho;
}
#include <iostream>

Mat4 Mat4::Perspective(float left, float right, float bottom, float top, float near, float far)
{
	Mat4 perspective = Mat4(2.0f * near / (right - left), 0, (right + left) / (right - left), 0,
		0, 2.0f * near / (top - bottom), (top + bottom) / (top - bottom), 0,
		0, 0, -(far+near) / (far - near), (-2.0f * far * near) / (far - near),
		0, 0, -1, 0);

	return perspective;
}

Mat4 Mat4::Perspective(float fov, float aspect, float near, float far)
{
	Mat4 perspective = Mat4(1.0f / (aspect * tanf(fov * 0.5f)), 0, 0, 0,
		0, 1.0f / (tanf(fov * 0.5f)), 0, 0,
		0, 0, -(far + near) / (far - near), (-2.0f * far * near) / (far - near),
		0, 0, -1, 0);



	return perspective;

}

Mat4 Mat4::InfinitePerspective(float left, float right, float bottom, float top, float near, float epsilon)
{
	Mat4 perspective = Mat4(2.0f * near / (right - left), 0, (right + left) / (right - left), 0,
		0, 2.0f * near / (top - bottom), (top + bottom) / (top - bottom), 0,
		0, 0, -1 * (1 - epsilon), -2 * near * (1 - epsilon),
		0, 0, -1, 0);
	return perspective;
}

Mat4 Mat4::PerspectiveReverseZ(float left, float right, float bottom, float top, float near, float far)
{

	Mat4 perspective = Mat4(2.0f * near / (right - left), 0, (right + left) / (right - left), 0,
		0, 2.0f * near / (top - bottom), (top + bottom) / (top - bottom), 0,
		0, 0, -(near + far) / (near - far), (-2.0f * near * far) / (near - far),
		0, 0, -1, 0);

	return perspective;
}

Mat4 Mat4::InfinitePerspectiveReverseZ(float left, float right, float bottom, float top, float near, float epsilon)
{
	Mat4 perspective = Mat4(2.0f * near / (right - left), 0, (right + left) / (right - left), 0,
		0, 2.0f * near / (top - bottom), (top + bottom) / (top - bottom), 0,
		0, 0, 1 * (1 - epsilon), 2 * near * (1 - epsilon),
		0, 0, -1, 0);

	return perspective;
}


Mat4 Mat4::PerspectiveDepthZeroToOne(float left, float right, float bottom, float top, float near, float far)
{
	Mat4 perspective = Mat4(2.0f * near / (right - left), 0, (right + left) / (right - left), 0,
		0, 2.0f * near / (top - bottom), (top + bottom) / (top - bottom), 0,
		0, 0, -far / (far - near), -near * far / (far - near),
		0, 0, -1, 0);

	return perspective;
}
	
Mat4 Mat4::InfinitePerspectiveDepthZeroToOne(float left, float right, float bottom, float top, float near, float epsilon)
{
	Mat4 perspective = Mat4(2.0f * near / (right - left), 0, (right + left) / (right - left), 0,
		0, 2.0f * near / (top - bottom), (top + bottom) / (top - bottom), 0,
		0, 0, -1 * (1 - epsilon), -near * (1 - epsilon),
		0, 0, -1, 0);

	return perspective;
}

Mat4 Mat4::PerspectiveReverseZDepthZeroToOne(float left, float right, float bottom, float top, float near, float far)
{
	Mat4 perspective = Mat4(2.0f * near / (right - left), 0, (right + left) / (right - left), 0,
		0, 2.0f * near / (top - bottom), (top + bottom) / (top - bottom), 0,
		0, 0, -near/(near-far), -near*far/(near-far),
		0, 0, -1, 0);

	return perspective;
}

Mat4 Mat4::InfinitePerspectiveReverseZDepthZeroToOne(float left, float right, float bottom, float top, float near, float epsilon)
{
	Mat4 perspective = Mat4(2.0f * near / (right - left), 0, (right + left) / (right - left), 0,
		0, 2.0f * near / (top - bottom), (top + bottom) / (top - bottom), 0,
		0, 0, 0, near * (1 - epsilon),
		0, 0, -1, 0);

	return perspective;
}


Mat4::operator Mat3() const
{
	return Mat3(
		m[0][0], m[0][1], m[0][2],
		m[1][0], m[1][1], m[1][2],
		m[2][0], m[2][1], m[2][2]
	);
}