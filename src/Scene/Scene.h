#ifndef SCENE_SCENE_H_
#define SCENE_SCENE_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "../Utilities/Mesh.h"

class Scene {
	private:
		std::vector<Mesh> meshes;
	public:
		Scene();
		~Scene();
		void render(const double &deltaTime, GLFWwindow* &window);
};

#endif // SCENE_SCENE_H