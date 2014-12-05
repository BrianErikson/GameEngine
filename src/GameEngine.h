
#include <GLFW/glfw3.h>
#include <gl/GL.h>
#include <OVR.h>
#include <stdlib.h>
#include <stdio.h>

struct Viewport {
	Viewport();
	Viewport(GLFWwindow &window, int width, int height);
	operator ovrRecti();
	operator ovrSizei();
	GLFWwindow* window;
	int width;
	int height;
};

class GameEngine {
	private:
		ovrHmd hmd;
		Viewport viewport;
		GLFWwindow* window;
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void error_callback(int error, const char* description);

	public:
		GameEngine();
		~GameEngine();
		void render();
		int shouldClose;
};