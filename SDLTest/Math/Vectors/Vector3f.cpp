#include "Vector3f.h"
#include <cmath>

GBM::Vector3f::Vector3f()
{
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
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
	return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

void GBM::Vector3f::normalize()
{
	float mag = this->magnitude();
	if (mag > 0.0) {
		float oneovermag = float(1.0 / mag);
		this->x = this->x * oneovermag;
		this->y = this->y * oneovermag;
		this->z = this->z * oneovermag;
	}
}

float GBM::Vector3f::operator[](const int index)
{
	switch (index) {
	case 0:
		return this->x;
	case 1:
		return this->y;
	case 2:
		return this->z;
	default:
		throw "GBM::Vector3f index out of bounds!";
		return 0.0f;
	}
}

GBM::Vector3f::Vector3f(const GBM::Vector3f& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
}

GBM::Vector3f& GBM::Vector3f::operator=(const GBM::Vector3f& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	return *this;
}

void GBM::Vector3f::operator+=(const GBM::Vector3f& v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
}

GBM::Vector3f GBM::Vector3f::operator+(const GBM::Vector3f& v) const
{
	return GBM::Vector3f(this->x + v.x, this->y + v.y, this->z + v.z);
}

void GBM::Vector3f::operator-=(const GBM::Vector3f& v)
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
}

GBM::Vector3f GBM::Vector3f::operator-(const GBM::Vector3f& v) const
{
	return GBM::Vector3f(this->x - v.x, this->y - v.y, this->z - v.z);
}

void GBM::Vector3f::operator*=(const float& d)
{
	this->x *= d;
	this->y *= d;
	this->z *= d;
}

GBM::Vector3f GBM::Vector3f::operator*(const float& d) const
{
	return GBM::Vector3f(this->x * d, this->y * d, this->z * d);
}

void GBM::Vector3f::operator/=(const float& d)
{
	this->x /= d;
	this->y /= d;
	this->z /= d;
}

GBM::Vector3f GBM::Vector3f::operator/(const float& d) const
{
	return GBM::Vector3f(this->x / d, this->y / d, this->z / d);
}

void GBM::Vector3f::operator%=(const GBM::Vector3f& v)
{
	*this = this->cross(v);
}

GBM::Vector3f GBM::Vector3f::operator%(const GBM::Vector3f& v) const
{
	return GBM::Vector3f(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z, this->x * v.y - this->y * v.x);
}

GBM::Vector3f GBM::Vector3f::cross(const GBM::Vector3f& v) const
{
	return GBM::Vector3f(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z, this->x * v.y - this->y * v.x);
}

float GBM::Vector3f::operator*(const GBM::Vector3f& v) const
{
	return this->x * v.x + this->y * v.y + this->z * v.z;
}

float GBM::Vector3f::dot(const GBM::Vector3f& v) const
{
	return this->x * v.x + this->y * v.y + this->z * v.z;
}