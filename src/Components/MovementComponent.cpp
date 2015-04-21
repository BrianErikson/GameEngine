
#include "MovementComponent.h"
#include <iostream>

MovementComponent::MovementComponent() {
	this->type = EActorComponent::MOVEMENT;
	this->transform = Transform<float, 3, Affine>();
	this->transform.setIdentity();
	this->setLocalPosition(Vector3f(0.f, 0.f, -5.f));
}

void MovementComponent::tick(const double &deltaTime) {

}

void MovementComponent::translate(Vector3f &vec) {
	std::cout << this->transform.data() << std::endl << std::endl;
	this->transform.translate(vec);
	std::cout << this->transform.data() << std::endl << std::endl;
}

void MovementComponent::rotate(Vector3f &rotator) {
	Matrix3f m;
	m = AngleAxisf(rotator.x(), Vector3f::UnitZ())
		* AngleAxisf(rotator.y(), Vector3f::UnitY())
		* AngleAxisf(rotator.z(), Vector3f::UnitZ());
	this->transform.rotate(m);
}

void MovementComponent::setLocalPosition(Vector3f &position) {
	this->transform(0, 3) = position.x();
	this->transform(1, 3) = position.y();
	this->transform(2, 3) = position.z();
}

void MovementComponent::setWorldPosition(Vector3f &position) {
	// TODO: Change to world position -- not local
	this->setLocalPosition(position);
}

void MovementComponent::setRotation(Vector3f &rotation) {
	Matrix3f m;
	m = AngleAxisf(rotation.x(), Vector3f::UnitZ())
		* AngleAxisf(rotation.y(), Vector3f::UnitY())
		* AngleAxisf(rotation.z(), Vector3f::UnitZ());
	this->transform.rotate(this->transform.rotation() * -1); // TODO: Make sure this is right. Trying to zeroize
	this->transform.rotate(m);
}

Vector3f MovementComponent::getLocalPosition() {
	return this->transform.translation();
}

Vector3f MovementComponent::getWorldPosition() {
	//TODO: Return something other than local
	return this->getLocalPosition();
}

Quaternionf MovementComponent::getRotation() {
	return Quaternionf(this->transform.rotation());
}

Transform<float, 3, Affine> MovementComponent::getTransform() {
	return this->transform;
}