#include "Vector2f.h"
#include <cmath>

GBM::Vector2f::Vector2f()
{
	x = 0.0;
	y = 0.0;
}

GBM::Vector2f::Vector2f(float x, float y)
{
	this->x = x;
	this->y = y;
}

GBM::Vector2f::~Vector2f()
{

}

float GBM::Vector2f::magnitude()
{
	return std::sqrt(x * x + y * y);
}

void GBM::Vector2f::normalize()
{
	float mag = magnitude();
	if (mag > 0.0f) {
		float oneovermag = 1.0f / mag;
		x = x * oneovermag;
		y = y * oneovermag;
	}
}

float GBM::Vector2f::operator[](const int index)
{
	switch (index) {
	case 0:
		return x;
	case 1:
		return y;
	default:
		throw "GBM::Vector2f index out of bounds!";
		return 0.0f;
	}
}

GBM::Vector2f::Vector2f(const GBM::Vector2f& v)
{
	x = v.x;
	y = v.y;
}

GBM::Vector2f& GBM::Vector2f::operator=(const GBM::Vector2f& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

void GBM::Vector2f::operator+=(const GBM::Vector2f& v)
{
	x += v.x;
	y += v.y;
}

GBM::Vector2f GBM::Vector2f::operator+(const GBM::Vector2f& v) const
{
	return GBM::Vector2f(x + v.x, y + v.y);
}

void GBM::Vector2f::operator-=(const GBM::Vector2f& v)
{
	x -= v.x;
	y -= v.y;
}

GBM::Vector2f GBM::Vector2f::operator-(const GBM::Vector2f& v) const
{
	return GBM::Vector2f(x - v.x, y - v.y);
}

void GBM::Vector2f::operator*=(const float& d)
{
	x *= d;
	y *= d;
}

GBM::Vector2f GBM::Vector2f::operator*(const float& d) const
{
	return GBM::Vector2f(x * d, y * d);
}

void GBM::Vector2f::operator/=(const float& d)
{
	x /= d;
	y /= d;
}

GBM::Vector2f GBM::Vector2f::operator/(const float& d) const
{
	return GBM::Vector2f(x / d, y / d);
}

float GBM::Vector2f::operator*(const GBM::Vector2f& v) const
{
	return x * v.x + y * v.y;
}

float GBM::Vector2f::dot(const GBM::Vector2f& v) const
{
	return x * v.x + y * v.y;
}
