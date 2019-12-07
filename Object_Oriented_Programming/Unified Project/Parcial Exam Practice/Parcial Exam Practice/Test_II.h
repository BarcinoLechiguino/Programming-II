#pragma once
#if 0
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

	virtual ~Character() {}

	const char * getName() const { return name; }
	int getLifePoints() const { return lifePoints; }

	virtual int physicalAttack() const = 0;
	virtual int magicAttack() const = 0;
	virtual void applyDamage(int physicalDamage, int magicalDamage) = 0;
};

int threshold(int a, int b)
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
		physicalDamage = threshold(0, physicalDamage - 5);
		magicDamage = threshold(0, magicDamage - 0);
		lifePoints = threshold(0, lifePoints - physicalDamage - magicDamage);

		//If int is used instead of void.
		/*if ((physicalDamage - 5) + (magicDamage - 0) < 0)
		{
			return lifePoints;

		}

		if (lifePoints <= (physicalDamage - 5) + (magicDamage - 0))
		{
			return lifePoints = 0;
		}

		else
		{
			lifePoints -= (physicalDamage - 5) + (magicDamage - 0);
			return lifePoints;
		}*/
	}
};

//////////////PALADIN
class Paladin : public Character
{
public:
	Paladin() : Character("Paladin", 15) {}

	int physicalAttack() const override { return 3; }
	int magicAttack() const override { return 3; }

	void applyDamage(int physicalDamage, int magicDamage) override
	{
		physicalDamage = threshold(0, physicalDamage - 5);
		magicDamage = threshold(0, magicDamage - 0);
		lifePoints = threshold(0, lifePoints - physicalDamage - magicDamage);

		//If int is used instead of void.
		/*if ((physicalDamage - 5) + (magicDamage - 5) < 0)
		{
			return lifePoints;
		}

		else if (lifePoints <= (physicalDamage - 5) + (magicDamage - 5))
		{
			return lifePoints = 0;
		}

		else
		{
			lifePoints -= (physicalDamage - 5) + (magicDamage - 5);
			return lifePoints;
		}*/
	}
};

//////////////WIZARD
class Wizard : public Character
{
public:
	Wizard() : Character("Wizard", 12) {}

	int physicalAttack() const override { return 0; }
	int magicAttack() const override { return 15; }

	void applyDamage(int physicalDamage, int magicDamage) override
	{
		physicalDamage = threshold(0, physicalDamage - 5);
		magicDamage = threshold(0, magicDamage - 0);
		lifePoints = threshold(0, lifePoints - physicalDamage - magicDamage);

		//If int is used instead of void.
		/*if ((physicalDamage - 0) + (magicDamage - 5) < 0)
		{
			return lifePoints;
		}

		else if (lifePoints <= (physicalDamage - 0) + (magicDamage - 5))
		{
			return lifePoints = 0;
		}

		else
		{
			lifePoints -= (physicalDamage - 0) + (magicDamage - 5);
			return lifePoints;
		}*/
	}
};

//////////////EVALUATE ATTACK
void evaluateAttack(Character* attacker, Character* defender)
{
	defender->applyDamage(attacker->physicalAttack(), attacker->magicAttack());
}
#endif