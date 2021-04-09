#include "Vector2f.h"
#include <cmath>

GBM::Vector2f::Vector2f()
{
	this->x = 0.0;
	this->y = 0.0;
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
	return std::sqrt(this->x * this->x + this->y * this->y);
}

void GBM::Vector2f::normalize()
{
	float mag = this->magnitude();
	if (mag > 0.0f) {
		float oneovermag = 1.0f / mag;
		this->x = this->x * oneovermag;
		this->y = this->y * oneovermag;
	}
}

float GBM::Vector2f::operator[](const int index)
{
	switch (index) {
	case 0:
		return this->x;
	case 1:
		return this->y;
	default:
		throw "GBM::Vector2f index out of bounds!";
		return 0.0f;
	}
}

GBM::Vector2f::Vector2f(const GBM::Vector2f& v)
{
	this->x = v.x;
	this->y = v.y;
}

GBM::Vector2f& GBM::Vector2f::operator=(const GBM::Vector2f& v)
{
	this->x = v.x;
	this->y = v.y;
	return *this;
}

void GBM::Vector2f::operator+=(const GBM::Vector2f& v)
{
	this->x += v.x;
	this->y += v.y;
}

GBM::Vector2f GBM::Vector2f::operator+(const GBM::Vector2f& v) const
{
	return GBM::Vector2f(this->x + v.x, this->y + v.y);
}

void GBM::Vector2f::operator-=(const GBM::Vector2f& v)
{
	this->x -= v.x;
	this->y -= v.y;
}

GBM::Vector2f GBM::Vector2f::operator-(const GBM::Vector2f& v) const
{
	return GBM::Vector2f(this->x - v.x, this->y - v.y);
}

void GBM::Vector2f::operator*=(const float& d)
{
	this->x *= d;
	this->y *= d;
}

GBM::Vector2f GBM::Vector2f::operator*(const float& d) const
{
	return GBM::Vector2f(this->x * d, this->y * d);
}

void GBM::Vector2f::operator/=(const float& d)
{
	this->x /= d;
	this->y /= d;
}

GBM::Vector2f GBM::Vector2f::operator/(const float& d) const
{
	return GBM::Vector2f(this->x / d, this->y / d);
}

float GBM::Vector2f::operator*(const GBM::Vector2f& v) const
{
	return this->x * v.x + this->y * v.y;
}

float GBM::Vector2f::dot(const GBM::Vector2f& v) const
{
	return this->x * v.x + this->y * v.y;
}
