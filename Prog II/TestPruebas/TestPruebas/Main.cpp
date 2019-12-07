#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Enemy
{
	const char *name; /**< Enemy name. */
	float x; /**< X coordinate. */
	float y; /**< Y coordinate. */
	int life; /**< Life units. */
};

struct Grenade
{
	float x; /**< X coordinate. */
	float y; /**< Y coordinate. */
	float radius; /**< Damage radius. */
	int damage; /**< Damage units. */
};

float distance(float ax, float ay, float bx, float by)
{
	// Pythagorean theorem
	float dx = ax - bx;
	float dy = ay - by;
	float dist = sqrt(dx*dx + dy * dy);
	return dist;
}

//void damageEnemiesWithGrenade(Grenade *grenade, Enemy *enemies, int numEnemies)
//{
//	for (int i = 0; i < numEnemies; i++)
//	{
//		if (grenade->radius > distance(grenade->x, grenade->y, enemies->x, enemies->y))
//		{
//			enemies->life = enemies->life - grenade->damage;
//		}
//
//		else
//		{
//			return;
//		}
//}

int main()
{
	Grenade grenade;
	Enemy enemies;

	grenade.x = 2.0f;
	grenade.y = 4.0f;

	enemies.x = 2.0f;
	enemies.y = 4.0f;

	grenade.radius = 5.0f;

	distance(grenade.x, grenade.y, enemies.x, enemies.y);
	
	std::cout << *distance << std::endl;

	system("pause");
	return 0;
}