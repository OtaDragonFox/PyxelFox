#pragma once
#include "modules/applicationWindow.h"





class Application
{
public:
	void startUp();
	void registerModules();
	void registerAddons();

	void applicationTick();


	static Application& get()
	{
		return m_application;
	}

	static Application m_application;

private:
	Application() {};
	float deltaTime = 0.01f;

	bool running = true;
	applicationWindow* window;
};


#define CORE Application::get()
