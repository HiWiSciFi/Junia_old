#pragma once

namespace GBM {
	class Vector2i
	{
	private:

	public:
		int x;
		int y;

		// constructor
		Vector2i();
		Vector2i(int x, int y);

		// destructor
		~Vector2i();

		float magnitude();


		int operator[](const int index);

		Vector2i(const Vector2i& v);
		Vector2i& operator=(const Vector2i& v);

		void operator+=(const Vector2i& v);
		Vector2i operator+(const Vector2i& v)const;

		void operator-=(const Vector2i& v);
		Vector2i operator-(const Vector2i& v)const;

		void operator*=(const int& d);
		Vector2i operator*(const int& d) const;

		void operator/=(const int& d);
		Vector2i operator/(const int& d) const;

		int operator*(const Vector2i& v) const;

		int dot(const Vector2i& v) const;
	};
}