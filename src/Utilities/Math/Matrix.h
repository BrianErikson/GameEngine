#ifndef UTILITIES_MATH_MATRIX_H_
#define UTILITIES_MATH_MATRIX_H_

#include "Vector.h"
#include <cmath>

class Matrix {
	private:
		Vector4 matrix[4];
	public:
		Matrix();
		Matrix& operator*(Matrix &mat);
		Matrix& operator*=(Matrix &mat);
		Vector3& operator*(const Vector3 &vec);
		Matrix& operator*=(Vector3 &vec);
		Matrix& operator*=(float &scalar);
		operator Vector3();
		void setRotation(Vector3 &rotator);
		void rotate(Vector3 &rotator);
		void translate(Vector3 &vector);
		void setPosition(Vector3 &pos);
		void setScale(int scalar);
		void resetMatrix();
		void setToIdenitity();
		Vector3 getPosition();
		Vector3 getEulerAngles();
		Vector3 getScale();
		std::string toString();
};

#endif // UTILITIES_MATH_MATRIX_H_