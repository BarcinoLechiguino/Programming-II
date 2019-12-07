#pragma once
#include <iostream>
#include <string.h>
#include "Building.h"

class Warehouse : public Building {

private:
	int wood;
	int rocks;
	int wheat;

public:
	Warehouse(const char *nameP, int w, int r, int wh) : Building(nameP), wood(w), rocks(r), wheat(wh) {};

	void printResources() {

		std::cout<< "Wood: " << wood << std::endl;
		std::cout << "Rocks: " << rocks << std::endl;
		std::cout << "Wheat: " << wheat << std::endl;
	}
};