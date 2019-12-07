#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

class Pokemon
{
protected:
	char name[64];
	const char * type;

public:
	Pokemon(const char * Pname) 
	{
		strcpy_s(name, Pname);
		type = "nullType";
	}

	const char * getName() const { return name; }
	const char * getType() const { return type; }
	virtual int damageAttack(Pokemon * victim) = 0;
};

class ElectricPokemon : public Pokemon
{
public:
	ElectricPokemon(const char * Ename) : Pokemon(Ename) { type = "Electric"; }

	int damageAttack(Pokemon * victim) override
	{
		int damage = 10;

		if (strcmp(victim->getType(), "Grass") == 0) { damage /= 2; }
		if (strcmp(victim->getType(), "Water") == 0) { damage *= 2; }
		return damage;
	}
};

class GrassPokemon : public Pokemon
{
public:
	GrassPokemon(const char * Gname) : Pokemon(Gname) { type = "Grass"; }

	int damageAttack(Pokemon * victim)
	{
		int damage = 10;

		if (strcmp(victim->getType(), "Fire") == 0) { damage /= 2; }
		if (strcmp(victim->getType(), "Water") == 0) { damage *= 2; }

		return damage;
	}
};

class FirePokemon : public Pokemon
{
public:
	FirePokemon(const char * Fname) : Pokemon(Fname) { type = "Fire"; }

	int damageAttack(Pokemon * victim)
	{
		int damage = 10;

		if (strcmp(victim->getType(), "Water") == 0) { damage /= 2; }
		if (strcmp(victim->getType(), "Plant") == 0) { damage *= 2; }

		return damage;
	}
};

class WaterPokemon : public Pokemon
{
public:
	WaterPokemon(const char * Wname) : Pokemon(Wname) { type = "Water"; }

	int damageAttack(Pokemon * victim)
	{
		int damage = 10;

		if (strcmp(victim->getType(), "Grass") == 0) { damage /= 2; }
		if (strcmp(victim->getType(), "Fire") == 0) { damage *= 2; }
		return damage;
	}
};

void PokemonExercise()
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