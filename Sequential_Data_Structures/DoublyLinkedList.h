#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <cassert>

class DoublyLinkedList
{
public:

	~DoublyLinkedList()
	{
		clear();
	}

	void push_back(int value)
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

	void push_front(int value)
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

	void insert(unsigned int index, int value)
	{
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
			// Find element to erase
			Node *it = first;
			for (int i = 0; i < index; ++i)
			{
				it = it->next;
			}

			// Create a new node
			Node *new_node = new Node;
			new_node->value = value;
			new_node->prev = it->prev;
			new_node->next = it->next;

			it->prev->next = new_node;
			it->prev = new_node;
		}
	}

	void erase(unsigned int index)
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
		int value = 0;
		Node *next = nullptr;
		Node *prev = nullptr;
	};

	Node *first = nullptr;
	Node *last = nullptr;
	int num_elems = 0;
};

#endif // DOUBLY_LINKED_LIST_H