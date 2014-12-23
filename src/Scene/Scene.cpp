
#include "Scene.h"

Scene::Scene() {
	this->actors = std::vector<Actor>();
	Box box = Box();
	this->actors.push_back(box);
}

Scene::~Scene() {

}

void Scene::render(const double &deltaTime, GLFWwindow* &window) {
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	float ratio = width / (float)height;
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Camera
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70.f, ratio, 0.1f, 1000);

	// Meshes
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glTranslatef(0.f, 0.f, -5.f);
	glRotatef((float)glfwGetTime() * 50.f, 0.f, 1.f, 1.f);

	for (int i = 0; i < this->actors.size(); i++) {
		this->actors[i].render(deltaTime);
	}

	glfwSwapBuffers(window);
	glfwPollEvents();
}