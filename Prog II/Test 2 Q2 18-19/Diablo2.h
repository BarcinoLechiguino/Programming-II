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
	const char * name;

protected:
	int lifePoints;

public:
	//Character () {} //cuidao
	Character(const char * alias, int lPoints) : name(alias), lifePoints(lPoints) {}

	virtual ~Character()  {}

	const char * getName() const { return name; }
	int getLifePoints() const { return lifePoints; }

	virtual int physicalAttack() const = 0;
	virtual int magicAttack() const = 0;

	virtual int applyDamage(int physicalDamage, int magicDamage) const = 0;
	friend void evaluateAttack(Character* attacker, Character* defender);
};

//////////////BARBARIAN
class Barbarian : public Character
{
public:
	Barbarian() : Character("Barbarian", 20) {}
	int physicalAttack() const override { return 10; }

	int magicAttack() const override { return 0; }

	int applyDamage(int physicalDmg, int magicDmg ) const override
	{
		return lifePoints - (physicalDmg - 5) + (magicDmg - 0);
	}
};

//////////////PALADIN
class Paladin : public Character
{
public:
	Paladin() : Character("Paladin", 15) {}
	int physicalAttack() const override { return 3; }

	int magicAttack() const override { return 3; }

	int applyDamage(int physicalDmg, int magicDmg) const override
	{
		return lifePoints - (physicalDmg - 5) + (magicDmg - 5);
	}
};

//////////////WIZARD
class Wizard : public Character
{
public:
	Wizard() : Character("Wizard", 12) {}
	int physicalAttack() const override { return 0; }

	int magicAttack() const override { return 15; }

	int applyDamage(int physicalDmg, int magicDmg) const override
	{
		 return lifePoints - (physicalDmg - 0) + (magicDmg - 5);
	}
};

//////////////EVALUATE ATTACK
void evaluateAttack(Character* attacker, Character* defender)
{
	 defender->lifePoints -= defender->applyDamage(attacker->physicalAttack(), attacker->magicAttack());
}

#endif