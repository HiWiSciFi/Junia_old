#include "Vector2i.h"
#include <cmath>

GBM::Vector2i::Vector2i()
{
	x = 0;
	y = 0;
}

GBM::Vector2i::Vector2i(int x, int y)
{
	this->x = x;
	this->y = y;
}

GBM::Vector2i::~Vector2i()
{

}

float GBM::Vector2i::magnitude()
{
	return float(std::sqrt(x * x + y * y));
}

void GBM::Vector2i::normalize()
{
	float mag = magnitude();
	if (mag > 0.0) {
		float oneovermag = float(1.0 / mag);
		x = int(x * oneovermag);
		y = int(y * oneovermag);
	}
}

int GBM::Vector2i::operator[](const int index)
{
	switch (index) {
	case 0:
		return x;
	case 1:
		return y;
	default:
		throw "GBM::Vector2i index out of bounds!";
		return 0;
	}
}

GBM::Vector2i::Vector2i(const GBM::Vector2i& v)
{
	x = v.x;
	y = v.y;
}

GBM::Vector2i& GBM::Vector2i::operator=(const GBM::Vector2i& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

void GBM::Vector2i::operator+=(const GBM::Vector2i& v)
{
	x += v.x;
	y += v.y;
}

GBM::Vector2i GBM::Vector2i::operator+(const GBM::Vector2i& v) const
{
	return GBM::Vector2i(x + v.x, y + v.y);
}

void GBM::Vector2i::operator-=(const GBM::Vector2i& v)
{
	x -= v.x;
	y -= v.y;
}

GBM::Vector2i GBM::Vector2i::operator-(const GBM::Vector2i& v) const
{
	return GBM::Vector2i(x - v.x, y - v.y);
}

void GBM::Vector2i::operator*=(const int& d)
{
	x *= d;
	y *= d;
}

GBM::Vector2i GBM::Vector2i::operator*(const int& d) const
{
	return GBM::Vector2i(x * d, y * d);
}

void GBM::Vector2i::operator/=(const int& d)
{
	x /= d;
	y /= d;
}

GBM::Vector2i GBM::Vector2i::operator/(const int& d) const
{
	return GBM::Vector2i(x / d, y / d);
}

int GBM::Vector2i::operator*(const GBM::Vector2i& v) const
{
	return x * v.x + y * v.y;
}

int GBM::Vector2i::dot(const GBM::Vector2i& v) const
{
	return x * v.x + y * v.y;
}
