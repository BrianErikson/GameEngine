
#include "MovementComponent.h"

MovementComponent::MovementComponent() {
	this->type = EActorComponent::MOVEMENT;
	this->identity = Matrix();
	this->translation = this->identity;
	this->scale = this->identity;
}

void MovementComponent::tick(const double &deltaTime) {
	this->local = this->translation * this->rotation * this->scale;

	// TODO: Calculate world matrix;
	this->world = this->local;
}

void MovementComponent::render(const double &deltaTime) {

}

void MovementComponent::translate(Vector3 &vec) {
	this->translation.translate(vec);
}

void MovementComponent::rotate(Vector3 &rotator) {
	this->rotation.rotate(rotator);
}

void MovementComponent::setLocalPosition(Vector3 &position) {
	this->translation *= this->identity;
	this->translation.translate(position);
}

void MovementComponent::setWorldPosition(Vector3 &position) {
	// TODO: Change to world position -- not local
	this->setLocalPosition(position);
}

void MovementComponent::setRotation(Vector3 &rotation) {
	this->rotation *= this->identity;
	this->rotation.rotate(rotation);
}

Vector3 MovementComponent::getLocalPosition() {
	// Not working
	//return this->local.getPosition();
	return this->translation.getPosition();
}

Vector3 MovementComponent::getWorldPosition() {
	return this->world.getPosition();
}

Vector3 MovementComponent::getRotation() {
	return this->world.getEulerAngles();
}