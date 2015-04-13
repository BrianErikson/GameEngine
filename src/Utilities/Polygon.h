#ifndef UTILITIES_POLYGON_H_
#define UTILITIES_POLYGON_H_

#include <vector>
#include <Eigen>
#include "GL/glew.h"

using Eigen::Vector3f;

class Polygon {
	private:
		std::vector<Vector3f> verts;
		Vector3f color; 
	public:
		Polygon();
		void addVertex(Vector3f &vert);
		void setColor(Vector3f color);
		void render(const double &deltaTime);
};

#endif // UTILITIES_POLYGON_H_