#include "iMatrix.h"

GBM::iMatrix::iMatrix()
{
	this->s1 = 1;
	this->s2 = 1;
	std::vector<int> v = { 0 };
	this->vmatrix = { v };
}

GBM::iMatrix::iMatrix(int s1, int s2)
{
	this->s1 = s1;
	this->s2 = s2;
	std::vector<std::vector<int>> vt;
	for (int i = 0; i < this->s2; i++) {
		std::vector<int> v(this->s1);
		vt.push_back(v);
	}
	this->vmatrix = vt;
}

GBM::iMatrix::~iMatrix()
{

}

GBM::iMatrix::iMatrix(const iMatrix& m)
{
	this->vmatrix = m.vmatrix;
	this->s1 = m.s1;
	this->s2 = m.s2;
}

GBM::iMatrix& GBM::iMatrix::operator=(const iMatrix& m)
{
	this->vmatrix = m.vmatrix;
	this->s1 = m.s1;
	this->s2 = m.s2;
	return *this;
}

std::vector<int>& GBM::iMatrix::operator[](const int index)
{
	if (index >= this->s1 || index < 0) throw "GBM::iMatrix[i] index out of range!";
	return this->vmatrix[index];
}

void GBM::iMatrix::operator+=(const GBM::iMatrix& m)
{
	if (this->s1 != m.s1 || this->s2 != m.s2) throw "GBM::iMatrix: cannot add two matrices of different sizes!";
	for (int p1 = 0; p1 < this->s1; p1++) {
		for (int p2 = 0; p2 < this->s2; p2++) {
			this->vmatrix[p1][p2] += m.vmatrix[p1][p2];
		}
	}
}

GBM::iMatrix GBM::iMatrix::operator+(const GBM::iMatrix& m) const
{
	if (this->s1 != m.s1 || this->s2 != m.s2) throw "GBM::iMatrix: cannot add two matrices of different sizes!";
	iMatrix retm = iMatrix(this->s1, this->s2);
	for (int p1 = 0; p1 < this->s1; p1++) {
		for (int p2 = 0; p2 < this->s2; p2++) {
			retm[p1][p2] = this->vmatrix[p1][p2] + m.vmatrix[p1][p2];
		}
	}
	return retm;
}

void GBM::iMatrix::operator-=(const iMatrix& m)
{
	if (this->s1 != m.s1 || this->s2 != m.s2) throw "GBM::iMatrix: cannot subtract two matrices of different sizes!";
	for (int p1 = 0; p1 < this->s1; p1++) {
		for (int p2 = 0; p2 < this->s2; p2++) {
			this->vmatrix[p1][p2] -= m.vmatrix[p1][p2];
		}
	}
}

GBM::iMatrix GBM::iMatrix::operator-(const iMatrix& m) const
{
	if (this->s1 != m.s1 || this->s2 != m.s2) throw "GBM::iMatrix: cannot subtract two matrices of different sizes!";
	iMatrix retm = iMatrix(this->s1, this->s2);
	for (int p1 = 0; p1 < this->s1; p1++) {
		for (int p2 = 0; p2 < this->s2; p2++) {
			retm[p1][p2] = this->vmatrix[p1][p2] - m.vmatrix[p1][p2];
		}
	}
	return retm;
}

void GBM::iMatrix::operator*=(const int s)
{
	for (int p1 = 0; p1 < this->s1; p1++) {
		for (int p2 = 0; p2 < this->s2; p2++) {
			this->vmatrix[p1][p2] *= s;
		}
	}
}

GBM::iMatrix GBM::iMatrix::operator*(const int s)
{
	iMatrix retm = iMatrix(this->s1, this->s2);
	for (int p1 = 0; p1 < this->s1; p1++) {
		for (int p2 = 0; p2 < this->s2; p2++) {
			retm[p1][p2] = this->vmatrix[p1][p2] * s;
		}
	}
	return retm;
}
