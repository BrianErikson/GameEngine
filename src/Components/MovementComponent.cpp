
#include "MovementComponent.h"

MovementComponent::MovementComponent() {
	this->type = EActorComponent::MOVEMENT;
	this->identity = Matrix();
	this->translation = Matrix();
	this->scale = Matrix();
	this->transform = Matrix();
	this->isDirty = false;
	this->test = std::string("What the fuck");
}

void MovementComponent::tick(const double &deltaTime) {
	//this->setLocalPosition(Vector3(0.f, 0.f, -5.f));
	this->updateTransform();

	//printf(std::to_string(this->isDirty).c_str());
	//printf(this->transform.toString().c_str());
}

void MovementComponent::updateTransform() {
	if (this->isDirty) {
		//printf(std::string("Updating Transform!!\n").c_str());
		this->transform = this->translation * this->rotation * this->scale;
		//printf(this->translation.toString().c_str());
		//printf(this->rotation.toString().c_str());
		//printf(this->scale.toString().c_str());
		//printf(this->transform.toString().c_str());
		this->isDirty = false;
	}
}

void MovementComponent::translate(Vector3 &vec) {
	this->translation.translate(vec);
	this->isDirty = true;
}

void MovementComponent::rotate(Vector3 &rotator) {
	this->rotation.rotate(rotator);
	this->isDirty = true;
}

void MovementComponent::setLocalPosition(Vector3 &position) {
	this->translation.setPosition(position);
	this->isDirty = true;
}

void MovementComponent::setWorldPosition(Vector3 &position) {
	// TODO: Change to world position -- not local
	this->setLocalPosition(position);
}

void MovementComponent::setRotation(Vector3 &rotation) {
	this->rotation.setRotation(rotation);
	this->isDirty = true;
}

Vector3 MovementComponent::getLocalPosition() {
	return this->translation.getPosition();
}

Vector3 MovementComponent::getWorldPosition() {
	return this->translation.getPosition();
}

Vector3 MovementComponent::getRotation() {
	return this->transform.getEulerAngles();
}

Matrix MovementComponent::getTransform() {
	this->updateTransform();
	return this->transform;
}