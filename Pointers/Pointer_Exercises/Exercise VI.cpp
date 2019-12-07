#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Player
{
	int health;
	float x, y;
};

void printPlayer(Player p)
{
	std::cout << p.health << std::endl;
	std::cout << p.x << std::endl;
	std::cout << p.y << std::endl;
}

void printPlayerAlt(Player *ptr)
{
	std::cout << (*ptr).health << std::endl;
	std::cout << (*ptr).x << std::endl;
	std::cout << (*ptr).y << std::endl;
}

void printPlayerAltII(Player * ptr) //Best way.
{
	std::cout << ptr->health << std::endl;
	std::cout << ptr->x << std::endl;
	std::cout << ptr->y << std::endl;
}

void ExerciseVI()
{
	Player p = { 100, 5.0, 5.0 };
	printPlayer(p);
	printPlayerAlt(&p);
	printPlayerAltII(&p);
}