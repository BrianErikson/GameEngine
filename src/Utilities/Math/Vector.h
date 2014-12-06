#ifndef UTILITIES_MATH_VECTOR_H_
#define UTILITIES_MATH_VECTOR_H_

#include <cmath>
#include <string>

class Vector2 {
	public:
		Vector2& operator*(const float& scalar);
		Vector2& operator/(const float& scalar);
		Vector2& operator+(const float& scalar);
		Vector2& operator-(const float& scalar);
		Vector2& operator*(const Vector2& vec);
		Vector2& operator/(const Vector2& vec);
		Vector2& operator+(const Vector2& vec);
		Vector2& operator-(const Vector2& vec);

		float x;
		float y;

		Vector2();
		Vector2(float x, float y);

		float getMagnitude();
		Vector2 getNormalizedVec();
		float dot(Vector2 &vector);
		Vector2 project(Vector2 &vector);
		float wedge(Vector2 &vector);
		Vector2 getPerpendicularVec();
};

class Vector3 {
	public:
		Vector3& operator*(const float& scalar);
		Vector3& operator/(const float& scalar);
		Vector3& operator+(const float& scalar);
		Vector3& operator-(const float& scalar);
		Vector3& operator*(const Vector3& vec);
		Vector3& operator/(const Vector3& vec);
		Vector3& operator+(const Vector3& vec);
		Vector3& operator-(const Vector3& vec);
		std::string toString();

		float x;
		float y;
		float z;

		Vector3();
		Vector3(float x, float y, float z);

		float getMagnitude();
		Vector3 getNormalizedVec();
		float dot(Vector3 &vector);
		Vector3 project(Vector3 &vector);
		Vector3 cross(Vector3 &vector);
};

class Vector4 : public Vector3 {
	public:
		float x;
		float y;
		float z;
		float w;

		Vector4(float x, float y, float z, float w);

		float getMagnitude();
		Vector4 getNormalizedVec();
};

enum EColor {
	BLACK,
	WHITE,
	RED,
	GREEN,
	BLUE,
	PURPLE
};

class Color {
	private:
	float r;
	float g;
	float b;
	float a;
	float getMagnitude();
	public:
	Color();
	Color(Vector4 &color);
	Color(EColor color);
	void setColor(Vector4 &color);
	void setColor(EColor &color);
	Vector4 getColor();
};

#endif // UTILITIES_MATH_VECTOR_H_