
#include "Vector.h"

Vector2& Vector2::operator*(const float& scalar) {
	Vector2 result = *this;
	result.x *= scalar;
	result.y *= scalar;
	return result;
}

Vector2& Vector2::operator/(const float& scalar) {
	Vector2 result = *this;
	result.x *= scalar;
	result.y *= scalar;
	return result;
}

Vector2& Vector2::operator+(const float& scalar) {
	Vector2 result = *this;
	result.x += scalar;
	result.y += scalar;
	return result;
}

Vector2& Vector2::operator-(const float& scalar) {
	Vector2 result = *this;
	result.x -= scalar;
	result.y -= scalar;
	return result;

}

Vector2& Vector2::operator*(const Vector2& vec) {
	Vector2 result = *this;
	result.x *= vec.x;
	result.y *= vec.y;
	return result;
}

Vector2& Vector2::operator/(const Vector2& vec) {
	Vector2 result = *this;
	result.x /= vec.x;
	result.y /= vec.y;
	return result;
}

Vector2& Vector2::operator+(const Vector2& vec) {
	Vector2 result = *this;
	result.x += vec.x;
	result.y += vec.y;
	return result;
}

Vector2& Vector2::operator-(const Vector2& vec) {
	Vector2 result = *this;
	result.x -= vec.x;
	result.y -= vec.y;
	return result;
}

/** Return the magnitude of the x and y axis
*/
float Vector2::getMagnitude() {
	return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

Vector2 Vector2::getNormalizedVec() {
	Vector2 norm = *this;
	float mag = norm.getMagnitude();
	norm.x /= mag;
	norm.y /= mag;
	return norm;
}

float Vector2::dot(Vector2 &vector) {
	Vector2 norm = this->getNormalizedVec();
	Vector2 target = vector.getNormalizedVec();
	return norm.x * target.x + norm.y * target.y;
}

Vector2 Vector2::project(Vector2 &vector) {
	return *this * this->dot(vector);
}

float Vector2::wedge(Vector2 &vector) {
	return this->x*vector.y - this->y*vector.x;
}

/** Preserves length and returns a perpendicular vector to this one
*/
Vector2 Vector2::getPerpendicularVec() {
	Vector2 perp = *this;
	perp.y = perp.x;
	perp.x = -perp.x;
	return perp;
}

/**
	------------------------------------
					Vector3
	------------------------------------
*/

Vector3& Vector3::operator*(const float& scalar) {
	Vector3 result = *this;
	result.x *= scalar;
	result.y *= scalar;
	return result;
}

Vector3& Vector3::operator/(const float& scalar) {
	Vector3 result = *this;
	result.x *= scalar;
	result.y *= scalar;
	return result;
}

Vector3& Vector3::operator+(const float& scalar) {
	Vector3 result = *this;
	result.x += scalar;
	result.y += scalar;
	return result;
}

Vector3& Vector3::operator-(const float& scalar) {
	Vector3 result = *this;
	result.x -= scalar;
	result.y -= scalar;
	return result;
}

Vector3& Vector3::operator*(const Vector3& vec) {
	Vector3 result = *this;
	result.x *= vec.x;
	result.y *= vec.y;
	return result;
}

Vector3& Vector3::operator/(const Vector3& vec) {
	Vector3 result = *this;
	result.x /= vec.x;
	result.y /= vec.y;
	return result;
}

Vector3& Vector3::operator+(const Vector3& vec) {
	Vector3 result = *this;
	result.x += vec.x;
	result.y += vec.y;
	return result;
}

Vector3& Vector3::operator-(const Vector3& vec) {
	Vector3 result = *this;
	result.x -= vec.x;
	result.y -= vec.y;
	return result;
}

/** Return the magnitude of the x and y axis
*/
float Vector3::getMagnitude() {
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

Vector3 Vector3::getNormalizedVec() {
	Vector3 norm = *this;
	float mag = norm.getMagnitude();
	norm.x, norm.y, norm.z /= mag;
	return norm;
}

float Vector3::dot(Vector3 &vector) {
	Vector3 norm = this->getNormalizedVec();
	Vector3 target = vector.getNormalizedVec();
	return norm.x * target.x + norm.y * target.y + norm.z * target.z;
}

Vector3 Vector3::project(Vector3 &vector) {
	return *this * this->dot(vector);
}

/** Returns the cross product between two vectors
*/
Vector3 Vector3::cross(Vector3 &vector) {
	Vector3 a = this->getNormalizedVec();
	Vector3 b = this->getNormalizedVec();
	Vector3 result = Vector3();
	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return result;
}