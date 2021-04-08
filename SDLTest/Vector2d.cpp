#include "Vector2d.h"
#include <cmath>
#include "ErrorHandler.h"

Vector2d::Vector2d()
{
	x = 0.0;
	y = 0.0;
}

Vector2d::Vector2d(double x, double y)
{
	this->x = x;
	this->y = y;
}

Vector2d::~Vector2d()
{

}

double Vector2d::magnitude()
{
	return std::sqrt(x * x + y * y);
}

void Vector2d::normalize()
{
	double mag = magnitude();
	if (mag > 0.0) {
		double oneovermag = 1.0 / mag;
		x = x * oneovermag;
		y = y * oneovermag;
	}
}

double Vector2d::operator[](const int index)
{
	switch (index) {
	case 0:
		return x;
	case 1:
		return y;
	default:
		ErrorHandler::code = ERRORCODE::VECTOR_INDEXOUTOFBOUNDS;
		ErrorHandler::message = "Vector2d index out of bounds!";
		return 0.0;
	}
}

Vector2d::Vector2d(const Vector2d& v)
{
	x = v.x;
	y = v.y;
}

Vector2d& Vector2d::operator=(const Vector2d& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

void Vector2d::operator+=(const Vector2d& v)
{
	x += v.x;
	y += v.y;
}

Vector2d Vector2d::operator+(const Vector2d& v) const
{
	return Vector2d(x + v.x, y + v.y);
}

void Vector2d::operator-=(const vector2d& v)
{
	x -= v.x;
	y -= v.y;
}

Vector2d Vector2d::operator-(const Vector2d& v) const
{
	return Vector2d(x - v.x, y - v.y);
}

void Vector2d::operator*=(const double& d)
{
	x *= d;
	y *= d;
}

Vector2d Vector2d::operator*(const double& d) const
{
	return Vector2d(x * d, y * d);
}

void Vector2d::operator/=(const double& d)
{
	x /= d;
	y /= d;
}

Vector2d Vector2d::operator/(const double& d) const
{
	return Vector2d(x / d, y / d);
}

double Vector2d::operator*(const Vector2d& v) const
{
	return x * v.x + y * v.y;
}

double Vector2d::dot(const Vector2d& v) const
{
	return x * v.x + y * v.y;
}
