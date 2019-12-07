#pragma once
#include <iostream>

void reverse(int *vec) {

	int *pointer2 = vec + 4;

	while (vec < pointer2) {

		int var = *vec;
		*vec = *pointer2;
		*pointer2 = var;

		vec++;
		pointer2--;
	}
}