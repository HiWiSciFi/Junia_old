#pragma once

namespace GBM {
	class Vector3i
	{
	private:

	public:
		int x;
		int y;
		int z;

		// constructor
		Vector3i();
		Vector3i(int x, int y, int z);

		// destructor
		~Vector3i();

		float magnitude();


		int operator[](const int index);

		Vector3i(const Vector3i& v);
		Vector3i& operator=(const Vector3i& v);

		void operator+=(const Vector3i& v);
		Vector3i operator+(const Vector3i& v)const;

		void operator-=(const Vector3i& v);
		Vector3i operator-(const Vector3i& v)const;

		void operator*=(const int& d);
		Vector3i operator*(const int& d) const;

		void operator/=(const int& d);
		Vector3i operator/(const int& d) const;

		void operator%=(const Vector3i& v);
		Vector3i operator%(const Vector3i& v) const;
		Vector3i cross(const Vector3i& v) const;

		int operator*(const Vector3i& v) const;
		int dot(const Vector3i& v) const;
	};
}