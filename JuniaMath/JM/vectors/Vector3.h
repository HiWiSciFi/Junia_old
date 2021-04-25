#ifndef JUNIA_VECTOR3_H_
#define JUNIA_VECTOR3_H_

#include <cmath>

namespace JM {
	template<class T> class Vector3 {
	private:

	public:

		/// @brief the x value of the vector
		T x;
		/// @brief the y value of the vector
		T y;
		/// @brief the z value of the vector
		T z;

		/// @brief the default constructor setting all values to 0
		Vector3<T>() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
		}

		/// @brief the constructor taking the values for the elements as inputs
		/// @param x the x value of the vector
		/// @param y the y value of the vector
		/// @param z the z value of the vector
		Vector3<T>(const T x, const T y, const T z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		// destructor
		~Vector3() {

		}

		/// @brief get the magnitude of the vector
		/// @return a double value conatinaing the magnitude of the vector
		double magnitude() {
			return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
		}

		/// @brief normalizes the vector
		void normalize() {
			double mag = this->magnitude();
			if (mag > 0.0) {
				double oneovermag = 1.0 / mag;
				this->x = this->x * oneovermag;
				this->y = this->y * oneovermag;
				this->z = this->z * oneovermag;
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
			case 2:
				return this->z;
			default:
				throw "GBM::Vector3 index out of bounds!";
				return 0;
			}
		}

		/// @brief create a vetcor by copying the elements from an existing vector
		/// @param v the vector to copy the values from
		Vector3<T>(const Vector3<T>& v) {
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
		}

		Vector3<T>& operator=(const Vector3<T>& v) {
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			return *this;
		}

		void operator+=(const Vector3<T>& v) {
			this->x += v.x;
			this->y += v.y;
			this->z += v.z;
		}

		Vector3<T> operator+(const Vector3<T>& v) const {
			return Vector3<T>(this->x + v.x, this->y + v.y, this->z + v.z);
		}

		void operator-=(const Vector3<T>& v) {
			this->x -= v.x;
			this->y -= v.y;
			this->z -= v.z;
		}

		Vector3<T> operator-(const Vector3<T>& v) const {
			return Vector3<T>(x - v.x, y - v.y, z - v.z);
		}

		void operator*=(const double& d) {
			this->x *= d;
			this->y *= d;
			this->z *= d;
		}

		Vector3<T> operator*(const double& d) const {
			return Vector3<T>(x * d, y * d, z * d);
		}

		void operator/=(const double& d) {
			this->x /= d;
			this->y /= d;
			this->z /= d;
		}

		Vector3<T> operator/(const double& d) const {
			return Vector3<T>(this->x / d, this->y / d, this->z / d);
		}

		/// @brief set this vector equal to the cross product with another vector
		/// @param v the vector to multiply with
		void operator%=(const Vector3<T>& v) {
			*this = this->cross(v);
		}

		/// @brief calculate the cross product of two vectors
		/// @param v the vector to multiply with
		/// @return the vector resulting from the calculation
		Vector3<T> operator %(const Vector3<T>& v) const {
			return Vector3<T>(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z, this->x * v.y - this->y * v.x);
		}

		/// @brief calculate the cross product of two vectors
		/// @param v the vector to multiply with
		/// @return the vector resulting from the calculation
		Vector3<T> cross(const Vector3<T>& v) const {
			return Vector3<T>(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z, this->x * v.y - this->y * v.x);
		}

		/// @brief calculate the dot product of two vectors
		/// @param v the vector to multiply with
		/// @return the scalar resulting from the calculation
		double operator*(const Vector3<T>& v) const {
			return this->x * v.x + this->y * v.y + this->z * v.z;
		}

		/// @brief calculate the dot product of two vectors
		/// @param v the vector to multiply with
		/// @return the scalar resulting from the calculation
		double dot(const Vector3<T>& v) const {
			return this->x * v.x + this->y * v.y + this->z * v.z;
		}
	};
}

#endif