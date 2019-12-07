#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void ExerciseI()
{
	int elements[10] = {};
	int *ptr = elements;

	for (int i = 0; i < 10; i++)
	{
		elements[i] = i;
		std::cout << &ptr[i] << std::endl;

	}
}