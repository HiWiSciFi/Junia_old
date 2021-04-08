#pragma once

class Vector3f
{
private:

public:
	float x;
	float y;
	float z;

	// constructor
	Vector3f();
	Vector3f(float x, float y, float z);

	// destructor
	~Vector3f();

	float magnitude();

	void normalize();


	float operator[](const int index);

	Vector3f(const Vector3f& v);
	Vector3f& operator=(const Vector3f& v);

	void operator+=(const Vector3f& v);
	Vector3f operator+(const Vector3f& v)const;

	void operator-=(const Vector3f& v);
	Vector3f operator-(const Vector3f& v)const;

	void operator*=(const float& d);
	Vector3f operator*(const float& d) const;

	void operator/=(const float& d);
	Vector3f operator/(const float& d) const;

	Vector3f operator%=(const Vector3f& v) const;
	Vector3f operator%(const Vector3f& v) const;
	Vector3f cross(const Vector3f& v) const;

	float operator*(const Vector3f& v) const;
	float dot(const Vector3f& v) const;
};