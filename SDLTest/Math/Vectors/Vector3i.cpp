#include "Vector3i.h"
#include <cmath>

GBM::Vector3i::Vector3i()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

GBM::Vector3i::Vector3i(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

GBM::Vector3i::~Vector3i()
{

}

float GBM::Vector3i::magnitude()
{
	return float(std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z));
}

int GBM::Vector3i::operator[](const int index)
{
	switch (index) {
	case 0:
		return this->x;
	case 1:
		return this->y;
	case 2:
		return this->z;
	default:
		throw "GBM::Vector3i index out of bounds!";
		return 0;
	}
}

GBM::Vector3i::Vector3i(const GBM::Vector3i& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
}

GBM::Vector3i& GBM::Vector3i::operator=(const GBM::Vector3i& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	return *this;
}

void GBM::Vector3i::operator+=(const GBM::Vector3i& v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
}

GBM::Vector3i GBM::Vector3i::operator+(const GBM::Vector3i& v) const
{
	return GBM::Vector3i(this->x + v.x, this->y + v.y, this->z + v.z);
}

void GBM::Vector3i::operator-=(const GBM::Vector3i& v)
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
}

GBM::Vector3i GBM::Vector3i::operator-(const GBM::Vector3i& v) const
{
	return GBM::Vector3i(this->x - v.x, this->y - v.y, this->z - v.z);
}

void GBM::Vector3i::operator*=(const int& d)
{
	this->x *= d;
	this->y *= d;
	this->z *= d;
}

GBM::Vector3i GBM::Vector3i::operator*(const int& d) const
{
	return GBM::Vector3i(this->x * d, this->y * d, this->z * d);
}

void GBM::Vector3i::operator/=(const int& d)
{
	this->x /= d;
	this->y /= d;
	this->z /= d;
}

GBM::Vector3i GBM::Vector3i::operator/(const int& d) const
{
	return GBM::Vector3i(this->x / d, this->y / d, this->z / d);
}

void GBM::Vector3i::operator%=(const GBM::Vector3i& v)
{
	*this = this->cross(v);
}

GBM::Vector3i GBM::Vector3i::operator%(const GBM::Vector3i& v) const
{
	return GBM::Vector3i(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z, this->x * v.y - this->y * v.x);
}

GBM::Vector3i GBM::Vector3i::cross(const GBM::Vector3i& v) const
{
	return GBM::Vector3i(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z, this->x * v.y - this->y * v.x);
}

int GBM::Vector3i::operator*(const GBM::Vector3i& v) const
{
	return this->x * v.x + this->y * v.y + this->z * v.z;
}

int GBM::Vector3i::dot(const GBM::Vector3i& v) const
{
	return this->x * v.x + this->y * v.y + this->z * v.z;
}