#include "Input.h"
#include "../Application.h"
#include <iostream>
#include <GLFW/glfw3.h>
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	INPUT->updateMousePosition(xpos, ypos);
}




void applicationInput::setupInput()
{

	glfwSetCursorPosCallback(&WINDOW->getWindow(), cursor_position_callback);

}

void applicationInput::updateMousePosition(double xpos, double ypos)
{
	/*calculate cursor location from the range of -1 +1 on both axis
* | (1 - ((xpos / m_winRes.x) * 2))*-1 | */

	m_mouseLoc.x = (float)(1 - ((xpos / WINDOW->getWindowSize().x) * 2)) * -1;
	m_mouseLoc.y = (float)(1 - ((ypos / WINDOW->getWindowSize().y) * 2)) * -1;

	std::cout << "x " << m_mouseLoc.x << "|" << "ypos " << m_mouseLoc.y << std::endl;
}
