#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void doubleNumberino(int &number)
{
	number = number * 2;
}

void ExerciseI()
{
	int numberino = 0;

	std::cout << "Introduce any number from 0 to 100: " << std::endl;
	std::cin >> numberino;
	doubleNumberino(numberino);

	std::cout << "The double of the introduced number amounts to: " << numberino << std::endl;
}

void ExerciseII()
{

}

struct pirate
{
	const char * name;
	unsigned short life;
};

struct weapon
{
	const char * name;
	unsigned short damage;
};

void attack(pirate * lechuck, const weapon &blade)
{
	lechuck->life = lechuck->life - blade.damage;
}

void printPirate(const pirate &p)
{
	std::cout << "Name: " << p.name << "    Current HP: " << p.life << std::endl;
}

void ExerciseIII()
{
	pirate Pirate = { "leChuck", 100 };
	weapon Weapon = { "Sword", 10 };

	attack((&Pirate), Weapon);
	printPirate(Pirate);
}
