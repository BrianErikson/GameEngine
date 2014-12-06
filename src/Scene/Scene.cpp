
#include "Scene.h"

Scene::Scene() {
	meshes = std::vector<Mesh>();

	Mesh box = Mesh(MeshType::POLYGON);

	// White side - BACK
	box.addVertex(Vector3(0.5, -0.5, 0.5));
	box.addVertex(Vector3(0.5, 0.5, 0.5));
	box.addVertex(Vector3(-0.5, 0.5, 0.5));
	box.addVertex(Vector3(-0.5, -0.5, 0.5));
	glEnd();

	// Purple side - RIGHT
	box.addVertex(Vector3(0.5, -0.5, -0.5));
	box.addVertex(Vector3(0.5, 0.5, -0.5));
	box.addVertex(Vector3(0.5, 0.5, 0.5));
	box.addVertex(Vector3(0.5, -0.5, 0.5));
	glEnd();

	// Green side - LEFT
	box.addVertex(Vector3(-0.5, -0.5, 0.5));
	box.addVertex(Vector3(-0.5, 0.5, 0.5));
	box.addVertex(Vector3(-0.5, 0.5, -0.5));
	box.addVertex(Vector3(-0.5, -0.5, -0.5));
	glEnd();

	// Blue side - TOP
	box.addVertex(Vector3(0.5, 0.5, 0.5));
	box.addVertex(Vector3(0.5, 0.5, -0.5));
	box.addVertex(Vector3(-0.5, 0.5, -0.5));
	box.addVertex(Vector3(-0.5, 0.5, 0.5));
	glEnd();

	// Red side - BOTTOM
	box.addVertex(Vector3(0.5, -0.5, -0.5));
	box.addVertex(Vector3(0.5, -0.5, 0.5));
	box.addVertex(Vector3(-0.5, -0.5, 0.5));
	box.addVertex(Vector3(-0.5, -0.5, -0.5));

	meshes.push_back(box);

}

Scene::~Scene() {

}

void Scene::render(const double &deltaTime, GLFWwindow* &window) {
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	float ratio = width / (float)height;
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);

	// Camera
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(359.f, ratio, 0.1f, 1000);

	// Meshes
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glRotatef(180.f, 0.f, 0.f, 0.f);
	glTranslatef(0.f, 0.f, -500.f);
	glRotatef((float)glfwGetTime() * 50.f, 0.f, 1.f, 1.f); 
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	for (int i = 0; i < this->meshes.size(); i++) {
		this->meshes[i].render(deltaTime);
	}
	glfwSwapBuffers(window);
	glfwPollEvents();
}