
#pragma once

#include "Actor.h"
#include "Eigen"
#include "../Components/MovementComponent.h"

using Eigen::Vector3f;

struct CameraSettings {
	CameraSettings(float FOV, float aspectRatio, float near, float far);
	float FOV;
	float aspectRatio;
	float near;
	float far;
};

class Camera : public Actor {
	private:
		MovementComponent* movementComponent;
		CameraSettings settings;
	public:
		Camera(Vector3f &position, Vector3f &rotation, CameraSettings &settings);
		~Camera();
		virtual void render(const double &deltaTime) override;
};