#pragma once
#include <iostream>
#include <string.h>
#include "Building.h"

class House :public Building {

private:
	int floors;
	int inhabitants;
	int servants;

public:
	House(const char* nameP, int f, int i, int s) : Building(nameP), floors(f), inhabitants(i), servants(s) {}

	void printHouse() const {

		std::cout << "Floors: " << floors << std::endl;
		std::cout << "Inhabitants: " << inhabitants << std::endl;
		std::cout << "Servants: " << servants << std::endl;
	}
};