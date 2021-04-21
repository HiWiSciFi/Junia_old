#ifndef JUNIA_MATRIX_H_
#define JUNIA_MATRIX_H_

namespace Junia {
	template<class T> class Matrix {
	private:
		T* vmatrix;
		int s1;
		int s2;
	public:
		Matrix<T>();
		Matrix<T>(int s1, int s2);

		~Matrix();

		T& operator()(const int p1, const int p2);
		T& at(const int p1, const int p2);

		void operator+=(const Matrix& m);
		Matrix operator+(const Matrix& m) const;

		void operator-=(const Matrix& m);
		Matrix operator-(const Matrix& m) const;

		void operator*=(const int s);
		Matrix operator*(const int s) const;

		void operator/=(const int s);
		Matrix operator/(const int s) const;

		void operator*=(const Matrix& m);
		Matrix operator*(const Matrix& m) const;

		Matrix& setAsIdentityMatrix();
	};
}

#endif