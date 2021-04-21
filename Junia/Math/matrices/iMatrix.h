#ifndef JUNIA_IMATRIX_H_
#define JUNIA_IMATRIX_H_

namespace Junia {
	class iMatrix
	{
	private:
		int* vmatrix;
		int s1;
		int s2;
	public:
		// constructors
		iMatrix();
		iMatrix(int s1, int s2);
		// destructor
		~iMatrix();

		// copy constructors
		iMatrix(const iMatrix& v);
		iMatrix& operator=(const iMatrix& m);

		// operators
		int& operator()(const int p1, const int p2);
		int& at(const int p1, const int p2);

		void operator+=(const iMatrix& m);
		iMatrix operator+(const iMatrix& m) const;

		void operator-=(const iMatrix& m);
		iMatrix operator-(const iMatrix& m) const;

		void operator*=(const int s);
		iMatrix operator*(const int s) const;

		void operator/=(const int s);
		iMatrix operator/(const int s) const;

		void operator*=(const iMatrix& m);
		iMatrix operator*(const iMatrix& m) const;

		iMatrix& setAsIdentityMatrix();
	};
}

#endif