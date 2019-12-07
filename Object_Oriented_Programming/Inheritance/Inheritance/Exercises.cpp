#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#if 0
class Point1D
{
public:
	int x;
	void setX(int X)
	{
		x = X;
	}
};

class Point2D : public Point1D
{
public:
	int y;
	void setY(int Y)
	{
		y = Y;
	}
};

class Point3D : public Point2D
{
public:
	int z;
	void setZ(int Z)
	{
		z = Z;
	}
};

void ExampleI()
{
	Point1D p1;

	p1.setX(1);
	std::cout << p1.x << std::endl;
	
	// Declaring a 2D point
	Point2D p2;
	p2.setX(2); p2.setY(2);
	std::cout << p2.x << " " << p2.y << std::endl;
	
	// Declaring a 3D point.
	Point3D p3;
	
	p3.setX(3); p3.setY(3); p3.setZ(3);
	std::cout << p3.x << " " << p3.y << " " << p3.z << std::endl;

	return;
}
#endif

class Point1D {
public:
	int x;
	Point1D() : x(0) { std::cout << "Ctor Point1D" << std::endl; }
	~Point1D() { std::cout << "Dtor Point 1D" << std::endl; }
};

class Point2D : public Point1D {
public:
	int y;
	Point2D() : y(0) {std::cout << "Ctor Point2D" << std::endl; }
	~Point2D() { std::cout << "Dtor Point 2D" << std::endl; }
};

void ExampleII()
{
	Point2D p;
}