#pragma once
#include <vector>

namespace GBM {
	class iMatrix
	{
	private:
		std::vector<std::vector<int>> vmatrix;
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
		std::vector<int>& operator[](const int index);

		void operator+=(const iMatrix& m);
		iMatrix operator+(const iMatrix& m) const;

		void operator-=(const iMatrix& m);
		iMatrix operator-(const iMatrix& m) const;

		void operator*=(const int s);
		iMatrix operator*(const int s);


	};
}