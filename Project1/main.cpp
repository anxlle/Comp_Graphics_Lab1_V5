#define GLEW_DLL
#define GLFW_DLL

#include <stdio.h>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3.\n");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(640, 480, "Polygon Variant 5 Grishaev ASUb-23-2", NULL, NULL);
	if (!window) {
		fprintf(stderr, "ERROR: could not create window.\n");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	GLenum ret = glewInit();
	if (GLEW_OK != ret) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(ret));
		return 1;
	}

	float R = 0.8;

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.8, 0.2, 0.7, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0.3, 0.6, 0.1);
		glBegin(GL_POLYGON);
		/*Êîîðäèíàòû âåðøèí*/
		for (int i = 0; i < 5; i++) {
			float angle = 2 * M_PI * i / 5 + M_PI / 2;
			float x = R * cos(angle);
			float y = R * sin(angle);
			glVertex2f(x, y);
		}
		/*Êîíåö êîîðäèíàò âåðøèí*/
		glEnd();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
