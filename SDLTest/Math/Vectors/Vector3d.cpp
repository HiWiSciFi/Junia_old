#include "Vector3d.h"
#include <cmath>

GBM::Vector3d::Vector3d()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

GBM::Vector3d::Vector3d(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

GBM::Vector3d::~Vector3d()
{

}

double GBM::Vector3d::magnitude()
{
	return std::sqrt(x * x + y * y + z * z);
}

void GBM::Vector3d::normalize()
{
	double mag = magnitude();
	if (mag > 0.0) {
		double oneovermag = 1.0 / mag;
		x = x * oneovermag;
		y = y * oneovermag;
		z = z * oneovermag;
	}
}

double GBM::Vector3d::operator[](const int index)
{
	switch (index) {
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
	default:
		throw "GBM::Vector3d index out of bounds!";
		return 0.0;
	}
}

GBM::Vector3d::Vector3d(const GBM::Vector3d& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

GBM::Vector3d& GBM::Vector3d::operator=(const GBM::Vector3d& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

void GBM::Vector3d::operator+=(const GBM::Vector3d& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
}

GBM::Vector3d GBM::Vector3d::operator+(const GBM::Vector3d& v) const
{
	return GBM::Vector3d(x + v.x, y + v.y, z + v.z);
}

void GBM::Vector3d::operator-=(const GBM::Vector3d& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

GBM::Vector3d GBM::Vector3d::operator-(const GBM::Vector3d& v) const
{
	return GBM::Vector3d(x - v.x, y - v.y, z - v.z);
}

void GBM::Vector3d::operator*=(const double& d)
{
	x *= d;
	y *= d;
	z *= d;
}

GBM::Vector3d GBM::Vector3d::operator*(const double& d) const
{
	return GBM::Vector3d(x * d, y * d, z * d);
}

void GBM::Vector3d::operator/=(const double& d)
{
	x /= d;
	y /= d;
	z /= d;
}

GBM::Vector3d GBM::Vector3d::operator/(const double& d) const
{
	return GBM::Vector3d(x / d, y / d, z / d);
}

void GBM::Vector3d::operator%=(const GBM::Vector3d& v)
{
	*this = cross(v);
}

GBM::Vector3d GBM::Vector3d::operator%(const GBM::Vector3d& v) const
{
	return GBM::Vector3d(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

GBM::Vector3d GBM::Vector3d::cross(const GBM::Vector3d& v) const
{
	return GBM::Vector3d(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

double GBM::Vector3d::operator*(const GBM::Vector3d& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

double GBM::Vector3d::dot(const GBM::Vector3d& v) const
{
	return x * v.x + y * v.y + z * v.z;
}