
#include "Polygon.h"

Polygon::Polygon() {
	this->verts = std::vector<Vector3>();
	this->color = Color();
}

void Polygon::addVertex(Vector3 &vert) {
	this->verts.push_back(vert);
}

void Polygon::setColor(Color color) {
	this->color = color;
}

void Polygon::render(const double &deltaTime) {
	Vector4 color = this->color.getColor();
	glColor3f(color.x, color.y, color.z);
	for (int i = 0; i < this->verts.size(); i++) {
		Vector3 vert = this->verts[i];
		glVertex3f(vert.x, vert.y, vert.z);
		printf(vert.toString().c_str());
	}
}