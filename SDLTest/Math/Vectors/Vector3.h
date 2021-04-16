#ifndef GBM_VECTOR3_H_
#define GBM_VECTOR3_H_

namespace GBM {
	template<class T> class Vector3 {
	private:

	public:

		// attributes

		T x;
		T y;
		T z;

		// constructors

		Vector3<T>() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
		}

		Vector3<T>(T x, T y, T z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		// destructor
		~Vector3() {

		}

		// functions

		double magnitude() {
			return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
		}

		void normalize() {
			double mag = this->magnitude();
			if (mag > 0.0) {
				double oneovermag = 1.0 / mag;
				this->x = this->x * oneovermag;
				this->y = this->y * oneovermag;
				this->z = this->z * oneovermag;
			}
		}

		double operator[](const int index) {
			switch (index) {
			case 0:
				return this->x;
			case 1:
				return this->y;
			case 2:
				return this->z;
			default:
				throw "GBM::Vector3 index out of bounds!";
				return 0.0;
			}
		}

		// copy constructors

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

		// math operators

		void operator+=(const Vector3<T>& v) {
			this->x += v.x;
			this->y += v.y;
			this->z += v.z;
		}

		Vector3 operator+(const Vector3& v) const {
			return Vector3d(this->x + v.x, this->y + v.y, this->z + v.z);
		}

		void operator-=(const Vector3& v) {
			this->x -= v.x;
			this->y -= v.y;
			this->z -= v.z;
		}

		Vector3<T> operator-(const Vector3<T>& v) const {
			return Vector3d<T>(x - v.x, y - v.y, z - v.z);
		}

		void operator*=(const double& d) {
			this->x *= d;
			this->y *= d;
			this->z *= d;
		}

		Vector3<T> operator*(const double& d) const {
			return Vector3d<T>(x * d, y * d, z * d);
		}

		void operator/=(const double& d) {
			this->x /= d;
			this->y /= d;
			this->z /= d;
		}

		Vector3<T> operator/(const double& d) const {
			return Vector3d<T>(this->x / d, this->y / d, this->z / d);
		}

		void operator%=(const Vector3<T>& v) {
			*this = this->cross(v);
		}

		Vector3<T> operator %(const Vector3<T>& v) const {
			return Vector3d<T>(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z, this->x * v.y - this->y * v.x);
		}

		Vector3<T> cross(const Vector3<T>& v) const {
			return Vector3d<T>(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z, this->x * v.y - this->y * v.x);
		}

		double operator*(const Vector3<T>& v) const {
			return this->x * v.x + this->y * v.y + this->z * v.z;
		}

		double dot(const Vector3<T>& v) const {
			return this->x * v.x + this->y * v.y + this->z * v.z;
		}
	};
}

#endif