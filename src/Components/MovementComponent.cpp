
#include "MovementComponent.h"

MovementComponent::MovementComponent() {
	this->type = EActorComponent::MOVEMENT;
	this->position = Vector3(0,0,0);
	this->identity = Matrix();
	this->matrix = Matrix();
}

void MovementComponent::tick(const double &deltaTime) {

}

void MovementComponent::render(const double &deltaTime) {

}

void MovementComponent::translate(Vector3 &vec) {
	this->translation *= vec;
}

void MovementComponent::rotate(Vector3 &rotator) {
	if (rotator.x != 0) {
		this->rotation.matrix[1][1] = cos(rotator.x);
		this->rotation.matrix[1][2] = sin(rotator.x);
		this->rotation.matrix[2][1] = -sin(rotator.x);
		this->rotation.matrix[2][2] = cos(rotator.x);
	}
	if (rotator.y != 0) {
		this->rotation.matrix[0][0] = cos(rotator.y);
		this->rotation.matrix[0][2] = -sin(rotator.y);
		this->rotation.matrix[2][0] = sin(rotator.y);
		this->rotation.matrix[2][2] = cos(rotator.y);
	}
	if (rotator.z != 0) {
		this->rotation.matrix[0][0] = cos(rotator.z);
		this->rotation.matrix[0][1] = sin(rotator.z);
		this->rotation.matrix[1][0] = -sin(rotator.z);
		this->rotation.matrix[1][1] = cos(rotator.z);
	}
}

Vector3 MovementComponent::getPos() {
	return this->translation;
}