#include "graphics.h"
#include <iostream>

int D = 3;
float A = 0.4f;

struct point2d
{
	float x;
	float y;
};

void concentric_circles(int level, int x, int y, int radius)
{
	if (level < 5)
	{
			circle(x, y, radius);
			
			concentric_circles(level + 1, x, y + radius / D + radius / D, radius / D);
			concentric_circles(level + 1, x + radius / D + radius / D, y, radius / D);
			concentric_circles(level + 1, x - radius / D - radius / D, y, radius / D);
			concentric_circles(level + 1, x, y - radius / D - radius / D, radius / D);
	}
}

void triangle(const point2d &a, const point2d &b, const point2d &c)
{
	line(a.x, a.y, b.x, b.y);
	line(b.x, b.y, c.x, c.y);
	line(c.x, c.y, a.x, a.y);
}


void sierpinski_triangle(int level, int x, int y, int dx, int dy)
{
	if (level < 5)
	{
		line(x, y, dx, dy);

		sierpinski_triangle(level + 1, 1, 1, 1, 1);
	}
}

void sierpinski_triangleII(int level , point2d a, point2d b, point2d c)
{
	if (level < 10)
	{
		triangle(a, b, c);
	}
}

void main()
{
	/*
	Basic drawing functions.
	void putpixel(int x, int y, int color);
	void line(int x1, int y1, int x2, int y2);
	void rectangle(int left, int top, int right, int bottom);
	void circle(int x, int y, int radius);
	*/

	initwindow(1000, 1000, "Graphics");

	/*line(0, 0, 200, 300);
	line(200, 300, 400, 0);
	line(400, 0, 0, 0);*/

	int level = 0;
	concentric_circles(level, 500, 500, 475);
	sierpinski_triangle(level, 50, 50, 100, 100);
	

	system("pause");
}
