#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

//Encapsulation
class Entity
{
private:
	const char * name;
	int x, y;
	int health;

public:
	const char * getName() const;
	void move(int dx, int dy);
	void applyDamage(int damage);
};

//Data Members and Member Functions
class Point
{
public:
	//Data Members
	int x, y;

	//Member Functions
	void move(int dx, int dy)
	{
		x += dx;
		y += dy;
	}
};

//Access Limiters and Const Methods
class PointII
{
private:
	int x, y; //The data members are declared as private, which means that they cannot be accessed from outside the class 

public:
	//The private data members can be modified from outside if a public function calls them and then the function is called outside.
	void move(int dx, int dy) { x += dx; y += dy; };
	int getx() const { return x; } //Functions are declared as const by putting the keyword at the end of the method signature.
	int gety() const { return y; } //The function is const as it will only consult the data member, not modify it.
	void setx(int newx) { x = newx; }
	void sety(int newy) { y = newy; }

};

//Constructors and destructors
class PointIII
{
private:
	int x, y;

public:
	//Constructor
	PointIII() { cout << "constructor" << endl; }
	~PointIII() { cout << "destructor" << endl; }
	
	void move(int dx, int dy) { x += dx; y += dy; };
	int getx() const { return x; } 
	int gety() const { return y; } 
	void setx(int newx) { x = newx; }
	void sety(int newy) { y = newy; }

};

 //Member Initialization Constructor
class PointIV
{
private:
	int x, y;
	Entity *entities; //An array of entities.

public:
	//Initializing data members
	//PointIV(){} //It does not initialize anything.
	PointIV() : x(0), y(0) {} //Initializes both data members to 0.
	//PointIV() { x = 0; y = 0; } //Also initializes both data members to 0.
	
	//Parameterized constructors
	PointIV(int x0, int y0) : x(x0), y(y0) {} //Declares a parameterized constructor.

	//Copy Constructor
	PointIV(const PointIV &p) : x(p.x), y(p.y) {} // Declares a copy constructor that will copy the data members of the parameter.

	//The "this" keyword
	PointIV(char x, char y)
	{
		this->x = x; //We specify through pointers which variable x is it.
		this->y = y; ////We specify through pointers which variable y is it.
	}

	//Memory Management in classes
	PointIV(int numEntities) //Constructor
	{
		entities = new Entity[numEntities];
	}

	~PointIV() { delete[] entities; }
};

void ExamplesIII()
{
	//Data Members
	Point p1, p2; //Declares various instances of the class Point.
	p1.x = p1.y = 1;
	p2.x = p2.y = 5;

	//Member Functions
	cout << " " << p1.x << "  " << p1.y << endl;
	p1.move(2, 4); //The function is accessed with the p1 instance of the class.
	cout << " " << p1.x << "  " << p1.y << endl;

	//Accessing members through pointers
	Point * P1 = new Point; //We declare a pointer instance to the class Point in dynamic memory.
	
	P1->x = P1->y = 2; // "->" is used instead of "." to access the data members and member functions.
	cout << " " << P1->x << "  " << P1->y << endl;
	
	P1->move(2, 4);
	cout << " " << P1->x << "  " << P1->y << endl;
	
	delete P1; //The dynamic memory allocated is freed.

	//Access Limiters and Const methods
	PointII p;
	
	p.setx(1); //A new value for the private data member x.
	p.sety(1); //A new value for the private data member y.
	//cout << " " << p.getx() << "  " << p.gety << endl; //getx() and gety() are used to consult the x and y private data members.

	p.move(2, 4);
	//cout << " " << p.getx() << "  " << p.gety << endl;

	//Constructors and destructors
	{
		PointIII P; //The constructor of P is called here.
		P.setx(1); p.sety(2);
	} //P destructor is called here.

	PointIII * ptr = new PointIII; //The ptr constructor is called here.
	ptr->setx(3);
	ptr->sety(4);
	delete ptr; //The ptr destructor is called here. 

	//Member Initialization Constructors
	PointIV point; //Default constructor.
	PointIV pointz(2, 4); //Parameterized constructor.

	//Copy Constructor
	PointIV copy(pointz); //Copy constructor.
	
}


class Pixel
{
private:
	short int r, g, b;

public:

	Pixel() : r(0), g(0), b(0) {}

	Pixel(short int red, short int green, short int blue) : r(red), g(green), b(blue) {}
	
	Pixel mix(Pixel base)
	{
		Pixel newMix;

		newMix.r = (r + base.r) / 2;
		newMix.g = (g + base.g) / 2;
		newMix.b = (b + base.b) / 2;

		return newMix;
	}

	short int Red() const { return r; }
	short int Green() const { return g; }
	short int Blue() const { return b; }
};

void Class_ExerciseI()
{
	Pixel black;
	Pixel blue(0, 0, 255);
	Pixel red(255, 0, 0);
	Pixel mixed = red.mix(blue);

	cout << black.Red() << " " << black.Green() << " " << black.Blue() << endl;
	cout << mixed.Red() << " " << mixed.Green() << " " << mixed.Blue() << endl;
}

class Clock
{
private:
	short int hours, minutes, seconds;

public:
	Clock(){} //Default constructor
	Clock(short int h, short int m, short int s) : hours(h), minutes(m), seconds(s) {} //Parameterized constructor

	short int Hours() const { return hours; }
	short int Minutes() const { return minutes; }
	short int Seconds() const { return seconds; }

#if 0
	bool areEquals(Clock clock1, Clock clock2) 
	{
		if (clock1.hours == clock2.hours && clock1.minutes == clock2.minutes && clock1.seconds == clock2.seconds)
		{
			return true;
		}

		else
		{
			return false;
		}
	}
#endif

	void areEquals(Clock clock1, Clock clock2)
	{
		if (clock1.hours == clock2.hours && clock1.minutes == clock2.minutes && clock1.seconds == clock2.seconds)
		{
			cout << "The time shown in both clocks is equal." << endl;
		}

		else
		{
			cout << "The time shown in both clocks is not equal." << endl;
		}
	}

	void fasterClock(Clock clock1, Clock clock2)
	{
		if (clock1.hours < clock2.hours)
		{
			cout << "Clock 1 shows an earlier time than clock 2." << endl;
		}

		if (clock1.hours > clock2.hours)
		{
			cout << "Clock 2 shows an earlier time than clock 1." << endl;
		}

		if (clock1.hours == clock2.hours)
		{
			if (clock1.minutes < clock2.minutes)
			{
				cout << "Clock 1 shows an earlier time than clock 2." << endl;
			}

			if (clock1.minutes > clock2.minutes)
			{
				cout << "Clock 2 shows an earlier time than clock 1." << endl;
			}

			if (clock1.minutes == clock2.minutes)
			{
				if (clock1.seconds < clock2.seconds)
				{
					cout << "Clock 1 shows an earlier time than clock 2." << endl;
				}

				if (clock1.seconds > clock2.seconds)
				{
					cout << "Clock 2 shows an earlier time than clock 1." << endl;
				}
			}
		}
	}

	void seth(short int Hours) { hours = Hours; }
	void setm(short int Minutes) { minutes = Minutes; }
	void sets(short int Seconds) { seconds = Seconds; }

	void printTime(Clock clock1, Clock clock2)
	{
		cout << " " << clock1.Hours() << ":" << clock1.Minutes() << ":" << clock1.Seconds() << endl;
		cout << " " << clock2.Hours() << ":" << clock2.Minutes() << ":" << clock2.Seconds() << endl;
	}
};

void Class_ExerciseII()
{
	Clock clock;
	Clock clock1 (23, 59, 59);
	Clock clock2;

	clock2.seth(23); clock2.setm(59), clock2.sets(59);

	clock.areEquals(clock1, clock2);
	clock.fasterClock(clock1, clock2);
	clock.printTime(clock1, clock2);
}

class Vec3
{
public:
	float x, y, z;

	Vec3() : x(0), y(0), z(0) {}
	Vec3(float xf, float yf, float zf) : x(xf), y(yf), z(zf) {}
	Vec3(const Vec3 &copy) : x(copy.x), y(copy.y), z(copy.z) {}

	float length(Vec3 vect)
	{
		float vecSumatory = x * x + y * y + z * z;
		float vecLength = sqrt(vecSumatory);

		cout << "The length of the vector is: " << vecLength << endl;

		return vecLength;
	}

	Vec3 inverse(const Vec3 original)
	{
		Vec3 inv;
		inv.x = original.x * (-1);
		inv.y = original.y * (-1);
		inv.z = original.z * (-1);
		
		cout << "The inverse of the vector is: " << inv.x << " " << inv.y << " " << inv.z << endl;

		return inv;
	}
};

float dotP(const Vec3 vec1, const Vec3 vec2)
{
	float dProduct = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	
	cout << "The dot product of the vector is: " << dProduct << endl;

	return dProduct;
}

void Class_ExerciseIII()
{
	Vec3 vec1;
	Vec3 vec2 (2.8f, 2.2f, 2.3f);
	Vec3 vec3(vec2);

	vec1.length(vec1);
	vec2.length(vec2);
	vec3.length(vec3);

	vec1.inverse(vec2);

	dotP(vec2, vec3);
}
#if 0
class HighscoreEntry
{
private:
	const char * string;
	int score;

public:
	HighscoreEntry() {} //Default constructor.
	HighscoreEntry(const char string[64], int highScore) : string(string), score(highScore) {}
	HighscoreEntry(const HighscoreEntry &copy) : string(copy.string), score(copy.score) {}

	const char * toString()
	{
		HighscoreEntry result;
		const char * results = ("%s-%d", result.string, result.score);

		return  results;
	}
	
	bool sameAs(const HighscoreEntry original)
	{
		HighscoreEntry end;

		if (strcmp(end.string, original.string) != 0 && end.score == original.score)
		{
			return true;
		}

		else
		{
			return false;
		}
	}
};

void Class_ExerciseIV()
{
	HighscoreEntry h1("Homer", 9999);
	HighscoreEntry h2("Bart", 7777);
	HighscoreEntry h3;
	HighscoreEntry h4(h2);
	
	const char *str = h1.toString();
	cout << "h1: " << str << endl;
	cout << "h2: " << h2.toString() << endl;
	cout << "h3: " << h3.toString() << endl;
	
	if (h2.sameAs(h4))
	{
		cout << "h2 and h4 are the same" << endl;
	}

	else 
	{
		cout << "h2 and h4 are not the same" << endl;
	}

}
#endif

class Module
{
private:
	const char * name;
	int numIterations;
	
public:
	Module() {}; //Default constructor
	Module(const char * string, int numIterations) : name(string), numIterations(numIterations)  {}

	void Update(int currentIteration)
	{
		if (currentIteration < numIterations)
		{
			cout << name << endl;
		}
	}
};

void Class_ExerciseV()
{
	Module Modules[3] = {
		Modules[0] = Module("Input", 5),
		Modules[1] = Module("Render", 7),
		Modules[2] = Module("Logic", 10)
	};

	for (int i = 0; i < 10; i++) 
	{

		std::cout << "--Iteration: " << i << std::endl;

		for (int j = 0; j < 3; j++) {

			Modules[j].Update(i);
		}

		std::cout << std::endl;
	}
}