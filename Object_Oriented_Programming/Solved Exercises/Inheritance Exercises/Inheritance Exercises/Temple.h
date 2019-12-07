#pragma once
#include <iostream>
#include <string.h>
#include "Building.h"

class Temple :public Building {

private:
	char god[25];
	int priests;

public:
	Temple(const char* nameP, const char* godP, int p) : Building(nameP), priests(p) {
	
		strcpy_s(god, godP);
	}

	void printTemple() const {

		std::cout << "God: " << god << std::endl;
		std::cout << "Priests: " << priests << std::endl;
	}
};