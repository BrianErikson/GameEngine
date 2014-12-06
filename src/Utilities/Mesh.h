#ifndef UTILITIES_MESH_H_
#define UTILITIES_MESH_H_

#include <GL\glew.h>
#include <vector>
#include "Math\Vector.h"
#include "Polygon.h"

enum MeshType {
	LINES = GL_LINES,
	LINE_STRIP = GL_LINE_STRIP,
	TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
	TRIANGLE_FAN = GL_TRIANGLE_FAN,
	QUAD_STRIP = GL_QUAD_STRIP,
	POLYGON = GL_POLYGON
};


class Mesh {
	private:
		MeshType type;
		std::vector<Vector3> mesh;
		std::vector<Polygon> polyMesh;
	public:
		Mesh(MeshType type);
		void add(Vector3 vert);
		void add(Polygon polygon);
		void render(const double &deltaTime);
};

class PolyMesh {
	private:
		MeshType type;
		std::vector<Polygon> polyMesh;
	public:
		PolyMesh(MeshType type);
		void addVertex(Vector3 vert);
		void render(const double &deltaTime);

};

#endif //UTILITIES_MESH_H_