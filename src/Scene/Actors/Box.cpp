
#include "Box.h"

Box::Box() {

	// White side - BACK
	Polygon back = Polygon();
	back.setColor(Vector3f(1.0, 1.0, 1.0));
	back.addVertex(Vector3f(0.5, -0.5, 0.5));
	back.addVertex(Vector3f(0.5, 0.5, 0.5));
	back.addVertex(Vector3f(-0.5, 0.5, 0.5));
	back.addVertex(Vector3f(-0.5, -0.5, 0.5));

	// Purple side - RIGHT
	Polygon right = Polygon();
	right.setColor(Vector3f(0.0, 1.0, 1.0));
	right.addVertex(Vector3f(0.5, -0.5, -0.5));
	right.addVertex(Vector3f(0.5, 0.5, -0.5));
	right.addVertex(Vector3f(0.5, 0.5, 0.5));
	right.addVertex(Vector3f(0.5, -0.5, 0.5));

	// Green side - LEFT
	Polygon left = Polygon();
	left.setColor(Vector3f(0.0, 1.0, 1.0));
	left.addVertex(Vector3f(-0.5, -0.5, 0.5)); // 0
	left.addVertex(Vector3f(-0.5, 0.5, 0.5)); // 2
	left.addVertex(Vector3f(-0.5, 0.5, -0.5)); // 3
	left.addVertex(Vector3f(-0.5, -0.5, -0.5)); // 1

	// Blue side - TOP
	Polygon top = Polygon();
	top.setColor(Vector3f(0.0, 0.0, 1.0));
	top.addVertex(Vector3f(0.5, 0.5, 0.5));
	top.addVertex(Vector3f(0.5, 0.5, -0.5));
	top.addVertex(Vector3f(-0.5, 0.5, -0.5));
	top.addVertex(Vector3f(-0.5, 0.5, 0.5));

	// Red side - BOTTOM
	Polygon bottom = Polygon();
	bottom.setColor(Vector3f(1.0, 0.0, 0.0));
	bottom.addVertex(Vector3f(0.5, -0.5, -0.5));
	bottom.addVertex(Vector3f(0.5, -0.5, 0.5));
	bottom.addVertex(Vector3f(-0.5, -0.5, 0.5));
	bottom.addVertex(Vector3f(-0.5, -0.5, -0.5));

	Mesh* box = new Mesh(MeshType::POLYGON);
	box->add(back);
	box->add(right);
	box->add(left);
	box->add(top);
	box->add(bottom);

	MeshComponent* mesh = new MeshComponent(box, 1.f);
	MovementComponent* movement = new MovementComponent();

	this->addComponent(mesh);
	this->addComponent(movement);
}