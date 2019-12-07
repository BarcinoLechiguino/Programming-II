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

//class String 
//{
//public:
//	// Constructors and destructor
//	String();
//	String(const char *s);
//	String(const String &s);
//	~String();
//	// Methods
//	bool empty() const;
//	int size() const;
//	void clear();
//	const char *c_str() const;
//	// Operators
//	void operator=(const String &); // to assign
//	void operator+=(const String &); // to concat
//	bool operator==(const String &) const; // to compare
//	bool operator!=(const String &) const; // to compare
//private:
//	char *_str; // Pointer to the array of chars
//	int _size;//Size of the string
//}