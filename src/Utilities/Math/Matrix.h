#ifndef UTILITIES_MATH_MATRIX_H_
#define UTILITIES_MATH_MATRIX_H_

#include "Vector.h"
#include <cmath>

class Matrix {
	public:
		Vector4 matrix[4];
		Matrix();
		Matrix& operator*(Matrix &mat);
		Vector3& operator*(const Vector3 &vec);
		Matrix& operator*=(Vector3 &vec);
		Matrix& operator*=(float &scalar);
		operator Vector3();
};

#endif // UTILITIES_MATH_MATRIX_H_