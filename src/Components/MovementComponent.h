#ifndef COMPONENTS_MOVEMENTCOMPONENT_H_
#define COMPONENTS_MOVEMENTCOMPONENT_H_

#include "ActorComponent.h"
#include "../Utilities/Math/Vector.h"
#include "../Utilities/Math/Matrix.h"

class MovementComponent : public ActorComponent {
	private:
		Vector3 position;
		Matrix matrix;
		Matrix identity;
		Matrix rotation;
		Matrix translation;
	public:
		MovementComponent();
		virtual void tick(const double &deltaTime) override;
		virtual void render(const double &deltaTime) override;
		void translate(Vector3 &vec);
		void rotate(Vector3 &rotator);
		Vector3 getPos();
};

#endif // COMPONENTS_MOVEMENTCOMPONENT_H_