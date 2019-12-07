#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

//Inheritance in C++ and Access modifiers
class Point1D
{
public:
	int x;
	void setx(int X) { x = X; }
};

class Point2D : public Point1D
{
public:
	int y;
	void sety(int Y) { y = Y; }
};

class Point3D : public Point2D
{
public:
	int z;
	void setz(int Z) { z = Z; }
};

//Best way to declare inheritances (one parent and many derived functions)
class Polygon
{
protected:
	int width, height;

public:
	void set_size(int w, int h)
	{
		width = w;
		height = h;
	}
};

class Rectangle : public Polygon
{
public:
	int area() const
	{
		return width * height;
	}
};

class Triangle : public Polygon
{
public:
	int area() const
	{
		return (width * height) / 2;
	}
};

//Order of destruction
class pointI
{
public:
	int x;
	pointI() : x(0) { cout << " Constructor of pointI is called here." << endl; }
	~pointI() { cout << " Destructor of pointI is called here." << endl; }
};

class pointII : public pointI
{
public:
	int y; 
	pointII() : y(0) { cout << " Constructor of pointII is called here." << endl; }
	~pointII() { cout << " Destructor of pointII is caller here." << endl; }
};

//Specialized Constructors
class point1D
{
public: 
	int x;
	point1D(int x_) : x(x_) { cout << " Constructor of point1D is called here." << endl; }
	~point1D() { cout << " Destructor of point1D is called here." << endl; }
};

class point2D : public point1D
{
public:
	int y;
	point2D(int x_, int y_) : point1D(x_), y(y_) { cout << " Constructor of point2D is called here" << endl; }
	~point2D() { cout << " Destructor of point2D is called here." << endl; }
};

void ExamplesV()
{
	//Inheritance in C++ and Access modifiers
	Point1D p1;
	p1.setx(2);
	cout << " " << p1.x << endl;

	Point2D p2;
	p2.setx(2); p2.sety(4);
	cout << " " << p2.x << " " << p2.y << endl;

	Point3D p3;
	p3.setx(2); p3.sety(4); p3.setz(6);
	cout << " " << p3.x << " " << p3.y << " " << p3.z << endl;

	cout << endl;

	//Best way to declare inheritances (one parent and many derived functions)
	Rectangle rect;
	rect.set_size(2, 4);
	cout << " " << rect.area() << endl;

	Triangle tri;
	tri.set_size(4, 6);
	cout << " " << tri.area() << endl;

	//Order of Destruction
	pointII p;

	//Specialized Constructors
	point2D asas(3, 5);
}

//Ex_1: Implementing classes.
class Building
{
protected:
	char name[64];

public:
	Building(const char * bName) //Has to be a pointer if strcpy_s() is to work.
	{
		strcpy_s(name, bName);
	}

	const char * getName() const { return name; }
};

class Warehouse : public Building
{
private:
	int Wood, Rocks, Wheat;

public:
	Warehouse(const char * bName, int wood, int rocks, int wheat) : Building(bName), Wood(wood), Rocks(rocks), Wheat(wheat) {}
	
	void printResources() 
	{
		cout << "Wood: " << Wood << endl;
		cout << "Rocks: " << Rocks << endl;
		cout << "Wheat: " << Wheat << endl; 
	}
};

class House : public Building
{
private:
	int Floors, Inhabitants, Servants;

public:
	House(const char * bName, int floors, int inhabitants, int servants) : Building(bName), Floors(floors), Inhabitants(inhabitants), Servants(servants) {}
	
	void printHouse()
	{
		cout << "Floors: " << Floors << endl;
		cout << "Inhabitants: " << Inhabitants << endl;
		cout << "Servants: " << Servants << endl;
	}
};

class Temple : public Building
{
private: 
	char god[64];
	int priests;

public:
	Temple(const char * bName, const char * Deity, int priests) : Building(bName), priests(priests) 
	{
		strcpy_s(god, Deity);
	}

	void printTemple()
	{
		cout << "Deity: " << god << endl;
		cout << "Priests: " << priests << endl;
	}
};

void Reverse(int * vec)
{
	int * ptr = vec + 4;

	while (vec < ptr)
	{
		int var = *vec;
		*vec = *ptr;
		*ptr = var;

		vec++;
		ptr--;
	}
}

void Inheritance_Buildings()
{
	Warehouse w("East Warehouse", 10, 20, 30);
	House h("Agripa's House", 2, 5, 10);
	Temple t("Mercury's Temple", "Mercury", 3);

	cout << "Warehouse name: " << w.getName() << endl << endl;

	cout << "--- Eastern Warehouse ---" << endl;
	w.printResources();
	cout << endl;
	cout << "--- Agripa's House ---" << endl;
	h.printHouse();
	cout << endl;
	cout << "--- Mercury's Temple ---" << endl;
	t.printTemple();

	cout << endl;

	int array[5] = { 2,4,-6,5,8 };

	for (int i = 0; i < 5; i++) {

		std::cout << " " << *(array + i) << std::flush;
	}

	Reverse(array);
	std::cout << std::endl;

	for (int i = 0; i < 5; i++) {

		std::cout << " " << *(array + i) << std::flush;
	}
	cout << endl;
}