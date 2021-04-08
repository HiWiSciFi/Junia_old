#include "Vector3f.h"
#include <cmath>
#include "ErrorHandler.h"

Vector3f::Vector3f()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Vector3f::Vector3f(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3f::~Vector3f()
{

}

float Vector3f::magnitude()
{
	return std::sqrt(x * x + y * y + z * z);
}

void Vector3f::normalize()
{
	float mag = magnitude();
	if (mag > 0.0) {
		float oneovermag = 1.0 / mag;
		x = x * oneovermag;
		y = y * oneovermag;
		z = z * oneovermag;
	}
}

float Vector3f::operator[](const int index)
{
	switch (index) {
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
	default:
		ErrorHandler::code = ERRORCODE::VECTOR_INDEXOUTOFBOUNDS;
		ErrorHandler::message = "Vector3f index out of bounds!";
		return 0.0;
	}
}

Vector3f::Vector3f(const Vector3f& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

Vector3f& Vector3f::operator=(const Vector3f& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

void Vector3f::operator+=(const Vector3f& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
}

Vector3f Vector3f::operator+(const Vector3f& v) const
{
	return Vector3f(x + v.x, y + v.y, z + v.z);
}

void Vector3f::operator-=(const Vector3f& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

Vector3f Vector3f::operator-(const Vector3f& v) const
{
	return Vector3f(x - v.x, y - v.y, z - v.z);
}

void Vector3f::operator*=(const float& d)
{
	x *= d;
	y *= d;
	z *= d;
}

Vector3f Vector3f::operator*(const float& d) const
{
	return Vector3f(x * d, y * d, z * d);
}

void Vector3f::operator/=(const float& d)
{
	x /= d;
	y /= d;
	z /= d;
}

Vector3f Vector3f::operator/(const float& d) const
{
	return Vector3f(x / d, y / d, z / d);
}

Vector3f Vector3f::operator%=(const Vector3f& v) const
{
	*this = cross(v);
}

Vector3f Vector3f::operator%(const Vector3f& v) const
{
	return Vector3f(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

Vector3f Vector3f::cross(const Vector3f& v) const
{
	return Vector3f(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

float Vector3f::operator*(const Vector3f& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

float Vector3f::dot(const Vector3f& v) const
{
	return x * v.x + y * v.y + z * v.z;
}