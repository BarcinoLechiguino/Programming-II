#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Module.h"

class Application
{
private:
	Module * modules[3];

public:
	void start()
	{
		std::cout << "Application::Start()" << std::endl;
		//modules[0] = new ModuleInput();
	}

	void update()
	{
		std::cout << "Application::Start()" << std::endl;
	}

	void stop()
	{
		std::cout << "Application::Start()" << std::endl;
	}
};