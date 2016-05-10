#pragma once
#define GLEW_STATIC 

#include <GL\glew.h>
#include <GLFW\glfw3.h>

class WindowGL
{
	public:
		unsigned Width, Height;
		GLFWwindow *windowHandle;

		WindowGL(unsigned width, unsigned height, const char *title);
		~WindowGL();

		void SetKeyCallBack(void (*callback)(GLFWwindow *window, int key, int scancode, int action, int mode));
};