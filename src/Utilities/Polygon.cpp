
#include "Polygon.h"

Polygon::Polygon() {
	this->verts = std::vector<Vector3f>();
	this->color = Vector3f();
}

void Polygon::addVertex(Vector3f &vert) {
	this->verts.push_back(vert);
}

/*RGB between 0.f and 1.f*/
void Polygon::setColor(Vector3f color) {
	this->color = color;
}

void Polygon::render(const double &deltaTime) {
	glBegin(GL_POLYGON);
	glColor3f(color.x(), color.y(), color.z());
	for (int i = 0; i < this->verts.size(); i++) {
		Vector3f vert = this->verts[i];
		glVertex3f(vert.x(), vert.y(), vert.z());
	}
	glEnd();
}