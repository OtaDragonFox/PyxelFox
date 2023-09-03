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
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	WINDOW->updateMousePosition(window,xpos, ypos);
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


	//Handle Glfw callbacks for input and window resizing -> mouse move and more.
	glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);
	glfwSetCursorPosCallback(m_Window, cursor_position_callback);






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

void applicationWindow::updateMousePosition(GLFWwindow* window, double xpos, double ypos)
{
	/*
	* calculate cursor location from the range of -1 +1 on both axis
	* 1-((xpos / m_winRes) * 2)  
	* 
	*/
	m_mouseLoc.x = (1 - ((xpos / m_winRes.x) * 2))*-1;
	m_mouseLoc.y = (1 - ((ypos / m_winRes.y) * 2))*-1;
	
	
	//test window at center of the screen
	vec2 ulcorner{-0.1f,-0.1f };
	vec2 brcorner{ 0.1f,0.1f };

	if (cursorOverlap(ulcorner, brcorner, m_mouseLoc))
		std::cout << "overlap" << std::endl;
	else
		std::cout << "nooverlap" << std::endl;
	



}

void applicationWindow::processInput()
{

}
