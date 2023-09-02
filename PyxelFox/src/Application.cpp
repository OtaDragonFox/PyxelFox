#include "Application.h"

void Application::startUp()
{
	registerModules();
	registerAddons();

	while (running)
	{
		applicationTick();
	}

}

void Application::registerModules()
{
	
	//Logger setup
	//IO setup
	//Register Window
	window = new applicationWindow;
	window->setupWindow(ivec2{640,420});

	//Setup ui modules and open up the application window


}

void Application::registerAddons()
{
	//future loading of separate LUA ad dons for advancing logic.
}

void Application::applicationTick()
{
	window->frameTick(deltaTime);
}

Application Application::m_application;