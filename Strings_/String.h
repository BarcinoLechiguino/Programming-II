#pragma once
#include <string.h>

class String
{
private:
	char *_str;
	int  _size;

public:
	//Constructors and destructors
	String() {} //Initializes _str to nullptr and _size to 0.
	String(const char * s) //Initializes _str as a copy of s and _size to the length of s.
	{
		strcpy(_str, s);
		_size = strlen(_str);
	}

	String(const String &s) //Initializes _str as a copy of s._str and _size as a copy of s._size.
	{
		strcpy(_str, s._str);
		_size = strlen(s._size);
	}

	~String() {} //Destructor.

	//Methods
	bool empty() const { return _size == 0; } //Returns true of the string is empty (_size == 0) and false otherwise.

	int size() const { return _size; } //Returns the number of characters of the string (returns _size)
	void clear() { delete _str; _size = 0; } //Deletes _str and sets _size to 0.
	const char *c_str() const { return &_str; } //Returns the internal char pointer _str.

	
	//Operators
	void operator= (const String &s) { strcpy(_str, s); }  //To assign. //Copies the passed string into the internals of an object.
	void operator+= (const String &s) {} //To concatenate. //Concentrates the passed string into the internals of the object.
	void operator== (const String &s) const { return strcmp(_str, s) == 0; } //To compare. //Compares two strings, returns true of they are equal, and false otherwise.
	void operator!= (const String &s) const {} //To compare. //Compares two strings, returns true if they are different and false otherwise.
};