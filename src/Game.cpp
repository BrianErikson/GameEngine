
#include "Scene/Scene.h"
#include "GameEngine.h"
#include <Eigen>
#include <GLFW/glfw3.h>
#include <iostream>

using Eigen::Vector3f;

int main(void) {
	float width = 1024.f;
	float height = 768.f;
	GameEngine GEngine = GameEngine((int)width, (int)height);

	CameraSettings settings(70.f, width / height, 0.1f, 1000.f);
	Camera camera = Camera(Vector3f(0.f, 0.f, -5.f), Vector3f(0.f, 0.f, 0.f), settings);
	Scene* scene = new Scene(camera);
	GEngine.addScene(scene);

	int desiredFPS = 60;
	int FPS = 0;
	double fixedDelta = 1.0 / desiredFPS;
	double deltaTime = 0;
	double curTime = glfwGetTime();
	double prevTime = curTime;
	double fpsTimer = 0;

	while (!glfwWindowShouldClose(GEngine.getRenderWindow())) {
		curTime = glfwGetTime();
		deltaTime = curTime - prevTime;
		if (deltaTime >= fixedDelta) {
			glEnable(GL_DEPTH_TEST);
			GEngine.render();

			++FPS;
			fpsTimer += deltaTime;
			prevTime = curTime;
		}

		// FPS counter
		if (fpsTimer >= 1.0) {
			fpsTimer = 0;
			FPS = 0;
		}

	}

	GEngine.~GameEngine();
	return 0;
}