#include<iostream>
#include<glad/glad.h> // always before other header files that require OpenGL (like GLFW).
#include<GLFW/glfw3.h>

void processInput(GLFWwindow* window);

int main() {
	int HEIGHT = 800;
	int WIDTH = 800;

	// Initialize GLFW
	glfwInit();
	// Tell GLFW what version of OpnelGl we are using -> 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	// Creating GLFWwindow object 
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window " << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	// Initialize glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// Load glad
	gladLoadGL();

	//Specify the vievport of OpenGL in the window x=800 y=800
	glViewport(0, 0, WIDTH, HEIGHT);

	// Swap the back buffer with front 


	//framebuffer_size_callback(window, WIDTH, HEIGHT);
	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	while (!glfwWindowShouldClose(window)) {
		processInput(window);
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}



	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


//void framebuffer_size_callback(glfwwindow* window, int width, int height)
//{
//	glviewport(0, 0, width, height);
//}
