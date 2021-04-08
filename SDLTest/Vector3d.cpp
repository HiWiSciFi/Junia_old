#include "Vector3d.h"
#include <cmath>
#include "ErrorHandler.h"

Vector3d::Vector3d()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Vector3d::Vector3d(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3d::~Vector3d()
{

}

double Vector3d::magnitude()
{
	return std::sqrt(x * x + y * y + z * z);
}

void Vector3d::normalize()
{
	double mag = magnitude();
	if (mag > 0.0) {
		double oneovermag = 1.0 / mag;
		x = x * oneovermag;
		y = y * oneovermag;
		z = z * oneovermag;
	}
}

double Vector3d::operator[](const int index)
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
		ErrorHandler::message = "Vector3d index out of bounds!";
		return 0.0;
	}
}

Vector3d::Vector3d(const Vector3d& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

Vector3d& Vector3d::operator=(const Vector3d& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

void Vector3d::operator+=(const Vector3d& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
}

Vector3d Vector3d::operator+(const Vector3d& v) const
{
	return Vector3d(x + v.x, y + v.y, z + v.z);
}

void Vector3d::operator-=(const Vector3d& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

Vector3d Vector3d::operator-(const Vector3d& v) const
{
	return Vector3d(x - v.x, y - v.y, z - v.z);
}

void Vector3d::operator*=(const double& d)
{
	x *= d;
	y *= d;
	z *= d;
}

Vector3d Vector3d::operator*(const double& d) const
{
	return Vector3d(x * d, y * d, z * d);
}

void Vector3d::operator/=(const double& d)
{
	x /= d;
	y /= d;
	z /= d;
}

Vector3d Vector3d::operator/(const double& d) const
{
	return Vector3d(x / d, y / d, z / d);
}

Vector3d Vector3d::operator%=(const Vector3d& v) const
{
	*this = cross(v);
}

Vector3d Vector3d::operator%(const Vector3d& v) const
{
	return Vector3d(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

Vector3d Vector3d::cross(const Vector3d& v) const
{
	return Vector3d(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

double Vector3d::operator*(const Vector3d& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

double Vector3d::dot(const Vector3d& v) const
{
	return x * v.x + y * v.y + z * v.z;
}