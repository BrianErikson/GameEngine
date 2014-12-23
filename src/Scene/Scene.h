#ifndef SCENE_SCENE_H_
#define SCENE_SCENE_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "Actor.h"
#include "Camera.h"

class Scene {
	private:
		std::vector<Actor> actors;
		Camera camera;
	public:
		Scene(Camera &camera);
		~Scene();
		void render(const double &deltaTime, GLFWwindow* &window);
};

#endif // SCENE_SCENE_H