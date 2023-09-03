#pragma once
#include "../math/math.h"
struct GLFWwindow;

class applicationWindow
{
public:
	bool setupWindow(ivec2 resulution);

	void frameTick(float& deltaTime);


	void recalculateWindow(GLFWwindow* window, int xSize, int ySize);
	void updateMousePosition(GLFWwindow* window, double xpos, double ypos);

	void processInput();

private:
	GLFWwindow* m_Window;
	vec4 bgrdCol{1,1,1,1};

	ivec2 m_winRes;

	vec2 m_mouseLoc;

};

