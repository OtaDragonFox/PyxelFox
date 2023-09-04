#include "Application.h"

void Application::startUp()
{
	registerModules();
	registerAddons();

	while (m_running)
	{
		applicationTick();
	}

}

void Application::registerModules()
{
	
	//Logger setup
	//IO setup
	//Register Window
	m_window = new applicationWindow;
	m_window->setupWindow(ivec2{640,420});
	m_input = new applicationInput;
	m_input->setupInput();
	//Setup ui modules and open up the application window


}

void Application::registerAddons()
{
	//future loading of separate LUA ad dons for advancing logic.
}

void Application::applicationTick()
{
	m_window->frameTick(m_deltaTime);
}

Application Application::m_application;