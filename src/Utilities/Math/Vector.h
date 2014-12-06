#ifndef UTILITIES_MATH_VECTOR_H_
#define UTILITIES_MATH_VECTOR_H_

#include <cmath>

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

		int x;
		int y;

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

		int x;
		int y;
		int z;

		float getMagnitude();
		Vector3 getNormalizedVec();
		float dot(Vector3 &vector);
		Vector3 project(Vector3 &vector);
		float wedge(Vector3 &vector);
		Vector3 getPerpendicularVec();
};

class Vector4 : public Vector3 {
	public:
		int x;
		int y;
		int z;
		int w;
};

#endif // UTILITIES_MATH_VECTOR_H_