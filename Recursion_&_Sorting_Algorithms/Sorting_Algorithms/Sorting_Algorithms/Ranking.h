#pragma once
void merge(int * array, int begin, int mid, int end)
{
	//TODO 1: Reserve Dynamic memory for 2 arrays.
	int * tmp1 = new int[(mid - begin) + 1];
	int * tmp2 = new int[end - mid];

	//TODO 2: Copy array into the 2 subarrays.
	for (int i = 0; i < (begin + end); i++)
	{
		if (i < (mid - begin) + 1)
		{
			tmp1[i] = array[i];
		}

		else
		{
			tmp2[i] = array[i];
		}
	}

	//TODO 3: Merge the 2 subarrays into array.
	for (int i = 0; i < (begin + end); i++)
	{
		if (i < (mid - begin) + 1)
		{
			array[i] = tmp1[i];
		}

		else
		{
			array[i] = tmp2[i];
		}
	}

	//TODO 4: Delete the 2 subarrays.
	delete[] tmp1;
	delete[] tmp2;
}

void mergesort(int * array, int begin, int end)
{
	if(begin < end)
	{
		int mid = (begin + end) / 2;

		//mergesort() separates the array into smaller parts.
		mergesort(array, begin, mid);
		mergesort(array, mid + 1, end);

		//merge() merges the smaller parts.
		merge(array, begin, mid, end);
	}
}

void quicksort(int * array, int begin, int end)
{
	if (begin < end)
	{

	}
}