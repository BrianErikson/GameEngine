
#include "Scene/Scene.h"
#include "GameEngine.h"
#include <Eigen>

using Eigen::Vector3f;

int main(void) {
	float width = 1024.f;
	float height = 768.f;
	GameEngine GEngine = GameEngine((int)width, (int)height);

	CameraSettings settings(70.f, width / height, 0.1f, 1000.f);
	Camera camera = Camera(Vector3f(0.f, 0.f, -5.f), Vector3f(0.f, 0.f, 0.f), settings);
	Scene* scene = new Scene(camera);
	GEngine.addScene(scene);

	while (!glfwWindowShouldClose(GEngine.getRenderWindow())) {
		glEnable(GL_DEPTH_TEST);
		GEngine.render();
	}

	GEngine.~GameEngine();
	return 0;
}