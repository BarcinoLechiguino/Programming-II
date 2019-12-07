#include <iostream>
#include <cstdlib>
#include "Ranking.h"

using namespace std;

void print(int * array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void bubblesort(int * array, int size)
{
	int tmp = 0;
	int num_swaps = 1;

	while (num_swaps != 0)
	{
		num_swaps = 0;

		for (int i = 1; i < size; i++)
		{
			if (array[i] < array[i - 1])
			{
				tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp;
				num_swaps++;
			}
		}
	}
}

int main()
{
	int v[10] = { 9, 1, 8, 2, 7, 3, 6, 4, 5, 0 };
	print(v, 10);
	bubblesort(v, 10);
	print(v, 10);

	system("pause");
	return 0;
}


//void bubblesort(int * array, int size)
//{
//	int num_swaps = 1;
//	int temp = 0;
//
//	while (num_swaps != 0)
//	{
//		num_swaps = 0;
//
//		for (int i = 1; i < size; i++)
//		{
//			//Compares the first two and then compares with the whole array.
//			if (array[i] < array[i - 1])
//			{
//				temp = array[i];
//				array[i] = array[i - 1];
//				array[i - 1] = temp;
//				num_swaps++;
//			}
//		}
//	}
//}