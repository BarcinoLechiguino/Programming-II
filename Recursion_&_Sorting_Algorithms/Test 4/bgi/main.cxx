#include "graphics.h"
#include <iostream>
#include <cstdlib>

// Cantor set //////////////////////////////////////////////////////////////////

void cantor(int depth, float x1, float x2, float y)
{
	// TODO
}


// Circles /////////////////////////////////////////////////////////////////////

void circles(int depth, int x, int y, int radius)
{

}


// 2D vector utility ///////////////////////////////////////////////////////////

struct vec2
{
	float x, y;
	vec2() : x(0), y(0) {}
	vec2(float X, float Y) :x(X), y(Y) {}
};
vec2 operator+(const vec2 &a, const vec2 &b) { return vec2(a.x + b.x, a.y + b.y); }
vec2 operator-(const vec2 &a, const vec2 &b) { return vec2(a.x - b.x, a.y - b.y); }
vec2 operator-(const vec2 &b) { return vec2(- b.x, - b.y); }
vec2 operator*(float v, const vec2 &a) { return vec2(a.x * v, a.y * v); }
vec2 operator*(const vec2 &a, float v) { return vec2(a.x * v, a.y * v); }
vec2 operator/(const vec2 &a, float v) { return vec2(a.x / v, a.y / v); }
float dot(const vec2 &a, const vec2 &b) { return a.x * b.x + a.y * b.y; }
float length(const vec2 &v) { return sqrt(dot(v, v)); }
vec2 perpendicular(const vec2 &v) { return vec2(v.y, -v.x); }
vec2 normalize(const vec2 &v) { return v / length(v); }


// Sierpinski fractal //////////////////////////////////////////////////////////


void triangle(const vec2 &a, const vec2 &b, const vec2 &c)
{
	line(a.x, a.y, b.x, b.y);
	line(b.x, b.y, c.x, c.y);
	line(c.x, c.y, a.x, a.y);
}

//
// Sierpinski fractal
//
//              top
//               o
//              / \
//           a o---o b
//            /\   /\
//           /  \ /  \
//          o----o----o
//  bottomLeft   c   bottomRight
//
void sierpinski(int depth, const vec2 &bottomLeft, const vec2 &bottomRight, const vec2 &top)
{
	// TODO
}


// Tree fractal ////////////////////////////////////////////////////////////////

void tree(int depth, const vec2 &a, const vec2 &b)
{
	// TODO
}


// Spiky triangle //////////////////////////////////////////////////////////////

void spiky_triangle(int depth, const vec2 &a, const vec2 &b, const vec2 &c)
{
	// TODO
}


void draw_square(vec2 &top, vec2 &left, vec2 &bottom, vec2 &right)
{
	line(left.x, left.y, top.x, top.y);
	line(top.x, top.y, right.x, right.y);
	line(right.x, right.y, bottom.x, bottom.y);
	line(bottom.x, bottom.y, left.x, left.y);
}

//void draw_squareII(int top, int left, int bottom, int right)
//{
//	line(left.x, left.y, top.x, top.y);
//	line(top.x, top.y, right.x, right.y);
//	line(right.x, right.y, bottom.x, bottom.y);
//	line(bottom.x, bottom.y, left.x, left.y);
//}

float P = 0.4;
float Q = 1.4;

vec2 top_left(vec2& top_left)
{
	top_left.x * Q;
	top_left.y * P;

	return top_left;
}

vec2 bottom_right(vec2& bottom_right)
{
	bottom_right.x * P;
	bottom_right.y * Q;

	return bottom_right;
}

void square(int depth, vec2 &top, vec2 &left, vec2 &bottom, vec2 &right)
{	
	if (depth < 5)
	{
		draw_square(top, left, bottom, right);
		
		square(depth + 1, top * Q, left * Q, bottom * P, right * P);
		square(depth + 1, top * P, left * P, bottom * P, right * P);
		square(depth + 1, top * P, left * P, bottom * P, right * P);
		square(depth + 1, top * P, left * P, bottom * P, right * P);
	}
}

// Main function ///////////////////////////////////////////////////////////////
void main()
{
	/*
	Basic drawing functions.
	void putpixel(int x, int y, int color);
	void line(int x1, int y1, int x2, int y2);
	void rectangle(int left, int top, int right, int bottom);
	void circle(int x, int y, int radius);
	*/
	vec2 top(100, 100);
	vec2 left(100, 500); 
	vec2 bottom(500, 500);
	vec2 right(500, 100);


	initwindow(1000, 1000, "Graphics");

	int depth = 0;

	if (depth == 1)
	{
		top.x += 40;
	}
	square(depth, top, left, bottom, right);
	//draw_square(top, left, bottom, right);

#if 0
	cantor(0, 10, 900, 100);
#endif

#if 0
	circles(0, 500, 500, 400);
#endif

#if 0
	const vec2 bottomLeft(100, 1000 - 100);
	const vec2 bottomRight(900, 1000 - 100);
	const vec2 top(500, 1000 - 770);
	triangle(bottomLeft, bottomRight, top);
	sierpinski(0, bottomLeft, bottomRight, top);
#endif

#if 0
	const vec2 a(500, 900);
	const vec2 b(500, 500);
	tree(0, a, b);
#endif

#if 0
	const vec2 a(100, 1000 - 260);
	const vec2 b(900, 1000 - 260);
	const vec2 c(500, 1000 - 940);
	spiky_triangle(0, a, b, c);
#endif

	system("pause");
}
