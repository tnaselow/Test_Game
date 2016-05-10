#include "WindowGL.h"
#include "ResourceManager.h"

WindowGL::WindowGL(unsigned width, unsigned height, const char *title)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	this->windowHandle = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(this->windowHandle);

	glewExperimental = true;
	glewInit();
	glGetError();


	glViewport(0, 0, width, height);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

WindowGL::~WindowGL()
{
	ResourceManager::Clear();
	glfwTerminate();
}

void WindowGL::SetKeyCallBack(void(*callback)(GLFWwindow *window, int key, int scancode, int action, int mode))
{
	glfwSetKeyCallback(this->windowHandle, callback);
}