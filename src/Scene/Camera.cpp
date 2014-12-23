
#include "Camera.h"

CameraSettings::CameraSettings(float FOV, float aspectRatio, float near, float far) {
	this->FOV = FOV;
	this->aspectRatio = aspectRatio;
	this->near = near;
	this->far = far;
}

Camera::Camera(Vector3 &position, Vector3 &rotation, CameraSettings &settings) : settings(settings) {
	this->movementComponent = new MovementComponent();
	movementComponent->setPosition(position);
	movementComponent->rotate(rotation);
	this->addComponent(movementComponent);
}

Camera::~Camera() {

}

void Camera::tick(const double &deltaTime) {

}

void Camera::render(const double &deltaTime) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(this->settings.FOV, this->settings.aspectRatio, this->settings.near, this->settings.far);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Vector3 pos = this->movementComponent->getPosition();
	glTranslatef(pos.x, pos.y, pos.z);
	printf((pos.toString() + std::string("\n")).c_str());

	Vector3 rot = this->movementComponent->getRotation();
	glRotatef(rot.x, rot.y, rot.z, 1.f);
}