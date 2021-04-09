#include "Vector3d.h"
#include <cmath>

GBM::Vector3d::Vector3d()
{
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
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
	return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

void GBM::Vector3d::normalize()
{
	double mag = this->magnitude();
	if (mag > 0.0) {
		double oneovermag = 1.0 / mag;
		this->x = this->x * oneovermag;
		this->y = this->y * oneovermag;
		this->z = this->z * oneovermag;
	}
}

double GBM::Vector3d::operator[](const int index)
{
	switch (index) {
	case 0:
		return this->x;
	case 1:
		return this->y;
	case 2:
		return this->z;
	default:
		throw "GBM::Vector3d index out of bounds!";
		return 0.0;
	}
}

GBM::Vector3d::Vector3d(const GBM::Vector3d& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
}

GBM::Vector3d& GBM::Vector3d::operator=(const GBM::Vector3d& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	return *this;
}

void GBM::Vector3d::operator+=(const GBM::Vector3d& v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
}

GBM::Vector3d GBM::Vector3d::operator+(const GBM::Vector3d& v) const
{
	return GBM::Vector3d(this->x + v.x, this->y + v.y, this->z + v.z);
}

void GBM::Vector3d::operator-=(const GBM::Vector3d& v)
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
}

GBM::Vector3d GBM::Vector3d::operator-(const GBM::Vector3d& v) const
{
	return GBM::Vector3d(x - v.x, y - v.y, z - v.z);
}

void GBM::Vector3d::operator*=(const double& d)
{
	this->x *= d;
	this->y *= d;
	this->z *= d;
}

GBM::Vector3d GBM::Vector3d::operator*(const double& d) const
{
	return GBM::Vector3d(x * d, y * d, z * d);
}

void GBM::Vector3d::operator/=(const double& d)
{
	this->x /= d;
	this->y /= d;
	this->z /= d;
}

GBM::Vector3d GBM::Vector3d::operator/(const double& d) const
{
	return GBM::Vector3d(this->x / d, this->y / d, this->z / d);
}

void GBM::Vector3d::operator%=(const GBM::Vector3d& v)
{
	*this = this->cross(v);
}

GBM::Vector3d GBM::Vector3d::operator%(const GBM::Vector3d& v) const
{
	return GBM::Vector3d(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z, this->x * v.y - this->y * v.x);
}

GBM::Vector3d GBM::Vector3d::cross(const GBM::Vector3d& v) const
{
	return GBM::Vector3d(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z, this->x * v.y - this->y * v.x);
}

double GBM::Vector3d::operator*(const GBM::Vector3d& v) const
{
	return this->x * v.x + this->y * v.y + this->z * v.z;
}

double GBM::Vector3d::dot(const GBM::Vector3d& v) const
{
	return this->x * v.x + this->y * v.y + this->z * v.z;
}