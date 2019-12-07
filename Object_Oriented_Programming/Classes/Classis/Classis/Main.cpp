#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Pixel
{
private:
	short int red;
	short int green;
	short int blue;

public:

};

int main()
{
	//Exercise I
	Pixel black;
	Pixel blue(0, 0, 255);
	Pixel red(255, 0, 0);
	Pixel mixed = red.mix(blue);

	std::cout << black.red() << " " << black.green() << " " << black.blue() << std::endl;
	std::cout << mixed.red() << " " << mixed.green() << " " << mixed.blue() << std::endl;
}