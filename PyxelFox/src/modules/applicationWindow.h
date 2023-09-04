#pragma once
#include "../math/math.h"
struct GLFWwindow;

class applicationWindow
{
public:
	bool setupWindow(ivec2 resulution);

	void frameTick(float& deltaTime);


	




	void recalculateWindow(GLFWwindow* window, int xSize, int ySize);
	
	ivec2& getWindowSize()
	{
		return m_winRes;
	}

	GLFWwindow& getWindow()
	{
		return *m_Window;
	}


private:
	GLFWwindow* m_Window;
	vec4 bgrdCol{1,1,1,1};

	ivec2 m_winRes;

};

