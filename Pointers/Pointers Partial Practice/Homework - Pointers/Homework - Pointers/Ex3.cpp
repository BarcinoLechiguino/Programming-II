#include "Ex3.h"
#include <iostream>
using namespace std;

#define SOLUTION1
#define SOLUTION2

void reverse(int *arr, int size)
{
#ifdef SOLUTION1
	cout << "The integers in reverse order: " << endl;
	for (int i = size - 1; i >= 0; --i) {
		cout << *(arr + i) << " ";
	}
	cout << endl;
#endif

#ifdef SOLUTION2
	cout << "The integers in reverse order: " << endl;
	int *begin = arr + size - 1;
	int *end = arr - 1;
	for (int *ptr = begin; ptr != end; --ptr) {
		cout << *ptr << " ";
	}
	cout << endl;
#endif
}

void ex3()
{
	cout << "Introduce 10 integers: " << flush;

	int arr[10];
	for (int i = 0; i < 10; ++i) {
		cin >> arr[i];
	}

	reverse(arr, 10);
}
