#pragma once
#include "modules/applicationWindow.h"
#include "modules/Input.h"





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
		return get().m_window;
	}
	static applicationInput* getInput()
	{
		return get().m_input;
	}

private:
	Application() {};
	float  m_deltaTime = 0.01f;

	bool  m_running = true;
	applicationWindow* m_window;
	applicationInput* m_input;
};


#define CORE Application::get()
#define WINDOW Application::getWindow()
#define INPUT Application::getInput()
