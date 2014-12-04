
#include <GLFW/glfw3.h>
#include <gl/GL.h>
#include <OVR.h>
#include <stdlib.h>
#include <stdio.h>

class GameEngine {
	private:
		ovrHmd hmd;
		GLFWwindow* window;
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void error_callback(int error, const char* description);

	public:
		GameEngine();
		~GameEngine();
		void render();
		int shouldClose;
};