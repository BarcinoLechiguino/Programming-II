/* ----------------------------------------------------------------------- */
/*                            ANGEL GONZALEZ T.                            */
/* ----------------------------------------------------------------------- */

#ifndef PRIORITY_QUEUE_H  
#define PRIORITY_QUEUE_H

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <assert.h>

class Ranking
{
public:

	Ranking() :
		first(nullptr),
		num_elems(0)
	{ }

	~Ranking()
	{
		clear();
	}

	int size() const
	{
		return num_elems;
	}

	bool empty() const
	{
		return num_elems == 0;
	}

	const char *head()
	{
		assert(num_elems > 0 && "The ranking is empty");
		return first->name;
	}

	const char *head() const
	{
		assert(num_elems > 0 && "The ranking is empty");
		return first->name;
	}

	void push_front(const char *name)
	{
		Node *new_node = new Node;
		new_node->name = name;
		new_node->prev = nullptr;
		new_node->next = first;
		if (first != nullptr) {
			first->prev = new_node;
		}
		first = new_node;
		num_elems++;
	}

	void clear()
	{
		Node *it = first;
		while (it != nullptr) {
			Node *to_delete = it;
			it = it->next;
			delete to_delete;
		}
	}

	int find_player_position(const char *name)
	{
		// TODO: Insert your code here
		Node * it = first;

		if (it != nullptr)
		{
			for (int i = 0; i < num_elems; i++)
			{
				if (strcmp(name, it->name) == 0)
				{
					return i;
				}

				else
				{
					it = it->next;
				}
			}
		}
		//delete it;
		return -1;
	}

	void advance(int position)
	{
		// TODO: Insert your code here

		Node * it = first;

		assert(position < num_elems && "position out of bounds");

		if (position == 0)
		{
			return;
		}

		for (int i = 0; i < position; i++)
		{
			it = it->next;
		}

		if (it->prev != nullptr)
		{
			it->prev->next = it->next;

			if (it->prev->prev != nullptr)
			{
				it->prev->prev = it;
				it->prev = it->prev->prev;
				it->next = it->prev->prev->next;
				it->prev->prev->next = it->prev->next;
			}
		}

		if (it->next != nullptr)
		{
			it->next->prev = it->prev;
			//it->next = 
		}

		//it->prev = it->next;
	}

private:

	struct Node
	{
		const char *name = nullptr;
		Node *next = nullptr;
		Node *prev = nullptr;
	};

	Node *first;
	int num_elems;
};

#endif // PRIORITY_QUEUE_H


