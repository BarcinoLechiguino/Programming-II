#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

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
