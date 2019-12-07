#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Animal
{
private:
	int age;
	int jumpStrength;
	int fidelity;

public:
	Animal() : age(6), jumpStrength(10), fidelity(12) 
	{
	}
};

class Dog : public Animal
{
public:
	int barkPower;

	Dog() : barkPower(100) 
	{
	}
};

class Cat : public Animal
{
public:
	int climbingSpeed;

	Cat() : climbingSpeed(7) 
	{
	}
};

int main()
{
	Dog dog; //Is initialized with the data members of Animals (age, jumpStrength and fidelity) plus the data members of Dog (barkPower).
	Cat cat; //Is initialized with the data members of Animals (age, jumpStrength and fidelity) plus the data members of Cat (climbingSpeed).
}