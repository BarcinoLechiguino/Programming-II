/* ----------------------------------------------------------------------- */
/*                            Angel Gonzalez T                             */
/* ----------------------------------------------------------------------- */

#ifndef EX2_H
#define EX2_H

// Uncomment to test the exercise
#define TEST_EX2

int partialSum(int* pIntArray, int pArraySize, int pInitPos, int pEndPos)
{
	// TO DO: Insert your code here
	int addition = 0;

	for (int i = pInitPos; i <= pEndPos; i++)
	{
		if (pEndPos < 0 || pInitPos < 0 || pEndPos >= pArraySize || pInitPos >= pArraySize)
		{
			addition = 0;
		}

		else
		{
			addition += *(pIntArray + i);
		}
	}

	return addition;
}


#endif