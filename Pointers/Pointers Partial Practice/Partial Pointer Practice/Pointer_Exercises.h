#pragma once
#include <iostream>
#include <string.h>

using namespace std;

void ExerciseI()
{
	int address[10] = {};
	int * ptr = address;

	for (int i = 0; i < 10; i++)
	{
		cout << ptr[i] << endl; //Element of the array.
		cout << &ptr[i] << endl; //Address of the element in the array.
	}
}

void addition(int val1, int val2, int * result)
{
	*result = val1 + val2; //'*' accesses the elements inside the address the pointer points to.

	cout << *result << endl; //Value of result.
	cout << &result << endl; //Address of result.
}

void ExerciseII()
{
	int numI, numII, result; 

	cout << "Introduce the first number: ";
	cin >> numI;
	cout << endl;
	
	cout << "Introduce the second number: ";
	cin >> numII;
	cout << endl;

	addition(numI, numII, &result);
}

void reverseArray(int * array, int sizeArray)
{
	for (int i = sizeArray; i >= 0; i--)
	{
		cout << "Element number " << i + 1 << ": " << *(array + i)  << endl;;
	}
}

void ExerciseIII()
{
	int numbers[10] = {};
	int * elements = numbers;
	int size = 9;

	for (int i = 0; i <= size; i++)
	{
		cout << "Introduce the element number " << i + 1 << ": ";
		cin >> *(elements + i);
		cout << endl;
	}

	reverseArray(elements, size);
}

void absSwap(int * arr1, int * arr2, int sizeArr2)
{
	for (int i = 0; i < sizeArr2; i++)
	{
		if (*(arr2 + i) < 0)
		{
			*(arr1 + i) = (*(arr2 + i) * -1);
		}

		else
		{
			*(arr1 + i) = *(arr2 + i);
		}

		cout << "Array 1 element " << i + 1 << ": " << *(arr1 + i) << "                " << "Array 2 element " << i + 1 << ": " << *(arr2 + i) << endl;
	}
}

void ExerciseIV()
{
	int * arr1 = (int*)calloc(20, sizeof(int));
	int * arr2 = (int*)malloc(20 * sizeof(int));
	int size = 19;

	for (int i = 0; i < size; i++)
	{
		cout << "Introduce the positive or negative number " << i + 1 << ": ";
		cin >> *(arr2 + i);
		cout << endl;
	}
	absSwap(arr1, arr2, size);
}

void printCharPtr(char * myString)
{
	for (int i = 0; myString[i] != '\0'; i++)
	{
		cout << myString[i];
	}
}

int sizeWord(char * word)
{
	int result = 0;

	for (int i = 0; word[i] != '\0'; i++)
	{
		result++;
	}
	return result;
}

void concat(char * word1, char * word2, char * result)
{
	int i = 0;
	for (i = 0; word1[i] != '\0'; i++)
	{
		result[i] = word1[i];
	}

	for (int j = 0; word2[j] != '\0'; i++, j++)
	{
		result[i] = word2[j];
	}
	result[i] = '\0';
}

void ExerciseV()
{
	char wordI[16];
	char wordII[16];

	cout << "Introduce the first word: " << flush;
	cin >> wordI;
	cout << "Introduce the second word: " << flush;
	cin >> wordII;

	int wordlenI = sizeWord(wordI);
	int wordlenII = sizeWord(wordII);

	char * chain = (char*)malloc(wordlenI + wordlenII + 1);

	concat(wordI, wordII, chain);

	printCharPtr(chain);

	cout << endl;

	free(chain);
}