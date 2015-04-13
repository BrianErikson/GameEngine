
#include "Scene.h"
#include "Actors\Box.h"

Scene::Scene(Camera &camera) : camera(camera) {
	this->actors = std::vector<Actor>();
	Box box = Box();
	this->actors.push_back(box);
}

Scene::~Scene() {

}

void Scene::render(const double &deltaTime, GLFWwindow* &window) {
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	MovementComponent* camMovement = dynamic_cast<MovementComponent*>(camera.getComponentByType(EActorComponent::MOVEMENT));
	camMovement->rotate(Vector3f(0.001, 0.001, 0.001));

	camera.tick(deltaTime);
	camera.render(deltaTime);

	// Meshes
	for (int i = 0; i < this->actors.size(); i++) {
		this->actors[i].tick(deltaTime);
	}

	for (int i = 0; i < this->actors.size(); i++) {
		this->actors[i].render(deltaTime);
	}

	glfwSwapBuffers(window);
	glfwPollEvents();
}