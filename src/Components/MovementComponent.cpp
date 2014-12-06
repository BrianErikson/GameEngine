
#include "MovementComponent.h"

MovementComponent::MovementComponent() {
	this->position = Vector3(0,0,0);
	this->identity = Matrix();
	this->matrix = Matrix();
}

void MovementComponent::translate(Vector3 &vec) {
	this->translation *= vec;
}

Vector3 MovementComponent::getPos() {
	return this->translation;
}