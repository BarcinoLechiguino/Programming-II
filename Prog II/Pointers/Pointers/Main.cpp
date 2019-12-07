#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void clear(int *x)
{
	*x = 0;
}

void practice()
{
	int energy = 100;
	int *ptr = &energy;
	*ptr = 50;
	std::cout << energy << std::endl;
	//printf("%d", energy);

	int val = 10;
	std::cout << "Before clear: " << val << std::endl;
	clear(&val);
	std::cout << "After clear: " << val << std::endl;

	int bar = 3;
	int *foo = &bar;
	int *baz = foo; //Pointer to the address where the previous pointer "foo" was pointing at.
	int **zap = &foo; //Pointer to another pointer's address in memory.
	std::cout << bar << std::endl;
	std::cout << zap << std::endl;
}

void ExerciseI()
{
	int num = 3;
	std::cout << "Memory address of num: "<< &num << std::endl;
	int *ptr = &num;
	std::cout << "Memory address where the pointer points: " << ptr << std::endl;
	std::cout << "Variable stored in the memory address: " << *ptr << std::endl;
	*ptr = 20;
	std::cout << "Changed value of num: " << *ptr << std::endl;
}

void pointerArrays()
{
	int vec[10] = {};
	int *ptr = &vec[2]; //We use the & to give the pointer the memory address. Without it it would give an integer to the pointer causing a crash.
}

void pointerArithmetics()
{
	int nums[4] = { 0, 1, 2, 3 };
	int *p = nums;

	for (int i = 0; i <= 3; i++)
	{
		std::cout << p[i] << std::endl;
	}

}

void ExerciseII()
{
	int vec[3] = { 1, 2, 3 };
	int *ptr0 = vec;
	
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Memory adress of the element " << i << ":" << &ptr0[i] << std::endl;
		std::cout << "Variable stored in the element " << i << ":" << ptr0[i] << std::endl;
		printf("\n");
	}

	printf("\n");

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Memory adress of the element " << i << ":" << ptr0 + i << std::endl;
		std::cout << "Variable stored in the element " << i << ":" << *(ptr0 + i) << std::endl;
	}

	printf("\n");

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Memory adress of the element " << i << ":" << ptr0 << std::endl;
		std::cout << "Variable stored in the element " << i << ":" << *ptr0 << std::endl;
		ptr0++;
	}
}

void increment(int *num)
{
	(*num)++;
}

void pointersAsArguments()
{
	int n = 3;
	increment(&n);
	std::cout << n << std::endl;
	//printf("%d", n);
}

void add5(int *p)
{
	*p += 5;
	//*p = *p + 5;
}

int sumAll(int *ptr, int size)
{
	int result = 0;
	
	for (int i = 0; i < size; i++)
	{
		result += ptr[i];
	}

	return result;
}

void ExerciseIII()
{
	//Exercise I:
	int num = 5;
	add5(&num);
	std::cout << num << std::endl;

	//Exercise II:
	int array[3] = { 1, 2, 3 };
	int sum = sumAll(array, 3);
	std::cout << sum << std::endl;
}

void charPointers()
{
	const char *p = "Hello";

	for (int i = 0; p[i] != '\0'; i++)
	{
		std::cout << p[i] << std::endl;
	}
}

void printString(const char *p, int size)
{
	for (int i = 0; p[i] != '\0'; i++)
	{
		std::cout << p[i] << std::endl;
	}
}

void ExerciseIV()
{
	const char *p = "Hello world of pointers";

	printString(p, 64);
}

void dynamicMemoryInC()
{
	int* nums = (int*)malloc(4* sizeof(int));
	int* more_nums = (int*)calloc(4, sizeof(int));

	for (int i = 0; i < 4; i++)
	{
		std::cout << *(nums + i) << std::endl;
		std::cout << *(more_nums + i) << std::endl;
		nums[i] = 0;
		std::cout << *(nums + i) << std::endl;
		std::cout << *(more_nums + i) << std::endl;
	}

	free(nums);
	free(more_nums);
	nums = more_nums = nullptr;
	return;
}

void ExerciseV()
{
	//Exercise I:
	int* nums = (int*)malloc(4 * sizeof(int));
	
	for (int i = 0; i < 4; i++)
	{
		nums[i] = i + 1;
		std::cout << *(nums + i) << std::endl;
	}

	free(nums);
	nums = nullptr;

	printf("\n");

	//Exercise II:
	int* more_nums = (int*)calloc(4, sizeof(int));

	more_nums[1] = 2;
	
	for (int i = 0; i < 4; i++)
	{

		std::cout << *(more_nums + i) << std::endl;
	}

	free(more_nums);
	more_nums = nullptr;
}

void dynamicMemoryInCPlusPlus()
{
	//Example I:
	int* num = new int; //Always use delete when using int.
	int* nums = new int[4]; //Always use delete[] when using int[].

	for (int i = 0; i < 4; i++)
	{
		//num[i] = 0;
		nums[i] = 0;
		//std::cout << *(num + i) << std::endl;
		std::cout << *(nums + i) << std::endl;
	}

	delete num;
	delete[] nums;

	printf("\n");

	//Example II:
	int* numII = new int();
	int* numsII = new int[4]();

	for (int i = 0; i < 4; i++)
	{
		//std::cout << *(numII + i) << std::endl;
		std::cout << *(numsII + i) << std::endl;
	}

	delete numII;
	delete[] numsII;
	return;
}

int main()
{
	practice();
	printf("\n");
	ExerciseI();
	pointerArrays();
	printf("\n");
	ExerciseII();
	printf("\n");
	pointerArithmetics();
	pointersAsArguments();
	printf("\n");
	ExerciseIII();
	printf("\n");
	charPointers();
	printf("\n");
	ExerciseIV();
	printf("\n");
	dynamicMemoryInC();
	printf("\n");
	ExerciseV();
	printf("\n");
	dynamicMemoryInCPlusPlus();
	printf("\n");

	system("pause");
	return 0;
}
