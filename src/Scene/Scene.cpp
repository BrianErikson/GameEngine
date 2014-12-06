
#include "Scene.h"

Scene::Scene() {
	meshes = std::vector<Mesh>();

	// White side - BACK
	Polygon back = Polygon();
	back.setColor(Color(EColor::WHITE));
	back.addVertex(Vector3(0.5, -0.5, 0.5));
	back.addVertex(Vector3(0.5, 0.5, 0.5));
	back.addVertex(Vector3(-0.5, 0.5, 0.5));
	back.addVertex(Vector3(-0.5, -0.5, 0.5));

	// Purple side - RIGHT
	Polygon right = Polygon();
	right.setColor(Color(EColor::PURPLE));
	right.addVertex(Vector3(0.5, -0.5, -0.5));
	right.addVertex(Vector3(0.5, 0.5, -0.5));
	right.addVertex(Vector3(0.5, 0.5, 0.5));
	right.addVertex(Vector3(0.5, -0.5, 0.5));

	// Green side - LEFT
	Polygon left = Polygon();
	left.setColor(Color(EColor::GREEN));
	left.addVertex(Vector3(-0.5, -0.5, 0.5));
	left.addVertex(Vector3(-0.5, 0.5, 0.5));
	left.addVertex(Vector3(-0.5, 0.5, -0.5));
	left.addVertex(Vector3(-0.5, -0.5, -0.5));

	// Blue side - TOP
	Polygon top = Polygon();
	top.setColor(Color(EColor::BLUE));
	top.addVertex(Vector3(0.5, 0.5, 0.5));
	top.addVertex(Vector3(0.5, 0.5, -0.5));
	top.addVertex(Vector3(-0.5, 0.5, -0.5));
	top.addVertex(Vector3(-0.5, 0.5, 0.5));
	glEnd();

	// Red side - BOTTOM
	Polygon bottom = Polygon();
	bottom.setColor(Color(EColor::RED));
	bottom.addVertex(Vector3(0.5, -0.5, -0.5));
	bottom.addVertex(Vector3(0.5, -0.5, 0.5));
	bottom.addVertex(Vector3(-0.5, -0.5, 0.5));
	bottom.addVertex(Vector3(-0.5, -0.5, -0.5));

	Mesh box = Mesh(MeshType::POLYGON);
	box.add(back);
	box.add(right);
	box.add(left);
	box.add(top);
	box.add(bottom);

	meshes.push_back(box);
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
	gluPerspective(359.f, ratio, 0.1f, 1000);

	// Meshes
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
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