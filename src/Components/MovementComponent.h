#ifndef COMPONENTS_MOVEMENTCOMPONENT_H_
#define COMPONENTS_MOVEMENTCOMPONENT_H_

#include "ActorComponent.h"
#include "../Utilities/Math/Vector.h"
#include "../Utilities/Math/Matrix.h"

class MovementComponent : public ActorComponent {
	private:
		Matrix translation;
		Matrix rotation;
		Matrix scale;
		Matrix identity;
		Matrix transform;
		bool isDirty;
		std::string test;
	public:
		MovementComponent();
		void updateTransform();
		void translate(Vector3 &vec);
		void rotate(Vector3 &rotator);
		void setLocalPosition(Vector3 &position);
		void setWorldPosition(Vector3 &position);
		void setRotation(Vector3 &rotation);
		Vector3 getLocalPosition();
		Vector3 getWorldPosition();
		Vector3 getRotation();
		Matrix getTransform();
		virtual void tick(const double &deltaTime) override;
};

#endif // COMPONENTS_MOVEMENTCOMPONENT_H_