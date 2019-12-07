/*#define _CRTDBG_MAP_ALLOC //Memory leaks. + Dr.Memory.
#include <stdlib.h>
#include <crtdbg.h>*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "M_String.h"
#include "M_DynamicArray.h"
#include "QueueM.h"
#include "Stack.h"
#include "Linked_Lists.h"

using namespace std;

void test_queue()
{
	std::cout << "*** TEST_QUEUE ***" << std::endl;
	std::cout << std::endl;

	Queue<float> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	std::cout << "The queue should print: 1 2 3" << std::endl << "contents: ";
	q.print();
	std::cout << std::endl;
}

void test_doubly_linked_list()
{
	std::cout << "*** TEST_DOUBLY_LINKED_LIST ***" << std::endl;
	std::cout << std::endl;

	DoublyLinkedList<int> l;
	l.push_back(1);
	l.push_front(2);
	l.push_back(3);
	l.push_front(4);
	std::cout << "The list should print: 4 2 1 3" << std::endl << "contents: ";
	l.print();
	std::cout << std::endl;

	/*l.clear();
	std::cout << "The list should print nothing (it's empty)" << std::endl << "contents: ";
	l.print();
	std::cout << std::endl;

	for (int i = 0; i < 20; ++i) { l.push_back(i); }
	for (int i = 0; i < 20; ++i) { l.push_front(i); }
	for (int i = 0; i < 18; ++i) { l.pop_front(); }
	for (int i = 0; i < 17; ++i) { l.pop_back(); }
	std::cout << "The list should print 1 0 0 1 2" << std::endl << "contents: ";
	l.print();
	std::cout << std::endl;

	std::cout << "The list front should be 1" << std::endl << "front: ";
	std::cout << l.front() << std::endl;
	std::cout << std::endl;

	std::cout << "The list back should be 2" << std::endl << "back: ";
	std::cout << l.back() << std::endl;
	std::cout << std::endl;*/
}


int main()
{
	//String.h:	
	// Declaration
	String str1;
	String str2;

	// Copy ( operator= )
	str1 = "Cloud";
	str2 = "Barret";

	//cout << str1 << endl;
	//cout << str2 << endl;

	// Compare ( operator== )
	//bool equals = (str1 == str2);

	// Copy and concat ( operator+ )
	//String str3 = str1 + str2:

	//Show memory leaks on output window.
	_CrtDumpMemoryLeaks();

	//DynamicArray.h


	//Queue.h
	test_queue();

	//Stack.h
	Stack s;
	
	s.push(1);
	s.push(2);
	s.push(3);
	s.print();

	s.pop();
	s.print();

	//Linked_List.h
	test_doubly_linked_list();


	system("pause");
	return 0;
}