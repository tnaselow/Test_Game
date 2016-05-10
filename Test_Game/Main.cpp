#define GLEW_STATIC 

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "Game.h"
#include "ResourceManager.h"
#include "WindowGL.h"

void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);

const unsigned SCREEN_WIDTH = 800;
const unsigned SCREEN_HEGHT = 600;

Game BrickBreaker(SCREEN_WIDTH, SCREEN_HEGHT);

int main(int num, char **args)
{
	WindowGL window(SCREEN_WIDTH, SCREEN_HEGHT, "Brick Breaker");
	window.SetKeyCallBack(KeyCallback);
	BrickBreaker.Init();

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	BrickBreaker.CurrentState = GameState::GAME_ACTIVE;

	while (!glfwWindowShouldClose(window.windowHandle))
	{
		float currentTime = glfwGetTime();
		deltaTime = currentTime - lastFrame;
		lastFrame = currentTime;
		glfwPollEvents();

		BrickBreaker.ProccessInput(deltaTime);
		BrickBreaker.Update(deltaTime);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		BrickBreaker.Render();

		glfwSwapBuffers(window.windowHandle);
	}

	return 0;
}


void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			BrickBreaker.Keys[key] = GL_TRUE;
		else if (action == GLFW_RELEASE)
			BrickBreaker.Keys[key] = GL_FALSE;
	}
}