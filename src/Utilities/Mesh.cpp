
#include "Mesh.h"

Mesh::Mesh(MeshType type) {
	this->type = type;
}

void Mesh::addVertex(Vector3 vert) {
	this->mesh.push_back(vert);
}

void Mesh::render(const double &deltaTime) {
	//glEnable(GL_DEPTH_TEST);
	glBegin(this->type);
	for (int i = 0; i < this->mesh.size(); i++) {
		Vector3 vert = this->mesh[i];
		glColor3f(0.f, 0.f, 1.f);
		glVertex3f(vert.x, vert.y, vert.z);
	}
	glEnd();
}