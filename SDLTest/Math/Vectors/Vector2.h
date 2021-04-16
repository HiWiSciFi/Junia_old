#ifndef GBM_VECTOR2_H_
#define GBM_VECTOR2_H_
#include <cmath>

namespace GBM {
	template<class T> class Vector2
	{
	private:

	public:

		// attributes

		T x;
		T y;

		// constructors

		Vector2<T>() {
			this->x = 0;
			this->y = 0;
		}

		Vector2<T>(T x, T y) {
			this->x = x;
			this->y = y;
		}

		// destructor
		~Vector2() {

		}

		// functions

		double magnitude() {
			return std::sqrt(this->x * this->x + this->y * this->y);
		}

		void normalize() {
			double mag = this->magnitude();
			if (mag > 0.0) {
				double oneovermag = 1.0 / mag;
				this->x = this->x * oneovermag;
				this->y = this->y * oneovermag;
			}
		}

		T operator[](const int index) {
			switch (index) {
			case 0:
				return this->x;
			case 1:
				return this->y;
			default:
				throw "GBM::Vector2 index out of bounds!";
				return NULL;
			}
		}

		// copy constructors

		Vector2<T>(const Vector2<T>& v) {
			this->x = v.x;
			this->y = v.y;
		}

		Vector2<T>& operator=(const Vector2<T>& v) {
			this->x = v.x;
			this->y = v.y;
			return *this;
		}

		// math operators

		void operator+=(const Vector2<T>& v) {
			this->x += v.x;
			this->y += v.y;
		}

		Vector2<T> operator+(const Vector2<T>& v) const {
			return Vector2<T>(this->x + v.x, this->y + v.y);
		}

		void operator-=(const Vector2<T>& v) {
			this->x -= v.x;
			this->y -= v.y;
		}

		Vector2<T> operator-(const Vector2<T>& v) const {
			return Vector2<T>(this->x - v.x, this->y - v.y);
		}

		void operator*=(const double& d) {
			this->x *= d;
			this->y *= d;
		}

		Vector2<T> operator*(const double& d) const {
			return Vector2<T>(this->x * d, this->y * d);
		}

		void operator/=(const double& d) {
			this->x /= d;
			this->y /= d;
		}

		Vector2<T> operator/(const double& d) const {
			return Vector2<T>(this->x / d, this->y / d);
		}

		double operator*(const Vector2<T>& v) const {
			return this->x * v.x + this->y * v.y;
		}

		double dot(const Vector2<T>& v) const {
			return this->x * v.x + this->y * v.y;
		}
	};
}

#endif