#include "Ex4.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void initializeArray(int *arr, int size)
{
	for (int i = 0; i < 20; ++i) {
		arr[i] = rand() % 20 - 10;
	}
}

void absSwap(int *arr1, int *arr2, int size)
{
	for (int i = 0; i < size; ++i) {
		arr1[i] = abs(arr2[i]);
	}
}

void printArray(int *arr, int size)
{
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void ex4()
{
	int* arr1 = (int*) calloc(20, sizeof(int));
	int* arr = (int*) malloc(20 * sizeof(int));

	initializeArray(arr, 20);

	absSwap(arr1, arr, 20);

	cout << "Initial Array: " << endl;
	printArray(arr, 20);

	cout << "Array with absolute values: " << flush;
	printArray(arr1, 20);

	free(arr1);
	free(arr);
}
