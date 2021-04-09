#include "Vector3f.h"
#include <cmath>

GBM::Vector3f::Vector3f()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

GBM::Vector3f::Vector3f(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

GBM::Vector3f::~Vector3f()
{

}

float GBM::Vector3f::magnitude()
{
	return std::sqrt(x * x + y * y + z * z);
}

void GBM::Vector3f::normalize()
{
	float mag = magnitude();
	if (mag > 0.0) {
		float oneovermag = float(1.0 / mag);
		x = x * oneovermag;
		y = y * oneovermag;
		z = z * oneovermag;
	}
}

float GBM::Vector3f::operator[](const int index)
{
	switch (index) {
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
	default:
		throw "GBM::Vector3f index out of bounds!";
		return 0.0f;
	}
}

GBM::Vector3f::Vector3f(const GBM::Vector3f& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

GBM::Vector3f& GBM::Vector3f::operator=(const GBM::Vector3f& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

void GBM::Vector3f::operator+=(const GBM::Vector3f& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
}

GBM::Vector3f GBM::Vector3f::operator+(const GBM::Vector3f& v) const
{
	return GBM::Vector3f(x + v.x, y + v.y, z + v.z);
}

void GBM::Vector3f::operator-=(const GBM::Vector3f& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

GBM::Vector3f GBM::Vector3f::operator-(const GBM::Vector3f& v) const
{
	return GBM::Vector3f(x - v.x, y - v.y, z - v.z);
}

void GBM::Vector3f::operator*=(const float& d)
{
	x *= d;
	y *= d;
	z *= d;
}

GBM::Vector3f GBM::Vector3f::operator*(const float& d) const
{
	return GBM::Vector3f(x * d, y * d, z * d);
}

void GBM::Vector3f::operator/=(const float& d)
{
	x /= d;
	y /= d;
	z /= d;
}

GBM::Vector3f GBM::Vector3f::operator/(const float& d) const
{
	return GBM::Vector3f(x / d, y / d, z / d);
}

void GBM::Vector3f::operator%=(const GBM::Vector3f& v)
{
	*this = cross(v);
}

GBM::Vector3f GBM::Vector3f::operator%(const GBM::Vector3f& v) const
{
	return GBM::Vector3f(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

GBM::Vector3f GBM::Vector3f::cross(const GBM::Vector3f& v) const
{
	return GBM::Vector3f(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

float GBM::Vector3f::operator*(const GBM::Vector3f& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

float GBM::Vector3f::dot(const GBM::Vector3f& v) const
{
	return x * v.x + y * v.y + z * v.z;
}