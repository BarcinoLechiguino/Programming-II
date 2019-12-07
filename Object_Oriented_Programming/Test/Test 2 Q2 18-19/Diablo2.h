/* ----------------------------------------------------------------------- */
/*                            Angel Gonzalez T.                            */
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
	//Character () {} //cuidao
	Character(const char * alias, int lPoints) 
	{
		strcpy_s(name, alias);
		lifePoints = lPoints;

	}

	virtual ~Character()  {}

	const char * getName() const { return name; }
	int getLifePoints() const { return lifePoints; }

	virtual int physicalAttack() const = 0;
	virtual int magicAttack() const = 0;

	virtual void applyDamage(int physicalDamage, int magicDamage) = 0;
	friend void evaluateAttack(Character* attacker, Character* defender);
};

int max(int a, int b)
{
	if (a > b) { return a; }
	else { return b; }
}

//////////////BARBARIAN
class Barbarian : public Character
{
public:
	Barbarian() : Character("Barbarian", 20) {}
	int physicalAttack() const override { return 10; }

	int magicAttack() const override { return 0; }

	void applyDamage(int physicalDmg, int magicDmg ) override
	{
		physicalDmg = max(0, physicalDmg - 5);
		magicDmg = max(0, magicDmg - 0);
		lifePoints = max(0, lifePoints - physicalDmg - magicDmg);
	}
};

//////////////PALADIN
class Paladin : public Character
{
public:
	Paladin() : Character("Paladin", 15) {}
	int physicalAttack() const override { return 3; }

	int magicAttack() const override { return 3; }
	void applyDamage(int physicalDmg, int magicDmg) override
	{
		physicalDmg = max(0, physicalDmg - 5);
		magicDmg = max(0, magicDmg - 5);
		lifePoints = max(0, lifePoints - physicalDmg - magicDmg);
	}
};

//////////////WIZARD
class Wizard : public Character
{
public:
	Wizard() : Character("Wizard", 12) {}
	int physicalAttack() const override { return 0; }

	int magicAttack() const override { return 15; }

	void applyDamage(int physicalDmg, int magicDmg) override
	{
		physicalDmg = max(0, physicalDmg - 0);
		magicDmg = max(0, magicDmg - 5);
		lifePoints = max(0, lifePoints - physicalDmg - magicDmg);
	}
};

//////////////EVALUATE ATTACK
void evaluateAttack(Character* attacker, Character* defender)
{
	defender->applyDamage(attacker->physicalAttack(), attacker->magicAttack());
}

#endif