#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
typedef unsigned int uint;

//const Objects and Class Methods
class Foo
{
public:
	int n;
	Foo() : n(0){}
	void set(int v) { n = v; }
	int get() const { return n; }
};

//References
void increment(int& n) //The n parameter of the functio is declared as a reference.
{
	++n;
}

//The standard of passing read only data
void foo(int n) { cout << n << endl; } // Makes a copy of n.
void bar(int *n) { cout << *n << endl; } // Does not make a copy but n can be nullptr.
void baz(int& n) { cout << n << endl; } // Does not make a copy but n cannot be nullptr.
void oof(const int& n) { cout << n << endl; } // Const reference that is read-only.

void ExamplesII()
{
	//const Variables
	const int a = 2; //"a" cannot be modified.

	//const Pointers
	int b = 4;
	const int * p1 = &b; //Pointer to a constant data. Can change p1 (address) but cannot change *p1 (element).
	int * const p2 = &b; //Constant pointer to a data. Cannot change p2 (address) but can can change *p2 (element).
	const int * const p3 = &b; //Constant pointer to a constant data. Cannot change p3 (address) and cannot change *p3 (element) either.

	//const Objects and Class Methods
	const Foo f1; //We declare a const instance of the class foo.
	Foo f2; //We declare an instance of the class foo.

	int n1 = f1.get(); //We get a value from the class.
	//f1.set(3); Would not compile due to the fact that f1 is const and void set is not.
	f2.set(3); //We change the value of f2.

	//References
	int c = 3;
	int& rc = c; //C is given an alias, which in this case is rc.
	increment(c);
	cout << rc << endl;
}

int doubleNumberino(uint& number)
{
	number *= 2;

	return number;
}

void CaR_ExerciseI()
{
	uint numberino = 0;
	cout << "Introduce a number from 0 to 100: " << endl;
	cin >> numberino;

	if (numberino > 100 || numberino < 0)
	{
		cout << "The introduced number is not within the range of 0 and 100." << endl;
		return;
	}

	doubleNumberino(numberino);
	cout << "The doubled value is: " << numberino << endl;
}

int misteriousFunction(const int * value)
{
	value = 0;
	return 0;
}

void CaR_ExerciseII()
{
	int num = 5;
	const int * ptr1 = &num;

	misteriousFunction(ptr1);
	cout << *ptr1 << endl;
}

struct Pirate
{
	char const * name;
	int lifeUnits;
};

struct Weapon
{
	char const * name;
	int damage;
};

void printPirateInfo(const Pirate &prt)
{
	cout << "Pirate's name: " << prt.name << "   HP: " << prt.lifeUnits << endl;
}

void printWeaponInfo(const Weapon &wpn)
{
	cout << "Weapon's name: " << wpn.name << "     Damage: " << wpn.damage << endl;
}

void attack(Pirate * lechuck, const Weapon &blade)
{
	lechuck->lifeUnits -= blade.damage;
}

void CaR_ExerciseIII()
{
	Pirate pirate = { "LeChuck", 100 };
	Weapon weapon = { "Sword", 10 };

	printPirateInfo(pirate);
	printWeaponInfo(weapon);

	attack(&pirate, weapon);
	printPirateInfo(pirate);
}