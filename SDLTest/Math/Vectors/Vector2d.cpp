#include "Vector2d.h"
#include <cmath>

GBM::Vector2d::Vector2d()
{
	x = 0.0;
	y = 0.0;
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
	return std::sqrt(x * x + y * y);
}

void GBM::Vector2d::normalize()
{
	double mag = magnitude();
	if (mag > 0.0) {
		double oneovermag = 1.0 / mag;
		x = x * oneovermag;
		y = y * oneovermag;
	}
}

double GBM::Vector2d::operator[](const int index)
{
	switch (index) {
	case 0:
		return x;
	case 1:
		return y;
	default:
		throw "GBM::Vector2d index out of bounds!";
		return 0.0;
	}
}

GBM::Vector2d::Vector2d(const GBM::Vector2d& v)
{
	x = v.x;
	y = v.y;
}

GBM::Vector2d& GBM::Vector2d::operator=(const GBM::Vector2d& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

void GBM::Vector2d::operator+=(const GBM::Vector2d& v)
{
	x += v.x;
	y += v.y;
}

GBM::Vector2d GBM::Vector2d::operator+(const GBM::Vector2d& v) const
{
	return GBM::Vector2d(x + v.x, y + v.y);
}

void GBM::Vector2d::operator-=(const GBM::Vector2d& v)
{
	x -= v.x;
	y -= v.y;
}

GBM::Vector2d GBM::Vector2d::operator-(const GBM::Vector2d& v) const
{
	return GBM::Vector2d(x - v.x, y - v.y);
}

void GBM::Vector2d::operator*=(const double& d)
{
	x *= d;
	y *= d;
}

GBM::Vector2d GBM::Vector2d::operator*(const double& d) const
{
	return GBM::Vector2d(x * d, y * d);
}

void GBM::Vector2d::operator/=(const double& d)
{
	x /= d;
	y /= d;
}

GBM::Vector2d GBM::Vector2d::operator/(const double& d) const
{
	return GBM::Vector2d(x / d, y / d);
}

double GBM::Vector2d::operator*(const GBM::Vector2d& v) const
{
	return x * v.x + y * v.y;
}

double GBM::Vector2d::dot(const GBM::Vector2d& v) const
{
	return x * v.x + y * v.y;
}
