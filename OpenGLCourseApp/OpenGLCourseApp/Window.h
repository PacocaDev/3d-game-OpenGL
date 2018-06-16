#pragma once

#include <stdio.h>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

class Window
{
public:
	Window();

	Window(GLint windowWidth, GLint windowsHeight);

	int initialise();

	GLfloat getBufferWidth() { return bufferWidth; };
	GLfloat getBufferHeigth() { return bufferHeight; };

	bool getShouldClose() { return glfwWindowShouldClose(mainWindow); };

	void swapBuffers() { return glfwSwapBuffers(mainWindow); };


	~Window();

private:
	GLFWwindow * mainWindow;

	GLint width, height;
	GLint bufferWidth, bufferHeight;

};

