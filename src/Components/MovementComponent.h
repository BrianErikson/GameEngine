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
		Matrix scale;
		Matrix rotation;
		Matrix translation;
	public:
		MovementComponent();
		void translate(Vector3 &vec);
		Vector3 getPos();
};

#endif // COMPONENTS_MOVEMENTCOMPONENT_H_