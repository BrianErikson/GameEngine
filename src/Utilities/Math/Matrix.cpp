
#include "Matrix.h"

Matrix::Matrix() {
	matrix[0] = Vector4(1, 0, 0, 0);
	matrix[1] = Vector4(0, 1, 0, 0);
	matrix[2] = Vector4(0, 0, 1, 0);
	matrix[3] = Vector4(0, 0, 0, 1);
};

Matrix& Matrix::operator*(Matrix &mat) {
	Matrix result = Matrix();
	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 4; j++) 
			for (int k = 0; k < 4; k++) 
				result.matrix[i][j] += this->matrix[i][k] * mat.matrix[k][j];
	return result;
}

Vector3& Matrix::operator*(const Vector3 &vec) {
	Vector3 result = Vector3();
	result.x = vec.x * matrix[0].x +
		vec.y * matrix[0].y +
		vec.z * matrix[0].z +
		matrix[0].w;
	result.y = vec.x * matrix[1].x +
		vec.y * matrix[1].y +
		vec.z * matrix[1].z +
		matrix[1].w;
	result.z = vec.x * matrix[2].x +
		vec.y * matrix[2].y +
		vec.z * matrix[2].z +
		matrix[2].w;
	return result;
}

Matrix& Matrix::operator*=(Vector3 &vec) {
	Matrix result = *this;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 4; k++)
				result.matrix[i][j] += this->matrix[i][k] * vec[j];

	return result;
}

Matrix& Matrix::operator*=(float &scalar) {
	Matrix result = *this;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 4; k++)
				result.matrix[i][j] += this->matrix[i][k] * scalar;

	return result;
}

Matrix::operator Vector3() {
	Vector4 result = Vector4();
	for (int i = 0; i < 4; i++)
		result[i] = this->matrix[0][i] + this->matrix[1][i] + this->matrix[2][i] + this->matrix[3][i];
	
	return result;
}