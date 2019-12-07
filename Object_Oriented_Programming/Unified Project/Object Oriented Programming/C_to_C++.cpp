#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//Initializing objects (keywords...)
enum class Color {red, green, blue}; //Declares an enumerating class with three elements.

//Namespaces
using namespace std; //Prioritizes std if an element of other group is named the same.
namespace foo { int a = 3; } //Declares a namespace named foo that contains a = 3.
namespace bar { int a = 5; } //Declares a namespace named bar that contains a = 5.
namespace baz { int a = 7; } //Declares a namespace named baz that contains a = 7.
using namespace baz; //If a is called and it is not specificed from which namespace it should be fetched, it will be fetched from baz.

//Bools
bool is_even(int n)
{
	if (n % 2 == 0)
	{
		cout << n << " is Even" << endl;
		return true;
	}
	
	else
	{
		cout << n << " is Odd" << endl;
		return false;
	}
}

void ExamplesI()
{
	//Initializing objects (keywords...)
	Color col = Color::red; //We initialize the class and then assign an element of the class to it. 

	const char * str = "C++";
	std::cout << "Hello " << str << std::endl;

	//Namespaces
	cout << foo::a << endl; //We declare a namespace and then we specify which element to fetch. "::" gives access to the elements of the namespace.
	cout << bar::a << endl;
	cout << a << endl; //As baz is set as default namespace a will fetch a = 7 from baz.

	//Allocating dynamic memory in C++
	int * num = new int; //Allocates dynamic memory for an int initialized to nullptr.
	int * nums = new int[4]; //Allocates dynamic memory for an array of 4 ints initialized to nullptr.
	int * num2 = new int(); //Allocates dynamic memory for an int initialized to 0;
	int * nums2 = new int[4](); //Allocates dynamic memory for an array of 4 ints initialized to 0;

	delete[] nums2; //Frees the dynamic memory space that nums2 was occupying.
	delete num2; //Frees the dynamic memory space that num2 was occupying.
	delete[]nums; //Frees the dynamic memory space that nums was occupying.
	delete num; //Frees the dynamic memory space that num was occupying.

	//Bools
	is_even(20);
}