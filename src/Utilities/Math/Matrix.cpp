
#include "Matrix.h"

Matrix::Matrix() {
	this->setToIdenitity();
};

void Matrix::resetMatrix() {
	matrix[0] = Vector4(0, 0, 0, 0);
	matrix[1] = Vector4(0, 0, 0, 0);
	matrix[2] = Vector4(0, 0, 0, 0);
	matrix[3] = Vector4(0, 0, 0, 0);
}

void Matrix::setToIdenitity() {
	matrix[0] = Vector4(1, 0, 0, 0);
	matrix[1] = Vector4(0, 1, 0, 0);
	matrix[2] = Vector4(0, 0, 1, 0);
	matrix[3] = Vector4(0, 0, 0, 1);
}

Matrix& Matrix::operator*(Matrix &mat) {
	Matrix result = Matrix();
	result.resetMatrix();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				result.matrix[i][j] += this->matrix[i][k] * mat.matrix[k][j];
			}
		}
	}
	return result;
}

Matrix& Matrix::operator*=(Matrix &mat) {
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

void Matrix::rotate(Vector3 &rotator) {
	if (rotator.x != 0) {
		this->matrix[1][1] = cos(rotator.x);
		this->matrix[1][2] = sin(rotator.x);
		this->matrix[2][1] = -sin(rotator.x);
		this->matrix[2][2] = cos(rotator.x);
	}
	if (rotator.y != 0) {
		this->matrix[0][0] = cos(rotator.y);
		this->matrix[0][2] = -sin(rotator.y);
		this->matrix[2][0] = sin(rotator.y);
		this->matrix[2][2] = cos(rotator.y);
	}
	if (rotator.z != 0) {
		this->matrix[0][0] = cos(rotator.z);
		this->matrix[0][1] = sin(rotator.z);
		this->matrix[1][0] = -sin(rotator.z);
		this->matrix[1][1] = cos(rotator.z);
	}
}

void Matrix::setRotation(Vector3 &rotator) {
	this->setToIdenitity();
	this->rotate(rotator);
}

void Matrix::translate(Vector3 &vector) {
	this->matrix[0][3] += vector.x;
	this->matrix[1][3] += vector.y;
	this->matrix[2][3] += vector.z;
}

void Matrix::setPosition(Vector3 &pos) {
	this->matrix[0][3] = pos.x;
	this->matrix[1][3] = pos.y;
	this->matrix[2][3] = pos.z;
}

void Matrix::setScale(int scale) {
	this->matrix[0][0] = scale;
	this->matrix[1][1] = scale;
	this->matrix[2][2] = scale;
}

Vector3 Matrix::getPosition() {
	Vector4 pos;

	pos.x = this->matrix[0][3];
	pos.y = this->matrix[1][3];
	pos.z = this->matrix[2][3];

	return Vector3(pos.x, pos.y, pos.z);
}

Vector3 Matrix::getEulerAngles() {
	Vector3 rot;

	rot.x = atan2(this->matrix[1][2], this->matrix[2][2]);
	rot.y = atan2(-(this->matrix[0][2]), sqrt(this->matrix[1][2] + this->matrix[2][2]));
	rot.z = atan2(this->matrix[0][1], this->matrix[0][0]);

	return rot;
}

std::string Matrix::toString() {
	std::string str = std::string("");
	str += std::string("[") + std::to_string(this->matrix[0][0]) + std::string(" ") + std::to_string(this->matrix[0][1]) + std::string(" ")
		+ std::to_string(this->matrix[0][2]) + std::string(" ") + std::to_string(this->matrix[0][3]) + std::string("\n");
	str += std::string(" ") + std::to_string(this->matrix[1][0]) + std::string(" ") + std::to_string(this->matrix[1][1]) + std::string(" ")
		+ std::to_string(this->matrix[1][2]) + std::string(" ") + std::to_string(this->matrix[1][3]) + std::string("\n");
	str += std::string(" ") + std::to_string(this->matrix[2][0]) + std::string(" ") + std::to_string(this->matrix[2][1]) + std::string(" ")
		+ std::to_string(this->matrix[2][2]) + std::string(" ") + std::to_string(this->matrix[2][3]) + std::string("\n");
	str += std::string(" ") + std::to_string(this->matrix[3][0]) + std::string(" ") + std::to_string(this->matrix[3][1]) + std::string(" ")
		+ std::to_string(this->matrix[3][2]) + std::string(" ") + std::to_string(this->matrix[3][3]) + std::string("]\n");

	return str;
}