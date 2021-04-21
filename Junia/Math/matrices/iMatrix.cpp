#include "iMatrix.h"

Junia::iMatrix::iMatrix()
{
	this->s1 = 1;
	this->s2 = 1;
	this->vmatrix = new int[1];
	for (int i = 0; i < this->s1 * this->s2; i++) {
		vmatrix[i] = 0;
	}
}

Junia::iMatrix::iMatrix(int s1, int s2)
{
	this->s1 = s1;
	this->s2 = s2;
	this->vmatrix = new int[s1 * s2];
	for (int i = 0; i < this->s1 * this->s2; i++) {
		vmatrix[i] = 0;
	}
}

Junia::iMatrix::~iMatrix()
{
	delete[] this->vmatrix;
}

Junia::iMatrix::iMatrix(const iMatrix& m)
{
	this->vmatrix = new int[m.s1 * m.s2];
	for (int i = 0; i < m.s1 * m.s2; i++) {
		this->vmatrix[i] = m.vmatrix[i];
	}
	this->s1 = m.s1;
	this->s2 = m.s2;
}

Junia::iMatrix& Junia::iMatrix::operator=(const iMatrix& m)
{
	delete[] this->vmatrix;
	this->vmatrix = new int[m.s1 * m.s2];
	for (int i = 0; i < m.s1 * m.s2; i++) {
		this->vmatrix[i] = m.vmatrix[i];
	}
	this->s1 = m.s1;
	this->s2 = m.s2;
	return *this;
}

int& Junia::iMatrix::operator()(const int p1, const int p2)
{
	return this->at(p1, p2);
}

int& Junia::iMatrix::at(const int p1, const int p2)
{
	if (p1 >= this->s1 || p1 < 0 || p2 >= this->s2 || p2 < 0) throw "Index out of range!";
	return vmatrix[(p1 * s2) + p2];
}

void Junia::iMatrix::operator+=(const Junia::iMatrix& m)
{
	if (this->s1 != m.s1 || this->s2 != m.s2) throw "Cannot add two matrices of different sizes!";
	for (int i = 0; i < this->s1 * this->s2; i++) {
		this->vmatrix[i] += m.vmatrix[i];
	}
}

Junia::iMatrix Junia::iMatrix::operator+(const Junia::iMatrix& m) const
{
	if (this->s1 != m.s1 || this->s2 != m.s2) throw "Cannot add two matrices of different sizes!";
	Junia::iMatrix retm = Junia::iMatrix(this->s1, this->s2);
	for (int i = 0; i < this->s1 * this->s2; i++) {
		retm.vmatrix[i] = this->vmatrix[i] + m.vmatrix[i];
	}
	return retm;
}

void Junia::iMatrix::operator-=(const Junia::iMatrix& m)
{
	if (this->s1 != m.s1 || this->s2 != m.s2) throw "Cannot subtract two matrices of different sizes!";
	for (int i = 0; i < this->s1 * this->s2; i++) {
		this->vmatrix[i] -= m.vmatrix[i];
	}
}

Junia::iMatrix Junia::iMatrix::operator-(const Junia::iMatrix& m) const
{
	if (this->s1 != m.s1 || this->s2 != m.s2) throw "Cannot subtract two matrices of different sizes!";
	Junia::iMatrix retm = Junia::iMatrix(this->s1, this->s2);
	for (int i = 0; i < this->s1 * this->s2; i++) {
		retm.vmatrix[i] = this->vmatrix[i] - m.vmatrix[i];
	}
	return retm;
}

void Junia::iMatrix::operator*=(const int s)
{
	for (int i = 0; i < this->s1 * this->s2; i++) {
		this->vmatrix[i] *= s;
	}
}

Junia::iMatrix Junia::iMatrix::operator*(const int s) const
{
	Junia::iMatrix retm = Junia::iMatrix(this->s1, this->s2);
	for (int i = 0; i < this->s1 * this->s2; i++) {
		retm.vmatrix[i] = this->vmatrix[i] * s;
	}
	return retm;
}

void Junia::iMatrix::operator/=(const int s)
{
	for (int i = 0; i < this->s1 * this->s2; i++) {
		this->vmatrix[i] /= s;
	}
}

Junia::iMatrix Junia::iMatrix::operator/(const int s) const
{
	Junia::iMatrix retm = Junia::iMatrix(this->s1, this->s2);
	for (int i = 0; i < this->s1 * this->s2; i++) {
		retm.vmatrix[i] = this->vmatrix[i] / s;
	}
	return retm;
}

void Junia::iMatrix::operator*=(const Junia::iMatrix& m)
{
	if (this->s2 != m.s1) throw "The amount of columns for the first matrix must be equal to the amount of rows of the second matrix!";
	int* pm = new int[this->s1 * m.s2];
	for (int i = 0; i < this->s1 * m.s2; i++) {
		pm[i] = 0;
	}

	for (int i = 0; i < this->s1; i++) {
		for (int k = 0; k < m.s2; k++) {
			for (int j = 0; j < this->s2; j++) {
				pm[(i * m.s2) + k] += this->at(i, j) * m.vmatrix[(j * m.s2) + k];
			}
		}
	}

	delete[] vmatrix;
	vmatrix = pm;
	this->s2 = m.s2;
}

Junia::iMatrix Junia::iMatrix::operator*(const Junia::iMatrix& m) const
{
	if (this->s2 != m.s1) throw "The amount of columns for the first matrix must be equal to the amount of rows of the second matrix!";
	Junia::iMatrix retm = Junia::iMatrix(this->s1, m.s2);

	for (int i = 0; i < this->s1; i++) {
		for (int k = 0; k < m.s2; k++) {
			for (int j = 0; j < this->s2; j++) {
				retm(i, k) += this->vmatrix[(i * this->s2) + j] * m.vmatrix[(j * m.s2) + k];
			}
		}
	}
	return retm;
}

Junia::iMatrix& Junia::iMatrix::setAsIdentityMatrix()
{
	if (this->s1 != this->s2) throw "Cannot create an identity matrix for a non-quadratic matrix!";
	for (int i = 0; i < this->s1; i++) {
		for (int j = 0; j < this->s2; j++) {
			if (i == j) {
				this->vmatrix[(i * this->s2) + j] = 1;
			}
			else {
				this->vmatrix[(i * this->s2) + j] = 0;
			}
		}
	}
	return *this;
}

