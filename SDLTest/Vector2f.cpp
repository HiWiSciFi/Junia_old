#include "Vector2f.h"
#include <cmath>
#include "ErrorHandler.h"

Vector2f::Vector2f()
{
	x = 0.0;
	y = 0.0;
}

Vector2f::Vector2f(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2f::~Vector2f()
{

}

float Vector2f::magnitude()
{
	return std::sqrt(x * x + y * y);
}

void Vector2f::normalize()
{
	float mag = magnitude();
	if (mag > 0.0) {
		float oneovermag = 1.0 / mag;
		x = x * oneovermag;
		y = y * oneovermag;
	}
}

float Vector2f::operator[](const int index)
{
	switch (index) {
	case 0:
		return x;
	case 1:
		return y;
	default:
		ErrorHandler::code = ERRORCODE::VECTOR_INDEXOUTOFBOUNDS;
		ErrorHandler::message = "Vector2f index out of bounds!";
		return 0.0;
	}
}

Vector2f::Vector2f(const Vector2f& v)
{
	x = v.x;
	y = v.y;
}

Vector2f& Vector2f::operator=(const Vector2f& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

void Vector2f::operator+=(const Vector2f& v)
{
	x += v.x;
	y += v.y;
}

Vector2f Vector2f::operator+(const Vector2f& v) const
{
	return Vector2f(x + v.x, y + v.y);
}

void Vector2f::operator-=(const Vector2f& v)
{
	x -= v.x;
	y -= v.y;
}

Vector2f Vector2f::operator-(const Vector2f& v) const
{
	return Vector2f(x - v.x, y - v.y);
}

void Vector2f::operator*=(const float& d)
{
	x *= d;
	y *= d;
}

Vector2f Vector2f::operator*(const float& d) const
{
	return Vector2f(x * d, y * d);
}

void Vector2f::operator/=(const float& d)
{
	x /= d;
	y /= d;
}

Vector2f Vector2f::operator/(const float& d) const
{
	return Vector2f(x / d, y / d);
}

float Vector2f::operator*(const Vector2f& v) const
{
	return x * v.x + y * v.y;
}

float Vector2f::dot(const Vector2f& v) const
{
	return x * v.x + y * v.y;
}
