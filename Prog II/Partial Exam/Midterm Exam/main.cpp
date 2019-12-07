#include "SimpleUnitTest.h"
#include "Ex1.h"
#include "Ex2.h"
#include "Ex3.h"
#include <iostream>

void testExercises();

int main()
{
	/* -- Auto evaluation -- */
	testExercises();

	system("pause");
	return 0;
}


/* ----------------------------------------------------------------------- */
/*                     DO NOT TOUCH THE CODE BELOW                         */
/* ----------------------------------------------------------------------- */

void testExercises()
{
	// Ex1
#ifdef TEST_EX1
	{
		Inventory inv1;
		Inventory inv2;
		Inventory inv3;
		// Inventory is created cleared
		bool res1 =
			inv1.itemAt(0) == Item::Empty && inv1.itemAt(1) == Item::Empty && inv1.itemAt(2) == Item::Empty &&
			inv1.itemAt(3) == Item::Empty && inv1.itemAt(4) == Item::Empty && inv1.itemAt(5) == Item::Empty &&
			inv1.itemAt(6) == Item::Empty && inv1.itemAt(7) == Item::Empty && inv1.itemAt(8) == Item::Empty;
		// Set and get work
		inv1.setItem(5, Item::Sword);
		bool res2 =
			inv1.itemAt(0) == Item::Empty && inv1.itemAt(1) == Item::Empty && inv1.itemAt(2) == Item::Empty &&
			inv1.itemAt(3) == Item::Empty && inv1.itemAt(4) == Item::Empty && inv1.itemAt(5) == Item::Sword &&
			inv1.itemAt(6) == Item::Empty && inv1.itemAt(7) == Item::Empty && inv1.itemAt(8) == Item::Empty;
		// Clear works
		inv1.clear();
		bool res3 =
			inv1.itemAt(0) == Item::Empty && inv1.itemAt(1) == Item::Empty && inv1.itemAt(2) == Item::Empty &&
			inv1.itemAt(3) == Item::Empty && inv1.itemAt(4) == Item::Empty && inv1.itemAt(5) == Item::Empty &&
			inv1.itemAt(6) == Item::Empty && inv1.itemAt(7) == Item::Empty && inv1.itemAt(8) == Item::Empty;
		// Item count works
		inv1.setItem(0, Item::Food);
		inv1.setItem(1, Item::Torch);
		inv1.setItem(3, Item::Sword);
		inv1.setItem(4, Item::Sword);
		inv1.setItem(6, Item::Food);
		inv1.setItem(8, Item::Food);
		bool res4 =
			inv1.itemCount(Item::Food) == 3 &&
			inv1.itemCount(Item::Torch) == 1 &&
			inv1.itemCount(Item::Sword) == 2;
		// Equality operator works
		inv2.setItem(0, Item::Food);
		inv2.setItem(2, Item::Sword);
		inv2.setItem(3, Item::Torch);
		inv2.setItem(4, Item::Sword);
		inv2.setItem(5, Item::Food);
		inv2.setItem(7, Item::Food);
		inv3.setItem(0, Item::Food);
		inv3.setItem(2, Item::Sword);
		inv3.setItem(4, Item::Sword);
		inv3.setItem(5, Item::Food);
		inv3.setItem(7, Item::Food);
		bool res5 = inv1 == inv2 && !(inv1 == inv3);

		TEST(": Exercise 1: Inventory class", res1 && res2 && res3 && res4 && res5);
	}
#endif

#ifdef TEST_EX2
	// Ex2
    {
        int auxArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        bool res1 = partialSum(auxArray, 10, 0, 9) == 45;
        bool res2 = partialSum(auxArray, 10, 5, 9) == 35;
        bool res3 = partialSum(auxArray, 10, 1, 2) == 3;
        bool res4 = partialSum(auxArray, 10, 1, 1) == 1;
        bool res5 = partialSum(auxArray, 10, -1, 1) == 0;
        bool res6 = partialSum(auxArray, 10, 1, 0) == 0;
        bool res7 = partialSum(auxArray, 10, 1, 10) == 0;
		int auxArray2[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		bool res8 = partialSum(auxArray2, 15, 0, 14) == 15;
		bool res9 = partialSum(auxArray, 10, 12, 15) == 0;
		TEST(": Exercise 2: Partial sum(...)", res1 && res2 && res3 && res4 && res5 && res6 && res7 && res8 && res9);
    }
#endif

#ifdef TEST_EX3
	// Ex3
	{
		int arr1[] = { 1, 2, 3 };
		int arr2[] = { 4, 5, 6 };

		int arr3[] = { 0 };
		int arr4[] = { 1 };

		int arr5[] = { 11, 22, 33, 44, 55 };
		int arr6[] = { 1, 2, 3, 4, 5 };

		int arr7[] = { 4, 3, 2, 1 };
		int arr8[] = { 1, 2, 3, 4 };

		swapReverse(arr1, arr2, 3);
	
		bool res1 = arr1[0] == 6 && arr1[1] == 5 && arr1[2] == 4 &&
					arr2[0] == 3 && arr2[1] == 2 && arr2[2] == 1;
	
		swapReverse(arr3, arr4, 1);

		bool res2 = arr3[0] == 1 && arr4[0] == 0;

		swapReverse(arr5, arr6, 5);

		bool res3 = arr5[0] == 5 && arr5[1] == 4 && arr5[2] == 3 && arr5[3] == 2 && arr5[4] == 1 &&
					arr6[0] == 55 && arr6[1] == 44 && arr6[2] == 33 && arr6[3] == 22 && arr6[4] == 11;
	
		swapReverse(arr7, arr8, 4);

		bool res4 = arr7[0] == 4 && arr7[1] == 3 && arr7[2] == 2 && arr7[3] == 1 &&
					arr8[0] == 1 && arr8[1] == 2 && arr8[2] == 3 && arr8[3] == 4;

		TEST(": Exercise 3: swapReverse(...)", res1 && res2 && res3 && res4);
	}
#endif

	PRINT_TEST_REPORT();
}
