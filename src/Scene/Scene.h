#ifndef SCENE_SCENE_H_
#define SCENE_SCENE_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Scene {
	public:
		Scene();
		~Scene();
		void render(const double &deltaTime, GLFWwindow* &window);
};

#endif // SCENE_SCENE_H