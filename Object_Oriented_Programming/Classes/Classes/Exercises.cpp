#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Point
{
private: 
	int x;
	int y;

public:
	Point() { std::cout << "constructor" << std::endl; } //Constructor
	~Point() { std::cout << "destructor" << "  " << x << " " << y << std::endl; } //Destructor

	//Point() { } //Constructor which does not initialize x and y.
	//~Point() { } //Destructor.

	void move(int dx, int dy)
	{
		x += dx; 
		y += dy;
	}

	int getx() const { return x; } //Const method.
	int gety() const { return y; } //Const method.
	void setx(int newx) { x = newx; }
	void sety(int newy) { y = newy; }
};

void ExerciseI()
{
	Point p;

	p.setx(1);
	p.sety(1);
	std::cout << p.getx() << " " << p.gety() << std::endl;
	
	return;
}

void ExerciseII()
{
	Point p;

	std::cout << p.getx() << " " << p.gety() << std::endl;

	return;
}

class Vec3
{
public:
	float x, y, z;

	Vec3() : x(0), y(0), z(0) {};
	Vec3(float X, float Y, float Z) : x(X), y(Y), z(Z) {};
	Vec3(const Vec3 &v2) { x = v2.x; y = v2.y; z = v2.z; };

	Vec3 inverse()
	{
		Vec3 inv(-x, -y, -z);
		return inv;
	}

	float length() const
	{
		float power = x * x + y * y + z * z;
		int length = sqrtf(power);

		return length;
	}

};

int dotP(const Vec3 vec1, const Vec3 vec2)
{
	int dot = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	return dot;
}

void ExerciseIII()
{
	Vec3 vector;
	Vec3 vector1 = { 1, 1, 1 };
	Vec3 vector2 = { 2, 2, 2 };

	std::cout << "The length of vector 1 is: " << vector1.length() << std::endl;
	std::cout << "The length of vector 2 is: " << vector2.length() << std::endl;

	Vec3 vector3 = vector2.inverse();
	std::cout << vector3.x << " " << vector3.y << " " << vector3.z << std::endl;

	std::cout << "Vector"

	//{
	//	//Object created in the stack:
	//	Point p1; //The p1 constructor is called here.
	//	p1.setx(1);
	//	p1.sety(2);
	//}//The p1 destructor called here.
	//
	//Point * p2 = new Point; //The p2 constructor is called here.
	//p2->setx(3);
	//p2->sety(4);
	//delete p2; //The p2 destructor is called here.

	return;
} 

void ExerciseIV()
{
	Point p1; //The p1 constructor will be called here.

	std::cout << p1.getx() << " " << p1.gety() << std::endl;

	return;
}

class Module
{
	private:
		char * string[64];
		unsigned short numIterations;

	public:
		Module(char * stringI, unsigned short numIterationsI): string[](stringI), numIterations(numIterationsI)
		{
		
		}

		void update()
		{
			
		}
};

void ExerciseV()
{

}


//Const
const int MAX_PLAYERS = 4;

void Const()
{
	int val = 0;
	int * ptr1 = &val; //We can modify the value and where the pointer is pointing.
	const int * ptr2 = &val; //We can modify the pointer but not the value. (Read from right to left)
	int * const ptr3 = &val; //We can modify the value but not where the pointer is pointing.
	const int * const ptr4 = &val; //We cannot modify neither the value or the pointer.
	
	int array[30]; //The statement that works as the array is int * const ptr3 = &val;.
}


//Class

class Player
{
private:
	float a;

public:
	
	float x, y;

	void copyFrom(const Player &player)
	{

	}

	void copyTo(Player &player) const
	{
		player.x = a;
	}
};

void Class()
{
	Player p1, p2; //Declares how the class elements will be called in this function.
	p1.copyFrom(p2); // 1 player
	p1.copyTo(p2); // 2 players. 
}