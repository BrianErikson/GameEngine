#ifndef UTILITIES_POLYGON_H_
#define UTILITIES_POLYGON_H_

#include <vector>
#include "Math\Vector.h"
#include "GL/glew.h"

class Polygon {
	private:
		std::vector<Vector3> verts;
		Color color; 
	public:
		Polygon();
		void addVertex(Vector3 &vert);
		void setColor(Color color);
		void render(const double &deltaTime);
};

#endif // UTILITIES_POLYGON_H_