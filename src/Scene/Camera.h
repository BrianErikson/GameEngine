
#pragma once

#include "Actor.h"
#include "../Utilities/Math/Vector.h"
#include "../Components/MovementComponent.h"

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
		Camera(Vector3 &position, Vector3 &rotation, CameraSettings &settings);
		~Camera();
		virtual void tick(const double &deltaTime) override;
		virtual void render(const double &deltaTime) override;
};