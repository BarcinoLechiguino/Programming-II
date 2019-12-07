#pragma once

// INSTRUCTIONS:
// - Press 'b' to call the bubblesort function
// - Press 'm' to call the mergesort function
// - Press 'q' to call the quicksort function
// - Press space to randomize the tile set
// - Press <esc> to exit

// Change these numbers to resize the tile grid dimensions
#define GRID_WIDTH 100
#define GRID_HEIGHT 100

// Bubblesort functions ////////////////////////////////////////////////
void bubblesort(uint32 * array, int size)
{
	// TODO: Insert your code here
	int num_swaps = 1;
	int temp = 0;

	while (num_swaps != 0)
	{
		num_swaps = 0;

		for (int i = 1; i < size; i++)
		{
			//Compares the first two and then compares with the whole array.
			if (array[i] < array[i - 1])
			{
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				num_swaps++;
			}
		}
	}
}

// Mergesort functions /////////////////////////////////////////////////
void merge(uint32 *array, int begin, int mid, int end)
{
	//TODO 1: Reserve Dynamic memory for 2 arrays.
	uint32 * tmp1 = new uint32[(mid - begin) + 1]; //Sets the size of the array to the amount of elements between begin and mid.
	uint32 * tmp2 = new uint32[end - mid]; //Sets the size of the array to the amount of elements between mid and end.

	//TODO 2: Copy array into the 2 subarrays.
	for (int i = 0; i < (mid - begin) + 1; i++)
	{
		tmp1[i] = array[begin + i]; //Gets all the numbers before mid.
	}

	for (int j = 0; j < (end - mid); j++)
	{
		tmp2[j] = array[mid + j + 1]; //Gets all the numbers after mid. (mid + 0 + 1...)
	}

	// Initialize indexes for tmp1, tmp2, and array, respectively
	int i = 0;
	int j = 0;
	int k = begin;

	//TODO 3: Merge the 2 subarrays into the main array.
	while (i < (mid - begin) + 1 && j < (end - mid))
	{
		if (tmp1[i] <= tmp2[j]) //Compares the 2 subarrays' elements. 
		{
			array[k] = tmp1[i];
			i++;
		}

		else
		{
			array[k] = tmp2[j];
			j++;
		}
		k++;
	}

	//Copy the remaining elements of tmp1 and tmp2 if there are any left.
	while (i < (mid - begin) + 1) //Traverses the array if index has not yet reached the end.
	{
		array[k] = tmp1[i];
		i++;
		k++;
	}

	while (j < (end - mid))
	{
		array[k] = tmp2[j];
		j++;
		k++;
	}

	//TODO 4: Delete the 2 subarrays.
	delete[] tmp1;
	delete[] tmp2;
}

void mergesort(uint32 *array, int begin, int end)
{
	// TODO 1: Insert your code here
	if (begin < end)
	{
		int mid = (begin + end) / 2;

		//mergesort() separates the array into smaller parts.
		mergesort(array, begin, mid);
		mergesort(array, mid + 1, end);

		//merge() merges the smaller parts.
		merge(array, begin, mid, end);
	}
}

// Quicksort functions /////////////////////////////////////////////////
int partition(uint32 *array, int begin, int end)
{
	// Take the last value as the pivot (Could be any other value in the array).
	uint32 pivot = array[end];

	// Initialize the pivot index at the beginning.
	int pivotIndex = begin;

	// TODO 1: Traversing the array. Each value that is found to be of less value than the pivot will be pushed to the left (swap) and pivot index will be increased.
	for (int i = begin; i <= end - 1; i++)
	{
		if (array[i] <= pivot) //We compare the element of index i with the pivot.
		{
			int tmp1 = array[i];
			array[i] = array[pivotIndex];
			array[pivotIndex] = tmp1;
			pivotIndex++;
		}
	}
	// TODO 2: Put the pivot in its position.
	int tmp2 = array[pivotIndex];
	array[pivotIndex] = array[end];
	array[end] = tmp2;

	return pivotIndex;
}

void quicksort(uint32 *array, int begin, int end)
{
	// TODO 1: Insert your code here
	if (begin < end)
	{
		int pivotIndex = partition(array, begin, end);
		quicksort(array, begin, pivotIndex - 1);
		quicksort(array, pivotIndex + 1, end);
	}
}
