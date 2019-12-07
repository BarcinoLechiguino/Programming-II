/* ----------------------------------------------------------------------- */
/*                          Angel Gonzalez Tovar                           */
/* ----------------------------------------------------------------------- */
#include <string.h>

#ifndef DIABLO2_H
#define DIABLO2_H

//////////////CHARACTER
class Character
{
private:
	char name[64];

protected:
	int lifePoints;

public:
	Character(const char * Cname, int lPoints)
	{
		strcpy_s(name, Cname);
		lifePoints = lPoints;
	}
	~Character() {}

	const char * getName() const { return name; }
	int getLifePoints() const { return lifePoints; }
	virtual int physicalAttack() const = 0;
	virtual int magicAttack() const = 0;

	virtual void applyDamage(int physicalDamage, int magicDamage) = 0;
};

int hpLimit(int a, int b)
{
	if (a > b) { return a; }
	else
		return b;
}

//////////////BARBARIAN
class Barbarian : public Character
{
public:
	Barbarian() : Character("Barbarian", 20) {}

	int physicalAttack() const override { return 10; }
	int magicAttack() const override { return 0; }

	void applyDamage(int physicalDamage, int magicDamage) override 
	{
		lifePoints = hpLimit(0, (lifePoints - ((physicalDamage - 5) + (magicDamage - 0))));
	}
};

//////////////PALADIN
class Paladin : public Character
{
public: 
	Paladin() : Character("Paladin", 15) {}

	int physicalAttack() const override { return 3; }
	int magicAttack() const override { return 3; }

	void applyDamage(int physicalDamage, int magicDamage)
	{
		lifePoints = hpLimit(0, (lifePoints - ((physicalDamage - 5) + (magicDamage - 5))));
	}
};
//////////////WIZARD
class Wizard : public Character
{
public:
	Wizard() : Character("Wizard", 12) {}

	int physicalAttack() const override { return 0; }
	int magicAttack() const override { return 15; }

	void applyDamage(int physicalDamage, int magicDamage)
	{
		lifePoints = hpLimit(0, (lifePoints - ((physicalDamage - 0) + (magicDamage - 5))));
	}
};

//////////////EVALUATE ATTACK
void evaluateAttack(Character* attacker, Character* defender)
{
	defender->applyDamage(attacker->physicalAttack(), attacker->magicAttack());
}

#endif