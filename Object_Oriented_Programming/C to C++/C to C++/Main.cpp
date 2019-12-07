#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void doubleNum(unsigned short& num)//int value
{
	num = num * 2;
}

void ExerciseI()
{
	unsigned short value = 0;
	//unsigned short& doubleValue = value;
	std::cout << "Introduce a number from 0 to 100: ";
	std::cin >> value;
	doubleNum(value);
	std::cout << value << std::endl;
}




int main()
{
	ExerciseI();

	system("pause");
	return 0;
}