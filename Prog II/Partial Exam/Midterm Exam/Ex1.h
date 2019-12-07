/* ----------------------------------------------------------------------- */
/*                            Angel Gonzalez T                             */
/* ----------------------------------------------------------------------- */

#ifndef EX1_H
#define EX1_H

// Uncomment to test the exercise
//#define TEST_EX1

/** Maximum number of items in the inventory. */
static const int MAX_ITEMS = 9;

/** Enumerated type for items. */
enum class Item {
	Food,
	Sword,
	Torch,
	Empty
};

// TO DO: Insert your code here

//Item clear(I)
//{
//	for (int i = 0; i < MAX_ITEMS; i++)
//	{
//		arr[i] = Item::Empty;
//	}
//}

class Inventory
{
private:
	Item * items[MAX_ITEMS];

public:
	Inventory() { clear(); } //Pasarle la funcion como parametro?

	void clear()
	{
		for (int i = 0; i <= MAX_ITEMS; i++)
		{
			 *items[i] = Item::Empty;
		}
	}

	void setItem(int index, Item item)
	{
		items[index] = &item;
	}

	Item itemAt(int index)
	{
		Item * item = items[index];
		
		return *item;
	}

	int itemCount(Item item)
	{
		int count = 0;
		Item * itemPtr = &item;

		for (int i = 0; i < MAX_ITEMS; i++)
		{
			//if ((itemPtr + i) = item) {}
		}

		return count;
	}

	bool operator==(const Inventory &inv)
	{
		/*for (int i = 0; i < MAX_ITEMS; i++)
		{
			if(items[i] = inv)
		}*/

		return true;
	}
};



#endif
