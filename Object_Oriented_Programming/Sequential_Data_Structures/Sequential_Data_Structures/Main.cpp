/*#define _CRTDBG_MAP_ALLOC //Memory leaks. + Dr.Memory.
#include <stdlib.h>
#include <crtdbg.h>*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "M_String.h"
#include "M_DynamicArray.h"

using namespace std;

int main()
{
	// Declaration
	String str1;
	String str2;

	// Copy ( operator= )
	str1 = "Cloud";
	str2 = "Barret";

	//cout << str1 << endl;
	//cout << str2 << endl;

	// Compare ( operator== )
	//bool equals = (str1 == str2);

	// Copy and concat ( operator+ )
	//String str3 = str1 + str2:
	//Show memory leaks on output window.
	_CrtDumpMemoryLeaks();

	system("pause");
	return 0;
}