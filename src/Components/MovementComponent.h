#ifndef COMPONENTS_MOVEMENTCOMPONENT_H_
#define COMPONENTS_MOVEMENTCOMPONENT_H_

#include "ActorComponent.h"
#include <Eigen>

using Eigen::Vector3f;
using Eigen::Translation3f;
using Eigen::Quaternionf;
using Eigen::Matrix4f;
using Eigen::Matrix3f;
using Eigen::Transform;
using Eigen::AngleAxisf;
using Eigen::Affine;

class MovementComponent : public ActorComponent {
	private:
		Transform<float,3, Affine> transform;
	public:
		MovementComponent();
		void updateTransform();
		void translate(Vector3f &vec);
		void rotate(Vector3f &rotator);
		void setLocalPosition(Vector3f &position);
		void setWorldPosition(Vector3f &position);
		void setRotation(Vector3f &rotation);
		Vector3f getLocalPosition();
		Vector3f getWorldPosition();
		Quaternionf getRotation();
		Transform<float, 3, Affine> getTransform();
		virtual void tick(const double &deltaTime) override;
};

#endif // COMPONENTS_MOVEMENTCOMPONENT_H_