#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Application.h"
#include "Module.h"


class Module
{
public:
	char name[32];

public: 
	Module(const char * pname)
	{
		//strcpy_s(name, *pname);
	}
};

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



int main()
{
	Application * app = new Application;

	
	system("pause");
	return 0;
}