/* ----------------------------------------------------------------------- */
/*                            Angel Gonzalez T                             */
/* ----------------------------------------------------------------------- */

#ifndef EX3_H
#define EX3_H

// Uncomment to test the exercise
#define TEST_EX3

#include <stdlib.h>

void swapReverse(int* vec1, int* vec2, int sizeVecs)
{
	// TO DO: Insert your code here
	int * traverseArray = new int [sizeVecs]();

	
	for (int j = 0; j < sizeVecs; j++)
	{
		for (int i = sizeVecs - 1; i >= 0; j++, i--)
		{
			traverseArray[i] = vec1[j];
			vec1[j] = vec2[i];
			vec2[i] = traverseArray[i];
		}
	}
	delete[] traverseArray;
}


#endif