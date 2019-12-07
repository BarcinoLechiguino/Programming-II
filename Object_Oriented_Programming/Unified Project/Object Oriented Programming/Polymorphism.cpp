#include <stdio.h>
#include <stdlib.h>
#include <iostream.>
#include <string.h>

using namespace std;

void ExamplesVI()
{

}

class Pokemon
{
protected:
	char name[32];
	const char * type;

public:
	Pokemon(const char naming[32])
	{
		strcpy_s(name, naming);
		type= "noType";
	}

	const char * getName() const { return name; }
	const char * getType() const { return type; }
	virtual int damageAttack(Pokemon* victim) = 0;
};

class ElectricPokemon : public Pokemon
{
public:
	ElectricPokemon(const char string[32]) : Pokemon(string) { type = "Electric"; }

	int damageAttack(Pokemon * victim) override
	{
		int damage = 10;
		if (strcmp(victim->getType(), "Water") == 0) { damage *= 2; }
		if (strcmp(victim->getType(), "Grass") == 0) { damage /= 2; }
		return damage;
	}
};

class GrassPokemon : public Pokemon
{
public:
	GrassPokemon(const char string[32]) : Pokemon(string) { type = "Grass"; }

	int damageAttack(Pokemon * victim) override
	{
		int damage = 10;
		if (strcmp(victim->getType(), "Water") == 0) { damage *= 2; }
		if (strcmp(victim->getType(), "Fire") == 0) { damage /= 2; }
		return damage;
	}
};

class FirePokemon : public Pokemon
{
public:
	FirePokemon(const char string[32]) : Pokemon(string) { type = "Fire"; }
	
	int damageAttack(Pokemon * victim) override
	{
		int damage = 10;
		if (strcmp(victim->getType(), "Grass") == 0) { damage *= 2; }
		if (strcmp(victim->getType(), "Water") == 0) { damage /= 2; }
		return damage;
	}
};

class WaterPokemon : public Pokemon
{
public:
	WaterPokemon(const char string[32]) : Pokemon(string) { type = "Water"; }
	
	int damageAttack(Pokemon * victim) override
	{
		int damage = 10;
		if (strcmp(victim->getType(), "Fire") == 0) { damage *= 2; }
		if (strcmp(victim->getType(), "Plant") == 0) { damage /= 2; }
		return damage;
	}
};

void Polymorphism_Pokemon()
{
	Pokemon * pikachu = new ElectricPokemon("Pikachu");
	Pokemon * bulbasur = new GrassPokemon("Bulbasur");
	Pokemon * charmander = new FirePokemon("Charmander");
	Pokemon * squirtle = new WaterPokemon("Squirtle");

	cout << "-- Damage Attacks -- " << endl;

	cout << pikachu->getName() << " -> " << bulbasur->getName() << " = " << pikachu->damageAttack(bulbasur) << " units\n";
	cout << bulbasur->getName() << " -> " << squirtle->getName() << " = " << bulbasur->damageAttack(squirtle) << " units\n";
	cout << squirtle->getName() << " -> " << charmander->getName() << " = " << squirtle->damageAttack(charmander) << " units\n";
	cout << charmander->getName() << " -> " << pikachu->getName() << " = " << charmander->damageAttack(pikachu) << " units\n";

	delete pikachu;
	delete bulbasur;
	delete charmander;
	delete squirtle;
}