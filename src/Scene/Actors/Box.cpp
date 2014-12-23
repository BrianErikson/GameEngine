
#include "Box.h"

Box::Box() {

	// White side - BACK
	Polygon back = Polygon();
	back.setColor(Color(EColor::WHITE));
	back.addVertex(Vector3(0.5, -0.5, 0.5));
	back.addVertex(Vector3(0.5, 0.5, 0.5));
	back.addVertex(Vector3(-0.5, 0.5, 0.5));
	back.addVertex(Vector3(-0.5, -0.5, 0.5));

	// Purple side - RIGHT
	Polygon right = Polygon();
	right.setColor(Color(EColor::PURPLE));
	right.addVertex(Vector3(0.5, -0.5, -0.5));
	right.addVertex(Vector3(0.5, 0.5, -0.5));
	right.addVertex(Vector3(0.5, 0.5, 0.5));
	right.addVertex(Vector3(0.5, -0.5, 0.5));

	// Green side - LEFT
	Polygon left = Polygon();
	left.setColor(Color(EColor::GREEN));
	left.addVertex(Vector3(-0.5, -0.5, 0.5));
	left.addVertex(Vector3(-0.5, 0.5, 0.5));
	left.addVertex(Vector3(-0.5, 0.5, -0.5));
	left.addVertex(Vector3(-0.5, -0.5, -0.5));

	// Blue side - TOP
	Polygon top = Polygon();
	top.setColor(Color(EColor::BLUE));
	top.addVertex(Vector3(0.5, 0.5, 0.5));
	top.addVertex(Vector3(0.5, 0.5, -0.5));
	top.addVertex(Vector3(-0.5, 0.5, -0.5));
	top.addVertex(Vector3(-0.5, 0.5, 0.5));

	// Red side - BOTTOM
	Polygon bottom = Polygon();
	bottom.setColor(Color(EColor::RED));
	bottom.addVertex(Vector3(0.5, -0.5, -0.5));
	bottom.addVertex(Vector3(0.5, -0.5, 0.5));
	bottom.addVertex(Vector3(-0.5, -0.5, 0.5));
	bottom.addVertex(Vector3(-0.5, -0.5, -0.5));

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