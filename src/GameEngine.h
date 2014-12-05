
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

class GameEngine {
	private:
		GLFWwindow* window;
	public:
		GameEngine();
		~GameEngine();
		void render();
		GLFWwindow* getRenderWindow();
};