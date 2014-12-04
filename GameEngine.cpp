#define PI 3.14159265359f

#include "GameEngine.h"

static GameEngine* engine;

void GameEngine::error_callback(int error, const char* description) {
	fputs(description, stderr);
}
void GameEngine::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	ovrHmd_Destroy(engine->hmd);
	ovr_Shutdown();
}

GameEngine::GameEngine() {
	engine = this;
	GLFWwindow* window;
	glfwSetErrorCallback(&this->error_callback);
	if (!glfwInit()) { exit(EXIT_FAILURE); }

	window = glfwCreateWindow(640, 480, "VR Game Engine", NULL, NULL);
	if (!window) { this->~GameEngine(); }
	this->shouldClose = glfwWindowShouldClose(window);

	// initialize and get first HMD device
	ovr_Initialize();
	hmd = ovrHmd_Create(0);
	if (!hmd) { hmd = ovrHmd_CreateDebug(ovrHmdType::ovrHmd_DK2); }

	// set up hmd
	ovrSizei resolution = hmd->Resolution;
	ovrBool tracking = ovrHmd_ConfigureTracking(hmd, ovrTrackingCap_Orientation | ovrTrackingCap_MagYawCorrection | ovrTrackingCap_Position, 0);
	if (tracking == false) { this->~GameEngine(); }

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, this->key_callback);
}

GameEngine::~GameEngine() {
	ovrHmd_Destroy(this->hmd);
	glfwDestroyWindow(this->window);
	ovr_Shutdown();
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

void GameEngine::render() {
	this->shouldClose = glfwWindowShouldClose(window);

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	float ratio = width / (float)height;
	glViewport(0, 0, width, height);

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);

	// get rotation
	float yaw, eyePitch, eyeRoll;
	ovrTrackingState ts = ovrHmd_GetTrackingState(hmd, ovr_GetTimeInSeconds());
	if (ts.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked)) {
		ovrPosef pose = ts.HeadPose.ThePose;
		float qx = pose.Orientation.x;
		float qy = pose.Orientation.y;
		float qz = pose.Orientation.z;
		float qw = pose.Orientation.w;
		double test = qx*qy + qz*qw;

		if (test > 0.499f) { // singularity at north pole
			yaw = 2 * atan2(qx, qw);
			eyePitch = PI / 2;
			eyeRoll = 0;
		}
		else if (test < -0.499f) { // singularity at south pole
			yaw = -2 * atan2(qx, qw);
			eyePitch = -PI / 2;
			eyeRoll = 0;
		}
		else {
			yaw = atan2(2 * qy*qw - 2 * qx*qz, 1 - 2 * pow(qy, 2) - 2 * pow(qz, 2));
			eyePitch = asin(2 * qx*qy + 2 * qz*qw);
			eyeRoll = atan2(2 * qx*qw - 2 * qy*qz, 1 - 2 * pow(qx, 2) - 2 * pow(qz, 2));
		}

		// get VR position offset
		ovrVector3f offset = pose.Position;
	}
	else {
		yaw = 0;
		eyePitch = 0;
		eyeRoll = 0;
	}


	//ovrHmd_BeginFrameTiming(hmd, 0);

	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glRotatef((float)glfwGetTime() * 50.f, 0.f, 0.f, 1.f);

	glBegin(GL_TRIANGLES);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(-0.6f, -0.4f, 0.f);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(0.6f, -0.4f, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(0.f, 0.6f, 0.f);
	glEnd();

	glfwSwapBuffers(window);
	glfwPollEvents();
}

int main(void) {
	GameEngine engine = GameEngine();

	while (!engine.shouldClose) {
		engine.render();
	}

	engine.~GameEngine();
}