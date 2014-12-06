
#include "GameEngine.h"

static void error_callback(int error, const char* description) {
	fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) { glfwSetWindowShouldClose(window, GL_TRUE); }
}


GameEngine::GameEngine(int width, int height) {
	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) { exit(EXIT_FAILURE); }

	this->window = glfwCreateWindow(width, height, "Simple example", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	this->scenes = std::vector<Scene*>();

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, key_callback);
	
}

GameEngine::~GameEngine() {
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

void GameEngine::render() {
	for (int i = 0; i < this->scenes.size(); i++) {
		Scene* scene = this->scenes[i];
		scene->render(glfwGetTime(), this->window);
	}
}

GLFWwindow* GameEngine::getRenderWindow() {
	return this->window;
}
void GameEngine::addScene(Scene* &scene) {
	this->scenes.push_back(scene);
}