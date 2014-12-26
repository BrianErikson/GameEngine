
#include "Camera.h"

CameraSettings::CameraSettings(float FOV, float aspectRatio, float near, float far) {
	this->FOV = FOV;
	this->aspectRatio = aspectRatio;
	this->near = near;
	this->far = far;
}

Camera::Camera(Vector3 &position, Vector3 &rotation, CameraSettings &settings) : settings(settings) {
	this->movementComponent = new MovementComponent();
	this->movementComponent->setWorldPosition(position);
	this->movementComponent->setRotation(rotation);
	this->addComponent(this->movementComponent);
	this->tmp = true;
}

Camera::~Camera() {

}

void Camera::render(const double &deltaTime) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(this->settings.FOV, this->settings.aspectRatio, this->settings.near, this->settings.far);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Vector3 pos = this->movementComponent->getLocalPosition();
	glTranslatef(pos.x, pos.y, pos.z);

	Vector3 rot = this->movementComponent->getRotation();
	glRotatef(rot.x, rot.y, rot.z, 1.f);

	if (this->tmp) {
		Matrix pos = Matrix();
		Matrix rot = Matrix();
		Matrix scale = Matrix();
		Matrix transform = Matrix();

		pos.setPosition(Vector3(5.f, -10.f, -5.f));
		rot.setRotation(Vector3(60.f, 30.f, 10.f));
		scale.setScale(1);

		transform = rot * scale;
		printf(scale.toString().c_str());
		printf(rot.toString().c_str());
		printf(pos.toString().c_str());
		printf(transform.toString().c_str());
		this->tmp = false;
	}
}