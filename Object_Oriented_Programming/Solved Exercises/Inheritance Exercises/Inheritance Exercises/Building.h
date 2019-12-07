#pragma once
#include <iostream>
#include <string.h>

class Building {

protected:
	char name[25];

public:
	Building(const char* nameP) {

		strcpy_s(name, nameP);
	}

	const char *getName() const {
		
		return name; 
	}
};