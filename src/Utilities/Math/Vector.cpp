
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

Vector2::Vector2() {
	this->x = 0;
	this->y = 0;
}
Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
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
	result.z *= scalar;
	return result;
}

Vector3& Vector3::operator/(const float& scalar) {
	Vector3 result = *this;
	result.x /= scalar;
	result.y /= scalar;
	result.z /= scalar;
	return result;
}

Vector3& Vector3::operator+(const float& scalar) {
	Vector3 result = *this;
	result.x += scalar;
	result.y += scalar;
	result.z += scalar;
	return result;
}

Vector3& Vector3::operator+=(const float& scalar) {
	Vector3 result = *this;
	result.x += scalar;
	result.y += scalar;
	result.z += scalar;
	return result;
}


Vector3& Vector3::operator-(const float& scalar) {
	Vector3 result = *this;
	result.x -= scalar;
	result.y -= scalar;
	result.z -= scalar;
	return result;
}

Vector3& Vector3::operator*(const Vector3& vec) {
	Vector3 result = *this;
	result.x *= vec.x;
	result.y *= vec.y;
	result.z *= vec.z;
	return result;
}

Vector3& Vector3::operator/(const Vector3& vec) {
	Vector3 result = *this;
	result.x /= vec.x;
	result.y /= vec.y;
	result.z /= vec.z;
	return result;
}

Vector3& Vector3::operator+(const Vector3& vec) {
	Vector3 result = *this;
	result.x += vec.x;
	result.y += vec.y;
	result.z += vec.z;
	return result;
}

Vector3& Vector3::operator+=(const Vector3& vec) {
	Vector3 result = *this;
	result.x += vec.x;
	result.y += vec.y;
	result.z += vec.z;
	return result;
}

std::string Vector3::toString() {
	return ("(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z) + ")").c_str();
}

Vector3::Vector3() {
	this->x = 0.f;
	this->y = 0.f;
	this->z = 0.f;
}
Vector3::Vector3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

float& Vector3::operator[](const int &num) {
	switch (num) {
		case 0:
			return this->x;
		case 1:
			return this->y;
		case 2:
			return this->z;
		default:
			float def = 0.f;
			return def;
	}
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

/**
------------------------------------
				Vector4
------------------------------------
*/
Vector4::Vector4() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}
Vector4::Vector4(float x, float y, float z, float w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

float& Vector4::operator[](const int &num) {
	switch (num) {
		case 0:
			return this->x;
		case 1:
			return this->y;
		case 2:
			return this->z;
		case 3:
			return this->w;
		default:
			float def = 0.f;
			return def;
	}
}

float Vector4::getMagnitude() {
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2) + pow(this->w, 2));
}

Vector4 Vector4::getNormalizedVec() {
	Vector4 norm = *this;
	float mag = norm.getMagnitude();
	norm.x, norm.y, norm.z, norm.w /= mag;
	return norm;
}

/**
------------------------------------
				Color
------------------------------------
*/

Color::Color() {
	this->setColor(Vector4(0.f, 0.f, 0.f, 1.f));
}

/** Creates a new Color. Accepts values between 0-1, or 0-255
*/
Color::Color(Vector4 &color) {
	this->setColor(color);
}

Color::Color(EColor color) {
	this->setColor(color);
}

float Color::getMagnitude() {
	return sqrt(pow(this->r, 2) + pow(this->g, 2) + pow(this->b, 2) + pow(this->a, 2));
}

/** Accepts values between 0-1, or 0-255
*/
void Color::setColor(Vector4 &color) {
	this->r = color.x;
	this->g = color.y;
	this->b = color.z;
	this->a = color.w;
	float mag = this->getMagnitude();
	this->r, this->g, this->b, this->a /= mag;
}

void Color::setColor(EColor &color) {
	switch (color) {
		case EColor::BLACK:
			this->setColor(Vector4(0.f, 0.f, 0.f, 1.f));
			break;
		case EColor::WHITE:
			this->setColor(Vector4(1.f, 1.f, 1.f, 1.f));
			break;
		case EColor::RED:
			this->setColor(Vector4(1.f, 0.f, 0.f, 1.f));
			break;
		case EColor::GREEN:
			this->setColor(Vector4(0.f, 1.f, 0.f, 1.f));
			break;
		case EColor::BLUE:
			this->setColor(Vector4(0.f, 0.f, 1.f, 1.f));
			break;
		case EColor::PURPLE:
			this->setColor(Vector4(1.f, 0.f, 1.f, 1.f));
			break;
	}
}

Vector4 Color::getColor() {
	return Vector4(this->r, this->g, this->b, this->a);
}