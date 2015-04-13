
#include "Mesh.h"

Mesh::Mesh(MeshType type) {
	this->type = type;
	this->mesh = std::vector<Vector3f>();
	this->polyMesh = std::vector<Polygon>();
}

void Mesh::add(Vector3f vert) {
	if (this->type != MeshType::POLYGON) {
		this->mesh.push_back(vert);
	}
}

void Mesh::add(Polygon polygon) {
	if (this->type == MeshType::POLYGON) {
		this->polyMesh.push_back(polygon);
	}
}

void Mesh::render(const double &deltaTime) {
	if (this->type == MeshType::POLYGON) {
		for (int i = 0; i < this->polyMesh.size(); i++) {
			this->polyMesh[i].render(deltaTime);
		}
	}
	// TODO: Add support for drawing verts instead of polygons
	/*
	for (int i = 0; i < this->mesh.size(); i++) {
		Vector3 vert = this->mesh[i];
		glColor3f(0.f, 0.f, 1.f);
		glVertex3f(vert.x, vert.y, vert.z);
	}*/
}