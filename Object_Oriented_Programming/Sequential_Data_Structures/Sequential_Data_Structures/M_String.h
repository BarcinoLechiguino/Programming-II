#pragma once
#include <string.h>

using namespace std;

class String
{
private:
	int size;
	char * string;

public:
	//Constructors and Destructors
	String() //Initializes size and string to 0;
	{
		size = 0;
		string = nullptr;
	};

	String(const char * str) //Initializes string as a copy of s and size to the size of s.
	{
		size = strlen(str);
		string = new char[size + 1];
		strcpy(string, str);
	}

	//Methods

};