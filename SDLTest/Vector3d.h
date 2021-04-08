#pragma once

class Vector3d
{
private:

public:
	double x;
	double y;
	double z;

	// constructor
	Vector3d();
	Vector3d(double x, double y, double z);

	// destructor
	~Vector3d();

	double magnitude();

	void normalize();


	double operator[](const int index);

	Vector3d(const Vector3d& v);
	Vector3d& operator=(const Vector3d& v);

	void operator+=(const Vector3d& v);
	Vector3d operator+(const Vector3d& v)const;

	void operator-=(const Vector3d& v);
	Vector3d operator-(const Vector3d& v)const;

	void operator*=(const double& d);
	Vector3d operator*(const double& d) const;

	void operator/=(const double& d);
	Vector3d operator/(const double& d) const;

	Vector3d operator%=(const Vector3d& v) const;
	Vector3d operator%(const Vector3d& v) const;
	Vector3d cross(const Vector3d& v) const;

	double operator*(const Vector3d& v) const;
	double dot(const Vector3d& v) const;
};