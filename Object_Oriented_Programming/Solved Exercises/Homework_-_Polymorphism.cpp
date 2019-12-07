#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


class Pokemon {
protected:
	char name[10];
	const char* type;
public:
	Pokemon(const char string[10])  {
		strcpy(name, string);
		type = "NoType";
	};
	const char* getName() const { return name; };
	const char* getType() const { return type; };
	virtual int damageAttack(Pokemon* victim) = 0;
};

class WaterPokemon : public Pokemon {
public:
	WaterPokemon(const char string[10]) : Pokemon(string) { type = "Water"; }

	int damageAttack(Pokemon* victim) override {
		int damage = 10;
		
		if (strcmp((*victim).getType(), "Grass") == 0) { damage /= 2; }
		if (strcmp((*victim).getType(), "Fire") == 0) { damage *= 2; }
		return damage;
	};
};

class FirePokemon : public Pokemon {

public:
	FirePokemon(const char string[10]) : Pokemon(string) { type = "Fire"; }
	
	int damageAttack(Pokemon* victim) {
		int damage = 10;
		if (strcmp((*victim).getType(), "Water") == 0) { damage /= 2; }
		if (strcmp((*victim).getType(), "Grass") == 0) { damage *= 2; }
		return damage;
	};
};

class GrassPokemon : public Pokemon {

public:
	GrassPokemon(const char string[10]) :  Pokemon(string) { type = "Grass"; }

	int damageAttack(Pokemon* victim) override {
		int damage = 10;
		if (strcmp((*victim).getType(), "Water") == 0) { damage *= 2; }
		if (strcmp((*victim).getType(), "Fire") == 0) { damage /= 2; }
		return damage;
	};
};

class ElectricPokemon : public Pokemon {

public:
	ElectricPokemon(const char string[10]) : Pokemon(string) { type = "Electric"; }

	int damageAttack(Pokemon* victim) override {
		int damage = 10;
		if (strcmp((*victim).getType(), "Water") == 0) { damage *= 2; }
		if (strcmp((*victim).getType(), "Grass") == 0) { damage /= 2; }
		return damage;
	};
};

using namespace std;

int main() {
	Pokemon* pikachu = new ElectricPokemon("Pikachu");
	Pokemon* charmander = new FirePokemon("Charmander");
	Pokemon* bulbasaur = new GrassPokemon("Bulbasaur");
	Pokemon* squirtle = new WaterPokemon("Squirtle");

	cout << "-- Damage Attack --" << endl;
	
	cout << pikachu->getName() << " -> " << bulbasaur->getName()
		<< " = " << pikachu->damageAttack(bulbasaur) << "units\n"; 

	cout << bulbasaur->getName() << " -> " << squirtle->getName()
		<< " = " << bulbasaur->damageAttack(squirtle) << "units\n";

	cout << squirtle->getName() << " -> " << charmander->getName()
		<< " = " << squirtle->damageAttack(charmander) << "units\n";
	
	cout << charmander->getName() << " -> " << pikachu->getName()
		<< " = " << charmander->damageAttack(pikachu) << "units\n" << endl;


	system("pause");
	return 0;
}