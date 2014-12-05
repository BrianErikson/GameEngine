
#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_

#include "Scene\Scene.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>


class GameEngine {
	private:
		GLFWwindow* window;
		std::vector<Scene*> scenes;
	public:
		GameEngine(int width, int height);
		~GameEngine();
		void render();
		GLFWwindow* getRenderWindow();
		void addScene(Scene* &scene);
};

#endif //  GAMEENGINE_H_