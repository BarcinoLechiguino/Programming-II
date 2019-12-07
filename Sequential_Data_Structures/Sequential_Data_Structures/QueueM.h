#pragma once
/*class Queue
{
public:
	// Ctor. and Dtor.
	Queue();
	~Queue();
	// Modifiers
	void enqueue(int value);
	int dequeue();
	// Getters
	int size() const;
	bool empty() const;
private:
	int _front; // Index to the front (-1 if empty)
	int _back; // Index to the back (-1 if empty)
	int *_array; // Dynamically allocated array
};*/


/*if ((last + 1) > capacity) 
{
	last = (last + 1) % capacity; //Allocates the last element of the queue to the begining of the queue if the position exceeds capacity.
}*/

#ifndef QUEUE_H
#define QUEUE_H

#include <cassert>
#include <iostream>

#define QUEUE_CHUNK_SIZE 8

template <class T> //Template that allows us to reuse a class to change the type of data we are using.
class Queue
{
public:
	T *array = new T[QUEUE_CHUNK_SIZE];
	int index_front = -1;
	int index_back = -1;
	int num_elems = 0;
	int capacity = QUEUE_CHUNK_SIZE;

	~Queue()
	{
		delete[] array;
	}

	void enqueue(T value)
	{
		if (num_elems == capacity) {
			increaseCapacity();
		}

		if (num_elems == 0)
		{
			index_front = 0;
			index_back = 0;
		}
		else
		{
			index_back = (index_back + 1) % capacity;
		}

		array[index_back] = value;
		num_elems++;
	}

	void dequeue()
	{
		assert(num_elems > 0 && "The queue is empty");

		index_front = (index_front + 1) % capacity;
		num_elems--;

		if (num_elems == 0)
		{
			index_front = -1;
			index_back = -1;
		}
	}

	T front() const
	{
		assert(num_elems > 0 && "The queue is empty");

		return array[index_front];
	}

	T back() const
	{
		assert(num_elems > 0 && "The queue is empty");

		return array[index_back];
	}

	void clear()
	{
		delete[] array;
		array = nullptr;
		capacity = 0;
		num_elems = 0;
		index_front = -1;
		index_back = -1;
	}

	int size() const
	{
		return num_elems;
	}

	bool empty() const
	{
		return num_elems == 0;
	}

	void print() const
	{
		for (int i = 0; i < num_elems; ++i)
		{
			std::cout << array[(index_front + i) % capacity] << " ";
		}
		std::cout << std::endl;
	}

private:

	void increaseCapacity()
	{
		capacity = capacity + QUEUE_CHUNK_SIZE;
		T *new_array = new T[capacity];
		for (int i = 0; i < num_elems; ++i)
		{
			new_array[i] = array[(index_front + i)%num_elems];
		}
		delete[] array;
		array = new_array;
		index_front = 0;
		index_back = num_elems - 1;
	}
};

#endif // QUEUE_H