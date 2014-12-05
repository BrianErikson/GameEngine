#define PI 3.14159265359f

#include "GameEngine.h"

Viewport::Viewport() {}

Viewport::Viewport(GLFWwindow &window, int width, int height) {
	this->window = &window;
	this->width = width;
	this->height = height;
}

Viewport::operator ovrRecti() {
	ovrVector2i pos;
	pos.x, pos.y = 0;

	ovrSizei size;
	size.w = this->width;
	size.h = this->height;

	ovrRecti rect;
	rect.Pos = pos;
	rect.Size = size;
	return rect;
}

Viewport::operator ovrSizei() {
	ovrSizei size;
	size.w = this->width;
	size.h = this->height;
	return size;
}

static GameEngine* engine;

GameEngine::GameEngine() {
	engine = this;

	glfwSetErrorCallback(&this->error_callback);
	if (!glfwInit()) { exit(EXIT_FAILURE); }

	// initialize and get first HMD device
	ovr_Initialize();
	hmd = ovrHmd_Create(0);
	if (!hmd) { hmd = ovrHmd_CreateDebug(ovrHmdType::ovrHmd_DK2); }

	int width = 640;
	int height = 480;
	GLFWwindow* window = glfwCreateWindow(width, height, "VR Game Engine", NULL, NULL);
	if (!window) { this->~GameEngine(); }
	this->shouldClose = glfwWindowShouldClose(window);
	Viewport viewport = Viewport(*window, 640, 480);

	// set up hmd
	ovrSizei resolution = hmd->Resolution;
	ovrBool tracking = ovrHmd_ConfigureTracking(hmd, ovrTrackingCap_Orientation | ovrTrackingCap_MagYawCorrection | ovrTrackingCap_Position, 0);
	if (tracking == false) { this->~GameEngine(); }

	// configure hmd OpenGL instance
	const ovrRecti debugRect = viewport;
	ovrHmd_AttachToWindow(hmd, viewport.window, &debugRect, nullptr);

	ovrRenderAPIConfig config;
	config.Header.API = ovrRenderAPIType::ovrRenderAPI_OpenGL;
	config.Header.Multisample = 4; 
	ovrSizei rtSize = viewport;
	config.Header.RTSize = rtSize;

	ovrEyeRenderDesc eyeRenderDesc[2];
	eyeRenderDesc[0] = ovrHmd_GetRenderDesc(hmd, ovrEye_Left, hmd->DefaultEyeFov[0]);
	eyeRenderDesc[1] = ovrHmd_GetRenderDesc(hmd, ovrEye_Right, hmd->DefaultEyeFov[1]);
	ovrHmd_ConfigureRendering(hmd, &config, hmd->DistortionCaps, hmd->DefaultEyeFov, eyeRenderDesc);

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, &this->key_callback);
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


	ovrHmd_BeginFrame(hmd, 0);

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
	
	//ovrHmd_EndFrame(hmd, )
	glfwPollEvents();
}

int main(void) {
	GameEngine engine = GameEngine();

	while (!engine.shouldClose) {
		engine.render();
	}

	engine.~GameEngine();
}

void GameEngine::error_callback(int error, const char* description) {
	fputs(description, stderr);
}

void GameEngine::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	ovrHmd_Destroy(engine->hmd);
	ovr_Shutdown();
}