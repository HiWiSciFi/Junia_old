#ifndef JUNIA_VECTOR2_H_
#define JUNIA_VECTOR2_H_

#include <cmath>

namespace JM {
	template<class T> class Vector2
	{
	private:

	public:

		/// @brief the x value of the vector
		T x;
		/// @brief the y value of the vector
		T y;

		/// @brief the default constructor setting all values to 0
		Vector2<T>() {
			this->x = 0;
			this->y = 0;
		}

		/// @brief the constructor taking the values for the elements as inputs
		/// @param x the x value of the vector
		/// @param y the y value of the vector
		Vector2<T>(const T x, const T y) {
			this->x = x;
			this->y = y;
		}

		// destructor
		~Vector2() {

		}

		/// @brief get the magnitude of the vector
		/// @return a double value conatinaing the magnitude of the vector
		double magnitude() {
			return std::sqrt(this->x * this->x + this->y * this->y);
		}

		/// @brief normalizes the vector
		void normalize() {
			double mag = this->magnitude();
			if (mag > 0.0) {
				double oneovermag = 1.0 / mag;
				this->x = this->x * oneovermag;
				this->y = this->y * oneovermag;
			}
		}

		/// @brief get an element of the vector by index
		/// @param index the index of the value to get
		/// @return the value saved at the given index
		T operator[](const int index) {
			switch (index) {
			case 0:
				return this->x;
			case 1:
				return this->y;
			default:
				throw "GBM::Vector2 index out of bounds!";
				return 0;
			}
		}

		/// @brief create a vetcor by copying the elements from an existing vector
		/// @param v the vector to copy the values from
		Vector2<T>(const Vector2<T>& v) {
			this->x = v.x;
			this->y = v.y;
		}

		Vector2<T>& operator=(const Vector2<T>& v) {
			this->x = v.x;
			this->y = v.y;
			return *this;
		}

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

		/// @brief calculate the dot product of two vectors
		/// @param v the vector to multiply with
		/// @return the scalar resulting from the calculation
		double operator*(const Vector2<T>& v) const {
			return this->x * v.x + this->y * v.y;
		}

		/// @brief calculate the dot product of two vectors
		/// @param v the vector to multiply with
		/// @return the scalar resulting from the calculation
		double dot(const Vector2<T>& v) const {
			return this->x * v.x + this->y * v.y;
		}
	};
}

#endif