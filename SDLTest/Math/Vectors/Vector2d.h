#pragma once

namespace GBM {
	class Vector2d
	{
	private:

	public:
		double x;
		double y;

		// constructor
		Vector2d();
		Vector2d(double x, double y);

		// destructor
		~Vector2d();

		double magnitude();

		void normalize();


		double operator[](const int index);

		Vector2d(const Vector2d& v);
		Vector2d& operator=(const Vector2d& v);

		void operator+=(const Vector2d& v);
		Vector2d operator+(const Vector2d& v)const;

		void operator-=(const Vector2d& v);
		Vector2d operator-(const Vector2d& v)const;

		void operator*=(const double& d);
		Vector2d operator*(const double& d) const;

		void operator/=(const double& d);
		Vector2d operator/(const double& d) const;

		double operator*(const Vector2d& v) const;
		double dot(const Vector2d& v) const;
	};
}