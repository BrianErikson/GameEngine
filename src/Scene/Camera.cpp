
#include "Camera.h"
#include <iostream>

CameraSettings::CameraSettings(float FOV, float aspectRatio, float near, float far) {
	this->FOV = FOV;
	this->aspectRatio = aspectRatio;
	this->near = near;
	this->far = far;
}

Camera::Camera(Vector3f &position, Vector3f &rotation, CameraSettings &settings) : settings(settings) {
	this->movementComponent = new MovementComponent();
	this->movementComponent->setWorldPosition(position);
	this->movementComponent->setRotation(rotation);
	this->addComponent(this->movementComponent);
}

Camera::~Camera() {

}

void Camera::render(const double &deltaTime) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(this->settings.FOV, this->settings.aspectRatio, this->settings.near, this->settings.far);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Transform<float, 3, 2, 0> transform = this->movementComponent->getTransform();
	glLoadMatrixf(transform.data());
}