#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Trees.h"
#include "ClassTree.h"

using namespace std;

void recursiveFunc(int i)
{
	if (i <= 10)
	{
		std::cout << "Hola" << " " << i << std::endl;
		recursiveFunc(i + 1);
		std::cout << "Osea jelou???? :V" << " " << i << std::endl;
	}

	else
	{
		std::cout << "Adios" << " " << std::endl;
	}
}

int recursiveFactorial(int n)
{
	if (n != 0)
	{
		return n * recursiveFactorial(n - 1);
	}

	if (n == 0)
	{
		return n = 1;
	}
}

int recursiveFibonacci(int n)
{
	if (n == 0)
	{
		return n = 0;
	}

	else if (n == 1)
	{
		return n = 1;
	}

	else
	{
		return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
	}


}

void countUp(unsigned int val)
{

}

int numTrues(bool vec[], int sizeVec, unsigned int index)
{
	if (index < sizeVec)
	{
		int count = numTrues(vec, sizeVec, index + 1);

		if (vec[index] == true)
		{
			count++;
		}
		return count;
	}
	
	else
	{
		return 0;
	}
}

bool searchRec(int vec[], int sizeVec, unsigned int index, int val)
{
	if (index < sizeVec)
	{
		if (vec[index] == val)
		{
			cout << "The value is in the array." << endl;
			return true;
		}
	}

	else
	{
		cout << "The value is not in the array." << endl;
	}
}

void clear(Node * n)
{
	if (n != nullptr)
	{
		clear(n->left);
		clear(n->right);
		delete n;
	}
}

int main()
{
	/*recursiveFunc(2);

	cout << endl; 

	cout << recursiveFactorial(4) << endl;
	cout << recursiveFactorial(3) << endl;
	cout << recursiveFactorial(2) << endl;
	cout << recursiveFactorial(1) << endl;

	cout << endl;

	cout << recursiveFibonacci(10) << endl;
	cout << recursiveFibonacci(4) << endl;
	cout << recursiveFibonacci(3) << endl;
	cout << recursiveFibonacci(2) << endl;
	cout << recursiveFibonacci(1) << endl;
	cout << recursiveFibonacci(0) << endl;

	cout << endl;

	bool vec[] = { true, true, false, true, false, true, true };
	int count = numTrues(vec, 7, 0);
	cout << "There are " << count << " trues in vec[]" << endl;*/

	Node * a = new Node; a->value = 3;
	Node * b = new Node; b->value = 4;
	Node * c = new Node; c->value = 5;
	Node * d = new Node; d->value = 6;
	Node * e = new Node; e->value = 10;
	Node * f = new Node; f->value = 0;
	Node * g = new Node; g->value = 2;

	a->left = b;
	a->right = e;
	b->left = c;
	b->right = d;
	e->left = f;
	e->right = g;

	print_pre_order_tree(a);
	std::cout << std::endl;
	print_in_order_tree(a);
	std::cout << std::endl;
	print_post_order_tree(a);
	std::cout << std::endl;

	clear(a);
	

	system("pause");
	return 0;
}