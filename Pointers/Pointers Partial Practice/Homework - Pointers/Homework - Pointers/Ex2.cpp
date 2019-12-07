#include "Ex2.h"
#include <iostream>
using namespace std;

void sum(int v1, int v2, int *res)
{
	*res = v1 + v2;
}

void ex2()
{
	int val1, val2;

	cout << "Introduce the first int: " << flush;
	cin >> val1;

	cout << "Introduce the second int: " << flush;
	cin >> val2;

	int result;
	sum(val1, val2, &result);

	cout << "val1 + val2 = " << result << endl;
}