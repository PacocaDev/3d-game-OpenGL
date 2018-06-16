#include <stdio.h>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

// Window dimensions

const GLint WIDTH = 800, HEIGHT = 600;

int main() {

	//Initialise GLFW

	if (!glfwInit()) {
		printf("GLFW initilise failed");
		glfwTerminate();
		return 1;
	}

	//Setup GLFW windows properties
	//OpenGL version

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//Core profile
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	//Allow forward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Game", NULL, NULL);
	if(!mainWindow)
	{
		printf("GLFW window creation failed");
		glfwTerminate();
		return 1;
	}

	// Get buffer size information
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Set context for GLEW to use
	glfwMakeContextCurrent(mainWindow);

	// Allow modern extension features
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		printf("GLEW initialisation failed");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	// Setup Viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);

	//Loope until windows closed
	while (!glfwWindowShouldClose(mainWindow)) {
		//Get + Handle use input events
		glfwPollEvents();

		//Clear Window
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
	}



	return 0;
}