#pragma once
#include "modules/applicationWindow.h"





class Application
{
public:
	void startUp();
	void registerModules();
	void registerAddons();

	void applicationTick();



	static Application m_application;



	static Application& get()
	{
		return m_application;
	}

	static applicationWindow* getWindow()
	{
		return get().window;
	}

private:
	Application() {};
	float deltaTime = 0.01f;

	bool running = true;
	applicationWindow* window;
};


#define CORE Application::get()
#define WINDOW Application::getWindow()
