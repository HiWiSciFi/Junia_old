#include "Vector2d.h"
#include <cmath>

GBM::Vector2d::Vector2d()
{
	this->x = 0.0;
	this->y = 0.0;
}

GBM::Vector2d::Vector2d(double x, double y)
{
	this->x = x;
	this->y = y;
}

GBM::Vector2d::~Vector2d()
{

}

double GBM::Vector2d::magnitude()
{
	return std::sqrt(this->x * this->x + this->y * this->y);
}

void GBM::Vector2d::normalize()
{
	double mag = this->magnitude();
	if (mag > 0.0) {
		double oneovermag = 1.0 / mag;
		this->x = this->x * oneovermag;
		this->y = this->y * oneovermag;
	}
}

double GBM::Vector2d::operator[](const int index)
{
	switch (index) {
	case 0:
		return this->x;
	case 1:
		return this->y;
	default:
		throw "GBM::Vector2d index out of bounds!";
		return 0.0;
	}
}

GBM::Vector2d::Vector2d(const GBM::Vector2d& v)
{
	this->x = v.x;
	this->y = v.y;
}

GBM::Vector2d& GBM::Vector2d::operator=(const GBM::Vector2d& v)
{
	this->x = v.x;
	this->y = v.y;
	return *this;
}

void GBM::Vector2d::operator+=(const GBM::Vector2d& v)
{
	this->x += v.x;
	this->y += v.y;
}

GBM::Vector2d GBM::Vector2d::operator+(const GBM::Vector2d& v) const
{
	return GBM::Vector2d(this->x + v.x, this->y + v.y);
}

void GBM::Vector2d::operator-=(const GBM::Vector2d& v)
{
	this->x -= v.x;
	this->y -= v.y;
}

GBM::Vector2d GBM::Vector2d::operator-(const GBM::Vector2d& v) const
{
	return GBM::Vector2d(this->x - v.x, this->y - v.y);
}

void GBM::Vector2d::operator*=(const double& d)
{
	this->x *= d;
	this->y *= d;
}

GBM::Vector2d GBM::Vector2d::operator*(const double& d) const
{
	return GBM::Vector2d(this->x * d, this->y * d);
}

void GBM::Vector2d::operator/=(const double& d)
{
	this->x /= d;
	this->y /= d;
}

GBM::Vector2d GBM::Vector2d::operator/(const double& d) const
{
	return GBM::Vector2d(this->x / d, this->y / d);
}

double GBM::Vector2d::operator*(const GBM::Vector2d& v) const
{
	return this->x * v.x + this->y * v.y;
}

double GBM::Vector2d::dot(const GBM::Vector2d& v) const
{
	return this->x * v.x + this->y * v.y;
}
