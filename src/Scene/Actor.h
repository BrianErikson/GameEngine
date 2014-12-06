#ifndef SCENE_ACTOR_H_
#define SCENE_ACTOR_H_

#include "GL\glew.h"
#include "../Utilities/Mesh.h"

class Actor {
	private:
		Mesh* mesh;
	public:
		Actor();
};

#endif // SCENE_ACTOR_H_