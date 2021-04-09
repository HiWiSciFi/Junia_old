#include "Vector2i.h"
#include <cmath>

GBM::Vector2i::Vector2i()
{
	this->x = 0;
	this->y = 0;
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
	return float(std::sqrt(this->x * this->x + this->y * this->y));
}

int GBM::Vector2i::operator[](const int index)
{
	switch (index) {
	case 0:
		return this->x;
	case 1:
		return this->y;
	default:
		throw "GBM::Vector2i index out of bounds!";
		return 0;
	}
}

GBM::Vector2i::Vector2i(const GBM::Vector2i& v)
{
	this->x = v.x;
	this->y = v.y;
}

GBM::Vector2i& GBM::Vector2i::operator=(const GBM::Vector2i& v)
{
	this->x = v.x;
	this->y = v.y;
	return *this;
}

void GBM::Vector2i::operator+=(const GBM::Vector2i& v)
{
	this->x += v.x;
	this->y += v.y;
}

GBM::Vector2i GBM::Vector2i::operator+(const GBM::Vector2i& v) const
{
	return GBM::Vector2i(this->x + v.x, this->y + v.y);
}

void GBM::Vector2i::operator-=(const GBM::Vector2i& v)
{
	this->x -= v.x;
	this->y -= v.y;
}

GBM::Vector2i GBM::Vector2i::operator-(const GBM::Vector2i& v) const
{
	return GBM::Vector2i(this->x - v.x, this->y - v.y);
}

void GBM::Vector2i::operator*=(const int& d)
{
	this->x *= d;
	this->y *= d;
}

GBM::Vector2i GBM::Vector2i::operator*(const int& d) const
{
	return GBM::Vector2i(this->x * d, this->y * d);
}

void GBM::Vector2i::operator/=(const int& d)
{
	this->x /= d;
	this->y /= d;
}

GBM::Vector2i GBM::Vector2i::operator/(const int& d) const
{
	return GBM::Vector2i(this->x / d, this->y / d);
}

int GBM::Vector2i::operator*(const GBM::Vector2i& v) const
{
	return this->x * v.x + this->y * v.y;
}

int GBM::Vector2i::dot(const GBM::Vector2i& v) const
{
	return this->x * v.x + this->y * v.y;
}
