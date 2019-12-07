#pragma once
#include <iostream>
#include <assert.h>

#define MAX_CHUNK_SIZE 10

using namespace std;

class Stack
{
public:
	// Ctor. and Dtor.
	~Stack() { delete[] _array; }

	// Modifiers
	void push(int value)
	{
		if (_top >= capacity)
		{
			increaseCapacity();
		}

		_top = (_top + 1);
		_array[_top] = value;
	}

	void pop()
	{
		assert(_top != -1 && "Stack is empty."); //If _top is -1 then an error message happens.

		_top--;
	}

	// Getters
	int top() const
	{
		return _array[_top];
	}

	bool empty() const
	{
		if (_top == -1)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	void print()
	{
		for (int i = 0; i < _top; i++)
		{
			cout << _array[i] << endl;
		}
	}

private:
	int _top; // Current top index (-1 if empty)
	int *_array = new int [MAX_CHUNK_SIZE]; // Dynamically allocated array
	int capacity = MAX_CHUNK_SIZE;

	void increaseCapacity()
	{
		capacity += MAX_CHUNK_SIZE;
		int * New_array = new int[capacity];

		for (int i = 0; i < _top + 1; i++)
		{
			New_array[i] = _array[i];
		}
		delete[] _array;
		_array = New_array;
	}
};
