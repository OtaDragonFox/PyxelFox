#include "applicationWindow.h"
#include "../Application.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "../math/aabb.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	WINDOW->recalculateWindow(window, width, height);
}




bool applicationWindow::setupWindow(ivec2 resulution)
{
	m_winRes = resulution;

	if (!glfwInit())
		return false;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = glfwCreateWindow(
		resulution.x,
		resulution.y,
		"PyxelFox",
		NULL/*monitor context*/,
		NULL/*GLFW window context*/);
	
	glfwMakeContextCurrent(m_Window);

	if (!m_Window || !gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return false;

	glViewport(0, 0, m_winRes.x, m_winRes.y);

	glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);

	return true;
}

void applicationWindow::frameTick(float& deltaTime)
{
	glClearColor(bgrdCol.x, bgrdCol.y, bgrdCol.z, bgrdCol.w);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

void applicationWindow::recalculateWindow(GLFWwindow* window, int xSize, int ySize)
{

}
