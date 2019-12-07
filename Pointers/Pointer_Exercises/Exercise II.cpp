#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void Sum(int val1, int val2, int*result)
{
	*result = val1 + val2;

	std::cout << "The result is: " << *result << std::endl;
}

void ExerciseII()
{
	int val1 = 0;
	int val2 = 0;
	int *result = 0;

	printf("Introduce the first value: \n");
	scanf_s("%d", &val1, sizeof(val1));
	printf("Introduce the second value: \n");
	scanf_s("%d", &val2, sizeof(val2));

	Sum(val1, val2, result);
}