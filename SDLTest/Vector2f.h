#pragma once

class Vector2f
{
private:

public:
	float x;
	float y;

	// constructor
	Vector2f();
	Vector2f(float x, float y);

	// destructor
	~Vector2f();

	float magnitude();

	void normalize();


	float operator[](const int index);

	Vector2f(const Vector2f& v);
	Vector2f& operator=(const Vector2f& v);

	void operator+=(const Vector2f& v);
	Vector2f operator+(const Vector2f& v)const;

	void operator-=(const Vector2f& v);
	Vector2f operator-(const Vector2f& v)const;

	void operator*=(const float& d);
	Vector2f operator*(const float& d) const;

	void operator/=(const float& d);
	Vector2f operator/(const float& d) const;

	float operator*(const Vector2f& v) const;

	float dot(const Vector2f& v) const;
};