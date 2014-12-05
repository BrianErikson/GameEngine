
#include "Scene/Scene.h"
#include "GameEngine.h"

int main(void) {
	GameEngine GEngine = GameEngine(1024, 768);
	Scene* scene = new Scene();
	GEngine.addScene(scene);

	while (!glfwWindowShouldClose(GEngine.getRenderWindow())) {
		GEngine.render();
	}

	GEngine.~GameEngine();
	return 0;
}