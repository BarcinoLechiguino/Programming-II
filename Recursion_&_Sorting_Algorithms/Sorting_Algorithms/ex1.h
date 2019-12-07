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

	bool sort = true;
	while (sort) {

		sort = false;

		for (int j = 0; j < (size - 1); j++) {
			if (array[j] > array[j + 1]) {
				int temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				sort = true;

			}
		}
	}

}


// Mergesort functions /////////////////////////////////////////////////

void merge(uint32 *array, int begin, int mid, int end)
{
	// Create the two subarrays
	// TODO
	
	int size1 = mid - begin;
	size1++;
	uint32 * subarray1 = new uint32[size1];
	//int * subarray1 = new int[size1];

	int size2 = end - (mid + 1);
	size2++;
	uint32 * subarray2 = new uint32[size2];
	//int * subarray2 = new int[size2];

	// Copy array parts into the subarrays

	int j = 0;
	for (int i = begin; i <= mid; i++) {
		subarray1[j] = array[i];
		j++;
	}
	//if (size1 == 1) subarray1[0] = array[begin];

	int q = 0;
	for (int i = mid + 1; i <= end; i++) {
		subarray2[q] = array[i];
		q++;
	}
	//if (size2 == 1) subarray2[0] = array[mid+1];


	uint32 temp;

	for (int i = 0; i < (size1-1); i++)
	{
		if (subarray1[i] > subarray1[i + 1]) {
			temp = subarray1[i + 1];
			subarray1[i + 1] = subarray1[i];
			subarray1[i] = temp;
		}
	}

	for (int i = 0; i < (size2-1); i++)
	{
		if (subarray2[i] > subarray2[i + 1]) {
			temp = subarray2[i + 1];
			subarray2[i + 1] = subarray2[i];
			subarray2[i] = temp;
		}
	}

	// Initialize indices for tmp1, tmp2, and array, respectively
	int c1 = 0;
	int c2 = 0;
	int k = begin;
	// Merge tmp1 and tmp2 into array
	/*
	for (int k = begin; k < end; k++) {
		if ((c1 < size1) && (c2 < size2)) {
			if (subarray1[c1] >= subarray1[c2]) {
				array[k] = subarray1[c1];
				c1++;
			}
			else if (subarray1[c1] < subarray2[c2]) {
				array[k] = subarray2[c2];
				c2++;
			}
		}
		else {
			if (c1 >= size1) {
				array[k] = subarray2[c2];
				c2++;
			}
			else if (c2 >= size2) {
				array[k] = subarray1[c1];
				c1++;
			}
		}
	}*/

	while (c1 < size1 && c2 < size2) {
		
		if (subarray1[c1] <= subarray2[c2]) {
			array[k] = subarray1[c1];
			c1++; 
		}
		else if (subarray1[c1] > subarray2[c2]) {
			array[k] = subarray2[c2];
			c2++; 
		}
		k++;
	}

	while (c1 < size1) {
		array[k] = subarray1[c1];
		c1++; k++;
	}
	while (c2 < size2) {
		array[k] = subarray2[c2];
		c2++; k++;
	}


	// Delete tmp arrays
	// TODO
	delete[] subarray1;
	delete[] subarray2;
}

void mergesort(uint32 *array, int begin, int end)
{
	if (begin < end) {
		int mid = (begin + end) / 2;
		mergesort(array, begin, mid);
		mergesort(array, mid + 1, end);
		merge(array, begin, mid, end);
	}
}


// Quicksort functions /////////////////////////////////////////////////

int partition(uint32 *array, int begin, int end)
{
	// Take the last value (for example) as the pivot
	// Could be any other value in the array
	uint32 pivot = array[end];

	// Initialize the pivot index at the beginning
	int pivotIndex = begin;

	// Traversing the array:
	// Each value we find that is less than the pivot we push
	// it to the left (swap) and increase the pivot index
	int temp;
	for (int i = begin; i < end; i++) {
		if (array[i] < pivot) {
			temp = array[i];
			array[i] = array[pivotIndex];
			array[pivotIndex] = temp;

			pivotIndex++;
		}	
	}

	// Put the pivot in its position
	temp = array[pivotIndex];
	array[pivotIndex] = array[end];
	array[end] = temp;


	return pivotIndex;
}

void quicksort(uint32 *array, int begin, int end)
{
	if (begin < end) {
		int pivotIndex = partition(array, begin, end);
		quicksort(array, begin, pivotIndex - 1);
		quicksort(array, pivotIndex + 1, end);
	}	
}
