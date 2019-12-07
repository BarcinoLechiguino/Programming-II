#include "Ex1.h"
#include <iostream>
using namespace std;

void ex1()
{
	int arr[10];

	for (int i = 0; i < 10; ++i) {
		arr[i] = (int)&arr[i];
		cout << arr[i] << endl;
	}
}