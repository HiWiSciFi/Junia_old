#include "Vector2i.h"
#include <cmath>
#include "ErrorHandler.h"

Vector2i::Vector2i()
{
	x = 0.0;
	y = 0.0;
}

Vector2i::Vector2i(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2i::~Vector2i()
{

}

float Vector2i::magnitude()
{
	return std::sqrt(x * x + y * y);
}

void Vector2i::normalize()
{
	float mag = magnitude();
	if (mag > 0.0) {
		float oneovermag = 1.0 / mag;
		x = x * oneovermag;
		y = y * oneovermag;
	}
}

float Vector2i::operator[](const int index)
{
	switch (index) {
	case 0:
		return x;
	case 1:
		return y;
	default:
		ErrorHandler::code = ERRORCODE::VECTOR_INDEXOUTOFBOUNDS;
		ErrorHandler::message = "Vector2i index out of bounds!";
		return 0.0;
	}
}

Vector2i::Vector2i(const Vector2i& v)
{
	x = v.x;
	y = v.y;
}

Vector2i& Vector2i::operator=(const Vector2i& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

void Vector2i::operator+=(const Vector2i& v)
{
	x += v.x;
	y += v.y;
}

Vector2i Vector2i::operator+(const Vector2i& v) const
{
	return Vector2i(x + v.x, y + v.y);
}

void Vector2i::operator-=(const Vector2i& v)
{
	x -= v.x;
	y -= v.y;
}

Vector2i Vector2i::operator-(const Vector2i& v) const
{
	return Vector2i(x - v.x, y - v.y);
}

void Vector2i::operator*=(const float& d)
{
	x *= d;
	y *= d;
}

Vector2i Vector2i::operator*(const float& d) const
{
	return Vector2i(x * d, y * d);
}

void Vector2i::operator/=(const float& d)
{
	x /= d;
	y /= d;
}

Vector2i Vector2i::operator/(const float& d) const
{
	return Vector2i(x / d, y / d);
}

float Vector2i::operator*(const Vector2i& v) const
{
	return x * v.x + y * v.y;
}

float Vector2i::dot(const Vector2i& v) const
{
	return x * v.x + y * v.y;
}
