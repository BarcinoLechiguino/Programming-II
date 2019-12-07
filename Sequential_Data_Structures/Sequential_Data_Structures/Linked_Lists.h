#pragma once
#include <assert.h>

// Declaration of a doubly-linked list
/*class List {
private:
	// Internal struct for list nodes
	struct Node {
		int value;
		Node *next;
		Node *prev;
	};
	// List internals
	Node *first = nullptr;
	Node *last = nullptr;
	unsigned int num_elems = 0;

public:
	// Constructor and destructor
	List();
	~List();
	// Modifiers
	void push_front(const int &value);
	void push_back(const int &value);
	void pop_front();
	void pop_back();
	void insert(unsigned int position, const int &value);
	void erase(unsigned int position);
	void clear();
	// Getters
	int &front();
	int &back();
	int &value_at(unsigned int position);
	bool empty() const;
	unsigned int size() const;
};

void push_front(const int &value)
{
	if (num_elems == 0)
	{
		first = last = new Node;
		first->value = value;
		first->prev = nullptr;
		first->next = nullptr;
	}
	else
	{
		Node *node = new Node;
		node->value = value;
		node->prev = nullptr;
		node->next = first;
		first->prev = node;
		first = node;
	}
	num_elems++;
}*/
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <cassert>

//All template classes must be entirely defined in the header (.h file). Nothing must be defined in a .cpp file.

template <class T>
class DoublyLinkedList
{
public:

	~DoublyLinkedList()
	{
		clear();
	}

	void push_back(T value)
	{
		Node *node = new Node;
		node->value = value;
		node->prev = last;
		node->next = nullptr;

		if (last != nullptr)
		{
			last->next = node;
		}

		if (num_elems == 0)
		{
			first = node;
		}

		last = node;

		num_elems++;
	}

	void push_front(T value)
	{
		Node *node = new Node;
		node->value = value;
		node->prev = nullptr;
		node->next = first;

		if (first != nullptr)
		{
			first->prev = node;
		}

		if (num_elems == 0)
		{
			last = node;
		}

		first = node;

		num_elems++;
	}

	void pop_front()
	{
		assert(num_elems > 0 && "The list is empty");

		Node *to_delete = first;

		first = first->next;

		if (first != nullptr)
		{
			first->prev = nullptr;
		}
		else
		{
			last = nullptr;
		}

		delete to_delete;

		num_elems--;
	}

	void pop_back()
	{
		assert(num_elems > 0 && "The list is empty");

		Node *to_delete = last;

		last = last->prev;

		if (last != nullptr)
		{
			last->next = nullptr;
		}
		else
		{
			first = nullptr;
		}

		delete to_delete;

		num_elems--;
	}

	void insert(T index, T value)
	{
		assert(index < num_elems && "Index out of bounds");
		
		if (index == 0)
		{
			push_front(value);
		}
		else if (index == num_elems)
		{
			push_back(value);
		}
		else
		{
			// Find element
			Node *it = first;
			for (int i = 0; i < index; ++i)
			{
				it = it->next;
			}

			// Create a new node
			Node *new_node = new Node;
			new_node->value = value;
			new_node->prev = it->prev; //Changes prev de new_node a v1 (new_node prev = v1)
			new_node->next = it; //Changes next de new_node a v2 (new_node next = v2)

			it->prev->next = new_node; //Changes Next de v1 a new_node (v1 next = new_node)
			it->prev = new_node; //Changes Prev de v2 a new_node (v2 prev = new_node)
		}
	}

	void erase(T index)
	{
		assert(index < num_elems && "Index out of bounds");

		// Find element to erase
		Node *it = first;
		for (int i = 0; i < index; ++i)
		{
			it = it->next;
		}

		// Re-link the list / detach the it pointer
		if (it->prev != nullptr)
		{
			it->prev->next = it->next;
		}
		if (it->next != nullptr)
		{
			it->next->prev = it->prev;
		}

		// Update first and last pointers if needed
		if (first == it)
		{
			first = first->next;
		}
		if (last == it)
		{
			last = last->prev;
		}

		// Delete the detached node
		delete it;

		num_elems--;
	}

	int value_at(T index) const
	{
		assert(index < num_elems && "Index out of bounds");

		Node * it = first;

		for (int i = 0; i < index; i++)
		{
			it = it->next;
		}

		return it->value;
	}

	void clear()
	{
		Node *it = first;
		while (it != nullptr)
		{
			Node *it_next = it->next;
			delete it;
			it = it_next;
		}
		first = nullptr;
		last = nullptr;
		num_elems = 0;
	}

	int &front()
	{
		assert(num_elems > 0 && "The list is empty");

		return first->value;
	}

	int &back()
	{
		assert(num_elems > 0 && "The list is empty");

		return last->value;
	}

	bool empty() const { return num_elems == 0; }
	int size() const { return num_elems; }

	void print() const
	{
		Node *it = first;
		while (it != nullptr)
		{
			std::cout << it->value << " ";
			it = it->next;
		}
		std::cout << std::endl;
	}

private:

	struct Node
	{
		T value = 0;
		Node *next = nullptr;
		Node *prev = nullptr;
	};

	Node *first = nullptr;
	Node *last = nullptr;
	int num_elems = 0;
};

#endif // DOUBLY_LINKED_LIST_H


