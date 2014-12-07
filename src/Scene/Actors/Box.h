#ifndef SCENE_ACTORS_BOX_H_
#define SCENE_ACTORS_BOX_H_

#include "../Actor.h"
#include "..\src\Components\MeshComponent.h"
#include "..\src\Components\MovementComponent.h"

class Box : public Actor {
	public:
		Box();
};

#endif // SCENE_ACTORS_BOX_H_