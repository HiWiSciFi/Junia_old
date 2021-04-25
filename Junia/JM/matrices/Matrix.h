#ifndef JUNIA_MATRIX_H_
#define JUNIA_MATRIX_H_

namespace JM {
	template<class T> class Matrix {
	private:
		/// @brief the array holding the matrix content
		T* vmatrix;
		/// @brief the x size of the matrix
		int s1;
		/// @brief the y size of the matrix
		int s2;
	public:
		/// @brief the default constructor creating a matrix with one element containing 0
		Matrix<T>() {
			this->s1 = 1;
			this->s2 = 1;
			this->vmatrix = new T[1];
			vmatrix[0] = 0;
		}

		/// @brief create a matrix with a given size and set contents to 0
		/// @param s1 x size of the matrix
		/// @param s2 y size of the matrix
		Matrix<T>(int s1, int s2) {
			if (s1 <= 0 || s2 <= 0) throw "Matrix has to be larger than 0 in both dimensions!";
			this->s1 = s1;
			this->s2 = s2;
			this->vmatrix = new T[s1 * s2];
			for (int i = 0; i < this->s1 * this->s2; i++) {
				vmatrix[i] = 0;
			}
		}

		// destructor
		~Matrix() {
			delete[] this->vmatrix;
		}

		/// @brief create a matrix by copying values from another matrix
		/// @param m the matrix to copy the attributes from
		Matrix<T>(const Matrix<T>& m) {
			this->vmatrix = new T[m.s1 * m.s2];
			for (int i = 0; i < m.s1 * m.s2; i++) {
				this->vmatrix[i] = m.vmatrix[i];
			}
			this->s1 = m.s1;
			this->s2 = m.s2;
		}

		/// @brief set the matrix equal to another matrix
		/// @param m the matrix to copy the attributes from
		/// @return a reference to the matrix the attributes have been copied to
		Matrix<T>& operator=(const Matrix<T>& m) {
			delete[] this->vmatrix;
			this->vmatrix = new T[m.s1 * m.s2];
			for (int i = 0; i < m.s1 * m.s2; i++) {
				this->vmatrix[i] = m.vmatrix[i];
			}
			this->s1 = m.s1;
			this->s2 = m.s2;
			return *this;
		}

		/// @brief access an element of the matrix
		/// @param p1 the x position of the element
		/// @param p2 the x position of the element
		/// @return a reference to the given element
		T& operator()(const int p1, const int p2) {
			return this->at(p1, p2);
		}

		/// @brief access an element of the matrix
		/// @param p1 the x position of the element
		/// @param p2 the x position of the element
		/// @return a reference to the given element
		T& at(const int p1, const int p2) {
			if (p1 >= this->s1 || p1 < 0 || p2 >= this->s2 || p2 < 0) throw "Index out of range!";
			return vmatrix[(p1 * s2) + p2];
		}

		void operator+=(const Matrix<T>& m) {
			if (this->s1 != m.s1 || this->s2 != m.s2) throw "Cannot add two matrices of different sizes!";
			for (int i = 0; i < this->s1 * this->s2; i++) {
				this->vmatrix[i] += m.vmatrix[i];
			}
		}

		Matrix<T> operator+(const Matrix<T>& m) const {
			if (this->s1 != m.s1 || this->s2 != m.s2) throw "Cannot add two matrices of different sizes!";
			Matrix<T> retm = Matrix<T>(this->s1, this->s2);
			for (int i = 0; i < this->s1 * this->s2; i++) {
				retm.vmatrix[i] = this->vmatrix[i] + m.vmatrix[i];
			}
			return retm;
		}

		void operator-=(const Matrix<T>& m) {
			if (this->s1 != m.s1 || this->s2 != m.s2) throw "Cannot subtract two matrices of different sizes!";
			for (int i = 0; i < this->s1 * this->s2; i++) {
				this->vmatrix[i] -= m.vmatrix[i];
			}
		}

		Matrix<T> operator-(const Matrix<T>& m) const {
			if (this->s1 != m.s1 || this->s2 != m.s2) throw "Cannot subtract two matrices of different sizes!";
			Matrix<T> retm = Matrix<T>(this->s1, this->s2);
			for (int i = 0; i < this->s1 * this->s2; i++) {
				retm.vmatrix[i] = this->vmatrix[i] - m.vmatrix[i];
			}
			return retm;
		}

		void operator*=(const int s) {
			for (int i = 0; i < this->s1 * this->s2; i++) {
				this->vmatrix[i] *= s;
			}
		}

		Matrix<T> operator*(const int s) const {
			Matrix<T> retm = Matrix<T>(this->s1, this->s2);
			for (int i = 0; i < this->s1 * this->s2; i++) {
				retm.vmatrix[i] = this->vmatrix[i] * s;
			}
			return retm;
		}

		void operator/=(const int s) {
			for (int i = 0; i < this->s1 * this->s2; i++) {
				this->vmatrix[i] /= s;
			}
		}

		Matrix<T> operator/(const int s) const {
			Matrix<T> retm = Matrix<T>(this->s1, this->s2);
			for (int i = 0; i < this->s1 * this->s2; i++) {
				retm.vmatrix[i] = this->vmatrix[i] / s;
			}
			return retm;
		}

		void operator*=(const Matrix<T>& m) {
			if (this->s2 != m.s1) throw "The amount of columns for the first matrix must be equal to the amount of rows of the second matrix!";
			T* pm = new T[this->s1 * m.s2];
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

		Matrix<T> operator*(const Matrix<T>& m) const {
			if (this->s2 != m.s1) throw "The amount of columns for the first matrix must be equal to the amount of rows of the second matrix!";
			Matrix<T> retm = Matrix<T>(this->s1, m.s2);

			for (int i = 0; i < this->s1; i++) {
				for (int k = 0; k < m.s2; k++) {
					for (int j = 0; j < this->s2; j++) {
						retm(i, k) += this->vmatrix[(i * this->s2) + j] * m.vmatrix[(j * m.s2) + k];
					}
				}
			}
			return retm;
		}

		/// @brief set this matrix as the identity matrix of itself
		/// @return a reference to thae changed matrix
		Matrix<T>& setAsIdentityMatrix() {
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
	};
}

#endif