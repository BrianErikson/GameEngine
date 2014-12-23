
#include "Scene/Scene.h"
#include "GameEngine.h"
#include "Utilities\Math\vector.h"

int main(void) {
	float width = 1024.f;
	float height = 768.f;
	GameEngine GEngine = GameEngine(width, height);

	CameraSettings settings(85.f, width / height, 0.1, 1000.f);
	Camera camera = Camera(Vector3(0.f, 0.f, -5.f), Vector3(0.f, 0.f, 0.f), settings);
	Scene* scene = new Scene(camera);
	GEngine.addScene(scene);

	while (!glfwWindowShouldClose(GEngine.getRenderWindow())) {
		GEngine.render();
	}

	GEngine.~GameEngine();
	return 0;
}