#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void reverse(int*array, int sizeArray)
{
	for (int i = sizeArray; i >= 0; i--)
	{
		std::cout << "Element of the array n" << i << ": " << array[i] << std::endl;
	}
}

void ExerciseIII()
{
	int elements[10] = {};
	int *ptr = elements;
	int size = 9;


	for (int i = 0; i <= size; i++)
	{
		std::cout << "Introduce the element of the array n" << i << ": "<< std::endl;
		std::cin >> elements[i];

	}
	std::cout << "The elements of the array in reverse order are: " << std::endl;

	reverse(ptr, size);
}