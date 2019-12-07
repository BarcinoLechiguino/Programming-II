#pragma once
//Exercise I:
Pixel black;
Pixel blue(0, 0, 255);
Pixel red(255, 0, 0);
Pixel mixed = red.mix(blue);
std::cout << black.r << " "

const float avg

//Exercise I
class Pixel
{
private:
	short int red;
	short int green;
	short int blue;

public:
	Pixel() : red(0), green(0), blue(0) {}
	Pixel(short int r, short int g, short int b) : red(r), green(g), blue(b) {}

	Pixel mix(Pixel p)
	{
		Pixel newp(avg(this->red, p.red), avg(this->green, p.green), avg(this->blue, p.green) {}
		return newp;
	}
	short int r() const { return red; }
	short int g() const { return green; }
	short int b() const { return blue; }
};

class HighScore
{
private:
	char str[64];

public:
	int Highscore() {}
	int Highscore(const char *, int) {}
	int Highscore(const Highscore, &hs) {}
};
